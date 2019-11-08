#include <stdio.h>
int printsol(int n){
    int t=0;
    while(n%2==0){
        t++;
        n/=2;
    }
    int p=t+1;
    for(int  i=3;i<sqrt(n);i+=2){
        int k=0;
        while(n%i==0){
            k++;
            n/=i;
        }
        p*=k+1;
    }
    return p;
}
int main()
{
   // printf("Hello World!\n");
   int n;
   scanf("%d",&n);
   printsol(n);
    return 0;
}
