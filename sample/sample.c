#define MIN(a,c) ((a) > (c) ? (c) : (a))
#include<stdio.h>

#if 10 > 20
     printf("sdfsd");
#else
    printf("sdfsd hey");
#endif

void main()
{
    #if 10 < 20
        printf("werftwrf");
    #else
        printf("hfghfg");
    #endif
    printf("%d", sizeof("bmw")); 
}
