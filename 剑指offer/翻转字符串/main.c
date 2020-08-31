#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverseLeftWords_test1(char *s, int n)
{
    int len = strlen(s);
    char *s1 = (char *)malloc(len + 1);
    strcpy(s1, s + n);
    strncat(s1, s, n);
    return s1;
}

char *reverseLeftWords_test2(char *s, int n)
{
    int len = strlen(s), i = 0;
    char *ans = malloc(sizeof(char) * (len + 1));
    while (i < len)
    {
        *(ans++) = s[(n + i++) % len];
    }
    *ans = '\0';
    return ans - len;
}

//double pointer
char *reverseLeftWords_test3(char *s, int n)
{
    char *arry;
    int sum, m1, m, i = 0, j;
    sum = strlen(s);
    j = sum - 1;
    arry = malloc(sizeof(char) * (sum + 1));
    arry[sum] = '\0';
    m = n - 1; //向前的指针；
    m1 = n;    //向后的指针;
    while (m1 < sum || 0 <= m)
    {
        if (0 <= m)
        {
            arry[j] = s[m];
            j--;
            m--;
        }
        if (m1 < sum)
        {
            arry[i] = s[m1];
            i++;
            m1++;
        }
    }
    return arry;
}

//strncpy
char *reverseLeftWords_test4(char *s, int n)
{
    int sum, n1;
    char *arry;
    sum = strlen(s);
    n1 = sum - n;
    arry = malloc(sizeof(char) * (sum + 1));
    arry[sum] = '\0';              //添加末尾;
    strncpy(arry, s + n, sum - n); //将 n 之后的copy 进入 字符串；
    strncpy(arry + n1, s, n);      // copy 之前的；
    return arry;
}

int main()
{
    char s[8] = "abcdefg";
    int k = 2;
    char *(*test[])(char *, int) =
    {
        reverseLeftWords_test1,
        reverseLeftWords_test2,
        reverseLeftWords_test3,
        reverseLeftWords_test4
    };

    printf("%s\n", test[0](s, k));
    printf("%s\n", test[1](s, k));
    printf("%s\n", test[2](s, k));
    printf("%s\n", test[3](s, k));

    return 0;
}