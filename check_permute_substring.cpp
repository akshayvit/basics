#include <bits/stdc++.h>
#define max 256
using namespace std;


bool compare(int cp[],int cq[])
{
    for(int j=0;j<max;j++)
    {
        if(cp[j]!=cq[j])
        {
            return false;
        }
    }
    return true;
}

main()
{
    int _;
    cin>>_;
    while(_--)
    {
    	int cp[max]={0},cq[max]={0};
        string a,b;
        cin>>a;
        cin>>b;
        bool flag=false;
        int m=a.length();
        int n=b.length();
        for(int i=0;i<=m-1;i++)
        {
            cp[a[i]-'0']++;
            cq[b[i]-'0']++;
        }
        if(compare(cp,cq))
        {
        	printf("YES\n");
        	continue;
		}
        for(int i=m;i<=n-1;i++)
        {
            if(compare(cp,cq))
            {
                flag=true;
                break;
            }
            cq[b[i]-'0']++;
            cq[b[i-m]-'0']--;
        }
        if(flag || compare(cp,cq))
          printf("YES\n");
        else
          printf("NO\n");
    }
}
