#include <stdio.h>

int max(int a,int b)
{
    return a>b ? a:b;
}


int unboundedKnapsack(int tw,int w[],int v[],int n)
{
    int dp[tw+1];
    memset(dp,0,(tw+1)*sizeof(int));
    for(int i=0;i<=tw;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=w[j])
            {
                dp[i]=max(dp[i],dp[i-w[j]]+v[j]);
            }
        }
    }
    return dp[tw];
}

int main() 
{ 
    int W = 100; 
    int val[] = {10, 30, 20}; 
    int wt[] = {5, 10, 15}; 
    int n = sizeof(val)/sizeof(val[0]); 
  
    printf("%d",unboundedKnapsack(W,  wt, val,n)); 
  
    return 0; 
} 