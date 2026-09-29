#include <stdio.h>
#include <string.h>

int main() {
    char str[1005];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    int freq[256] = {0};
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] != '\n' && str[i] != '\r') {
            freq[(unsigned char)str[i]]++;
        }
    }

    int max_freq = 0;
    char best_char = 0;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            best_char = (char)i;
        }
    }

    printf("%c %d\n", best_char, max_freq);
    return 0;
}

