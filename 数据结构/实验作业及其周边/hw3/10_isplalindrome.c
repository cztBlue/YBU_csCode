#include <stdio.h>
// 习题3,实习1

int isplaindrome(char *s)
{
    int len, i;
    for (i = 0;; i++)
    {
        if (s[i] == '&')
        {
            len = 2 * i + 1;
            break;
        }
    }
    //由长度剪枝
    if (s[len] != '@') return 0;

    for (i = i + 1; i < len; i++)
    {
        if (s[i] != s[len - i - 1])
            return 0;
    }

    return 1;
}

int main()
{
    printf("习题3,实习1\n");
    char s[50] = "a+bc&cb+a@";
    char s2[50] = "a+bc&ca@";
    // test
    printf("%s ", s);
    if (isplaindrome(s))
        printf("是回文字符串\n");
    else
        printf("不是回文字符串\n");
    printf("%s ", s2);
    if (isplaindrome(s2))
        printf("是回文字符串\n");
    else
        printf("不是回文字符串\n");

    return 0;
}