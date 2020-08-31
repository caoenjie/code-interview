/* 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replaceSpace(char *s)
{
    int len = strlen(s);
    char *p = (char *)malloc(len*3 + 1);
    char *p1 = p;
    while(*s != '\0')
    {
        if(*s == ' ')
        {
            *(p++) = '%';
            *(p++) = '2';
            *(p++) = '0';
            s++;
        }
        else
        {
            *p = *s;
            s++;
            p++;
        }
    }
    *p = '\0';
    return p1;
}

int main()
{
    printf("%s\n", replaceSpace("     "));
    return 0;
}