#include <stdio.h>
#include <string.h>
#define MAXPLA 128
#define MAXSTRLEN 1000
#define TRUE 1
#define FALSE 0
// P125-实习题-4_最长平台

typedef struct platform
{
    int pos;
    int len;
} CharPlatform;
CharPlatform maxcharplares[1000];

// 返回平台个数
int GetCharPlatform(char *s)
{
    int len = strlen(s);
    CharPlatform pla[MAXPLA];
    CharPlatform maxpla = {0, 0};
    int rescount = 0;

    // 初始化
    for (int i = 0; i < MAXPLA; i++)
        pla[i] = maxpla;

    // 上一格字符
    int charres = s[0];
    // 连续跟踪标记
    int trackflag = FALSE;
    int curlen = 0, curpos = 0;
    for (int i = 1; i < len; i++)
    {
        if (s[i] == charres && trackflag == FALSE)
        {
            trackflag = TRUE;
            curlen = 1;
            curpos = i - 1;
        }

        if (s[i] != charres && trackflag == TRUE)
            trackflag = FALSE;

        if (trackflag == TRUE)
            curlen += 1;

        if (trackflag == TRUE && curlen > pla[(int)s[i]].len)
        {
            pla[(int)s[i]].len = curlen;
            pla[(int)s[i]].pos = curpos;
        }
        charres = s[i];
    }

    for (int i = 0; i < MAXPLA; i++)
        if (pla[i].len > maxpla.len)
            maxpla = pla[i];

    for (int i = 0; i < MAXPLA; i++)
    {
        if (pla[i].len == maxpla.len)
        {
            maxcharplares[rescount] = pla[i];
            rescount++;
        }
    }

    return rescount;
}

int main()
{
    printf("P125-实习题-4_最长平台:\n\n");
    // test
    char s[] = "aabbcdfdd";
    int rescount = GetCharPlatform(s);
    printf("母串：%s\n", s);
    for (int i = 0; i < rescount; i++)
    {
        char plastring[MAXSTRLEN];
        CharPlatform res = maxcharplares[i];
        strncpy(plastring, s + res.pos, res.len);
        printf("%d,%d:%s\n", res.pos, res.len, plastring);
    }

    return 0;
}