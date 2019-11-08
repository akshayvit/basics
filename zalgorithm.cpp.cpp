#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int zalgo(char* pat,char* text);
int findchar(char* s,int l,int r,int len);
int getmax(int* a);
int bin_search(int *arr,int n,int len);
int* sorted(int* a);
int main()
{
    int lp,lt;
    char* pat;char* text;
    std::cin>>lp>>lt;
    pat=(char*)malloc(sizeof(char)*lp);
    text=(char*)malloc(sizeof(char)*lt);
    std::cin>>pat>>text;
    fflush(stdin);
    std::cout<<zalgo(pat,text);
    return 1;
}
int bin_search(int* arr,int n,int len)
{
    int mid=(0+len)/2;
    if(arr[mid]==n)
    {
        return mid;
    }
    else if(n<arr[mid])
    {
        int* left;
        left=(int*)malloc(sizeof(int)*mid);
        for(int i=0;i<mid;i+=1)
        {
            left[i]=arr[i];
        }
        return bin_search(left,n,mid);
        delete[] left;
    }
    else
    {
        int* right;
        right=(int*)malloc(sizeof(int)*mid);
        for(int i=mid;i<len;i+=1)
        {
            right[i]=arr[i];
        }
        return bin_search(right,n,mid)+mid;
        delete[] right;
    }
}
int* sorted(int* a)
{
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i+=1)
    {
        int temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
    }
    return a;
}
int getmax(int* a)
{
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i+=1)
    {
        int temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
    }
    return a[len-1];
}

int zalgo(char* pat,char* text)
{
    int* c;
    int len1=strlen(pat);
    char* pg="$";
    char* s1=strcat(pat,pg);
    char* s=strcat(s1,text);
    int len=strlen(s);
    memset(c,-1,len);
    int n=sizeof(c)/sizeof(c[0]);
    c[0]=0;
    for(int i=1;i<n;i+=1)
    {
        c[i]=findchar(s,0,i,len);
    }
    int g=getmax(c);
    c=sorted(c);
    int ind=bin_search(c,g,n);
    return ind-(len1+1);
}
int findchar(char* s,int l,int r,int len)
{
    if(r>len-1)
    {
        return 0;
    }
    if(l==r)
    {
        return 0;
    }
    int tot=0;
    while(s[l]==s[r] && l!=r)
    {
        tot+=1;
        l+=1;
        r+=1;
    }
    return tot;
}