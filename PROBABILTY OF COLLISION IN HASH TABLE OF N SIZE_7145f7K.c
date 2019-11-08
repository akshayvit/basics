#include <stdio.h>
#include<math.h>
int power(int n,int k);
int main()
{
    //printf("Hello World!\n");
    int n,m;
    scanf("%d%d",&n,&m);
    double p=1-(exp(-(power(n,2))/(2*m)));
    printf("%f",p);
    return 0;
}
int power(int n,int k){
    if(k==0){
        return 1;
    }
    return n*power(n,k-1);
}