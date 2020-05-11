#include <stdio.h>
#include "cub3d.h"
#include <fcntl.h>
int aa(char *a)
{
    int i = 0;

    while (a[i])
    {
        printf("%d\n",i);
        if (a[i++]!='1')
            return (1);
    }
    return (0);
}
int main(int argc, char **argv)
{
    char a[10] = "111110111";
    int l = aa(a);
    printf("return = %d\n",l);
}