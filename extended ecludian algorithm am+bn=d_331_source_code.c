#include <stdio.h>
int main() {
	//printf("Hello World!");
	int m,n,a,b;
	scanf("%d%d%d%d",&m,&n,&a,&b);
	int d=gcd(m,n);
	printf("%d\n%d",check(m,n,a,b,d),a);
	return 0;
}
int gcd(int m,int n){
    int r=m%n;
    if(r==0){
        return n;
    }
    return gcd(m,r);
}
int check(int m,int n,int a,int b,int d){
    int a1=b;
    int b1=0;
    a=b1;
    a1=1;
    int c=m;
    d=n;
    int q=c/d;
    int r=c%d;
    if(r==0){
        return 1;
    }
    c=d;
    d=r;
    int t=a1;
    a1=a;
    a=t-q*a;
    t=b1;
    b1=b;
    b=t-q*b;
    return check(c,d,a,b,d);
}