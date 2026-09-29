#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CMDS 5
#define TOKENS 4
#define MAXWORDS 50

int cl[CMDS] = {0};
char *lists[CMDS][MAXWORDS];
char *tokens[TOKENS]={"[N]","[AV]","[V]","[AJ]"};
char *cmds[CMDS]={"NOUNS","ADVERBS","VERBS","ADJECTIVES","END"};

int main()
{
    char sentence[500], line[200];
    int cur = -1, used[CMDS] = {0};
    fgets(sentence, sizeof sentence, stdin);
    sentence[strcspn(sentence, "\r\n")] = 0;

    while (fgets(line, sizeof line, stdin)) {
        line[strcspn(line, "\r\n")] = 0;
        if (!line[0]) continue;
        int k, isCmd = 0;
        for (k = 0; k < CMDS; k++)
            if (strcmp(line, cmds[k]) == 0) { isCmd = 1; break; }
        if (isCmd) { if (k == 4) break; cur = k; }
        else if (cur >= 0 && cl[cur] < MAXWORDS) lists[cur][cl[cur]++] = strdup(line);
    }

    for (int round = 0; round < 2; round++) {
        char copy[500];
        strcpy(copy, sentence);
        char *w = strtok(copy, " ");
        int first = 1;
        while (w) {
            if (!first) printf(" ");
            first = 0;
            int done = 0;
            for (int k = 0; k < TOKENS && !done; k++) {
                size_t len = strlen(tokens[k]);
                if (strncmp(w, tokens[k], len) == 0 && used[k] < cl[k]) {
                    printf("%s%s", lists[k][used[k]++], w + len);
                    done = 1;
                }
            }
            if (!done) printf("%s", w);
            w = strtok(NULL, " ");
        }
        printf("\n");
    }
    return 0;
}
