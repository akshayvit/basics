#include <stdio.h>

int main()
{
    //-printf("Hello World!\n");
    int num=9;
    int cnt=0;
    while(num){
        num &=(num-1);
        cnt++;
    }
   printf("%d",cnt);
    return 0;
}
