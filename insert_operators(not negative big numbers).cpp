#include <bits/stdc++.h>
using namespace std;

string res;

bool recur(int arr[],int sum,char oper[],int n,int i)
{
    if(i>n-1)
    {
        if(sum==0)
        {
            return true;
        }
        return false;
    }
    oper[i-1]='+';
    if(recur(arr,sum-arr[i],oper,n,i+1))
    {
        return true;
    }
    oper[i-1]='-';
    if(recur(arr,sum+arr[i],oper,n,i+1))
    {
        return true;
    }
    return false;
}

int main() {
	int n,s;
	std::cin>>n>>s;
	int arr[n];
	for(int i=n-1;i>=0;i--)
	   arr[i]=i+1;
	char oper[n-1];
	bool a;
	long long int sum=(n*(n+1)/2)-s;
	if(sum&1)
	{
	    printf("Impossible");
	    return 0;
	}
	if(n<=10)
	{
	a=recur(arr,s-1,oper,n,1);
	if(!a)
	{
	    printf("Impossible");
	}
	else
	{
	    printf("1");
	    for(int i=0;i<n-1;i++)
	    {
	        printf("%c%d",oper[i],arr[i+1]);
	    }
	    
	}
	}
	else
	{
	    int oper1[n-1]={0};
	    long long int s2=sum/2;
	    int i=n+1;
	    while((--i)>1 && s2)
	    {
	        if(s2-i>1)
	        {
	            s2-=i;
	            oper1[i-2]=1;
	        }
	        else if(s2-i==0)
	        {
	            s2-=i;
	            oper1[i-2]=1;
	            break;
	        }
	    }
	    if(s2){
	        printf("Impossible");
	    }
	    else
	    {
	        printf("1");
	        for(int k=1;k<=n-1;k++)
	        {
	            oper1[k-1] ? printf("-") : printf("+");
	            printf("%d",arr[k]);
	        }
	    }
	}
	printf("\n");
	return 0;
}