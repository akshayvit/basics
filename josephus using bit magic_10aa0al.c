#include <stdio.h>

int main()
{
    //printf("Hello World!\n");
    int n;
    scanf("%d",&n);
    int p=(int)log2(n);
    int p2=pow(2,p);
    int diff=n-p2;
    if(diff)
    {
        int a=((2*diff)+1);
        printf("%d",a);
    }
    else{
        printf("1");
    }
    return 0;
}