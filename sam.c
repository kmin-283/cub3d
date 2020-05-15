#include<stdlib.h>
#include <stdio.h>
int main()
{
    char **aa = calloc(3,sizeof(char *));
    aa[0] = calloc(4,sizeof(char));
    aa[1] = calloc(4,sizeof(char));
    aa[2] = calloc(4,sizeof(char));
    aa[0] = "aaa";
    aa[1] = "bbb";
    aa[2] = "ccc";

    /* aa[1][2] = 'k'; */
    printf("%s\n",aa[1]);

}