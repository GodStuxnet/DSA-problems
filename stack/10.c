#include <stdio.h>
#include <string.h>
#include <ctype.h>

char st[100][50];
int top = -1;

void push(char s[])
{
    top++;
    strcpy(st[top], s);
}

char* pop()
{
    return st[top--];
}

int main()
{
    char post_exp[1000];
    scanf("%s", post_exp);

    int len = strlen(post_exp);
    int i;

    for(i=0;i<len;i++)
    {
        char c = post_exp[i];

        if(isalpha(c) || isdigit(c))
        {
            char s[2];
            s[0] = c;
            s[1] = '\0';
            push(s);
        }
        else
        {
            char op1[50], op2[50], temp[50];
            strcpy(op1, pop());
            strcpy(op2, pop());

            temp[0] = c;
            temp[1] = '\0';
            strcat(temp, op2);
            strcat(temp, op1);

            push(temp);
        }
    }

    printf("%s\n", st[top]);
    return 0;
}