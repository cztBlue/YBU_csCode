#include <stdio.h>
#include <string.h>
// P125-12 BF匹配和KMP匹配

// 参数：主串，子串，
int BF(char *l, char *s)
{
    if (strlen(l) < strlen(s)) // 剪去子串长于母串的非法比较
        return 0;

    if (!strcmp(l, s))
        return 1;
    int ll = strlen(l), sl = strlen(s), di = ll - sl;
    for (int i = 0; i <= di; i++)
    {
        int flag = 0;
        for (int j = 0; j < sl; j++)
        {
            if (l[i + j] == s[j])
                continue;
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            continue;
        else if (flag == 0)
            return i + 1;
    }
    //printf("子串不存在");
    return 0;
}

void Next(char *T, int *next)
{

    int i = 1;
    next[1] = 0;
    int j = 0;
    while (i < strlen(T))
    {
        if (j == 0 || T[i - 1] == T[j - 1])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int KMP(char *S, char *T)
{
    if (strlen(S) < strlen(T)) // 剪去非法比较
        return 0;

    int next[10];
    Next(T, next);
    int i = 1;
    int j = 1;
    while (i <= strlen(S) && j <= strlen(T))
    {
        if (j == 0 || S[i - 1] == T[j - 1])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > strlen(T))
    {
        return i - (int)strlen(T);
    }
    return 0;
}

int main(void)
{
    int pos;
    char s1[201] = "aaabbbababaabb";
    char s2[201] = "aaab";
    printf("P125-12 BF匹配和KMP匹配:\n\n");
    printf("母串：%s\n", s1);
    printf("子串：%s\n", s2);
    
    // test for BF
    pos = BF(s1, s2);
    if (pos != 0)
    {
        printf("BF:s1是s2的子串 ");
        printf("下标从1开始,在第%d位匹配\n", pos);
    }
    else
    {
        printf("无法匹配\n");
    }

    // test for kmp
    pos = KMP(s1, s2);
    if (pos != 0)
    {
        printf("KMP:s1是s2的子串 ");
        printf("下标从1开始,在第%d位匹配\n", pos);
    }
    else
    {
        printf("无法匹配\n");
    }

    return 0;
}
