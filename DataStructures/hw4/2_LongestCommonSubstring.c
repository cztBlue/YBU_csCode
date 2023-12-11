#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAXSTRLEN 1000
//P125-13_最长子串

typedef struct substrinfo
{
    int pos;
    int len;
} SubStrInfo;

// 最长子串
char dest[1000];
int dp[MAXSTRLEN][MAXSTRLEN];

char *MaxCommonSubstring(char *str1, char *str2)
{
    int lena = strlen(str1), lenb = strlen(str2);
    // 最长匹配的长度,最长匹配对应在s1中的最后一位
    int mmax = 0, p = 0;
    // 经典的dp题
    for (int i = 0; i < lena; i++)
    {
        for (int j = 0; j < lenb; j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                if (dp[i + 1][j + 1] > mmax)
                {
                    mmax = dp[i + 1][j + 1];
                    p = i + 1;
                }
            }
        }
    }

    strncpy(dest, str1 + p - mmax, mmax);
    return dest;
}

int main()
{
    char str1[] = "abddabc";
    char str2[] = "ckadbc";
    printf("P125-13_最长子串:\n\n");

    printf("母串1：%s\n",str1);
    printf("母串2：%s\n",str2);
    printf("最长子串：%s", MaxCommonSubstring(str1, str2));
    return 0;
}