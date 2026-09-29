#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXP 100
#define BUFLEN 105

char *gems[] =
{
    "Lapis",
    "Topaz",
    "Tourmaline",
    "Sapphire",
    "Peridot",
    "Ruby",
    "Pearl",
    "Emerald",
    "Diamond",
    "Aquamarine",
    "Amethyst",
    "Garnet"
};

int gemCount = 12;

int compareIgnoreCase(const char *a, const char *b)
{
    while (*a && *b)
    {
        char x = tolower((unsigned char)*a);
        char y = tolower((unsigned char)*b);

        if (x != y)
            return x - y;

        a++;
        b++;
    }

    return tolower((unsigned char)*a) -
           tolower((unsigned char)*b);
}

int getRank(const char *name)
{
    char lowerName[BUFLEN];

    int i;

    for (i = 0; name[i] != '\0'; i++)
        lowerName[i] = tolower((unsigned char)name[i]);

    lowerName[i] = '\0';

    int bestRank = gemCount;

    for (i = 0; i < gemCount; i++)
    {
        char lowerGem[30];

        int j;

        for (j = 0; gems[i][j] != '\0'; j++)
            lowerGem[j] = tolower((unsigned char)gems[i][j]);

        lowerGem[j] = '\0';

        if (strstr(lowerName, lowerGem) != NULL)
        {
            if (i < bestRank)
                bestRank = i;
        }
    }

    return bestRank;
}

int compareNames(const void *a, const void *b)
{
    const char *name1 = (const char *)a;
    const char *name2 = (const char *)b;

    int rank1 = getRank(name1);
    int rank2 = getRank(name2);

    if (rank1 != rank2)
        return rank1 - rank2;

    return compareIgnoreCase(name1, name2);
}

int main()
{
    char ponies[MAXP][BUFLEN];
    int count = 0;

    while (count < MAXP)
    {
        fgets(ponies[count], BUFLEN, stdin);

        ponies[count][strcspn(ponies[count], "\n")] = '\0';

        if (strcmp(ponies[count], "END") == 0)
            break;

        count++;
    }

    qsort(ponies, count, BUFLEN, compareNames);

    for (int i = 0; i < count; i++)
        printf("%s\n", ponies[i]);

    return 0;
}
