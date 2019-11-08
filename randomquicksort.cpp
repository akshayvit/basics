#include <iostream>
using namespace std;
void quicksort(int *arr,int low,int high);
bool iscenpiv(int* arr,int low,int high,int rd);
bool issorted(int *arr);
int smaller(int* arr,int m);
int larger(int* arr,int m);
int main()
{
    int n;
    int* arr;
    arr=(int*)malloc(sizeof(n)*n);
    std::cin>>n;
    int i;
    int len=sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<len;i+=1)
    {
        std::cin>>*(arr+i);
    }
    quicksort(arr,0,len-1);
    for(i=0;i<len;i+=1)
    {
        std::cout<<arr[i];
    }
}
bool iscenpiv(int* arr,int low,int high,int rd)
{
    bool b=0;
    int sc=0,gc=0;
    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i+=1)
    {
        if(arr[i]<rd)
        {
            sc+=1;
        }
        else
        {
            gc+=1;
        }
    }
    int n=high-low+1;
    if(sc>=n/4 && gc>=n/4)
    {
        b=1;
    }
    return b;
}
bool issorted(int* arr)
{
    bool b=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i+=1)
    {
        if(arr[i]<arr[i+1])
        {
            b=1;
        }
    }
    return b;
}
void quicksort(int* arr,int low,int high)
{
    int random=(low+high)/2;
    if(issorted(arr))
    {
        return;
    }
    while(!iscenpiv(arr,low,high,random) && high!=low)
    {
        random=(random+high)/2;
    }
    int sc=smaller(arr,random);
    int gc=larger(arr,random);
    quicksort(arr,low,sc-1);
    quicksort(arr, high-gc+1, high);
}
int smaller(int* arr,int m)
{
    int sc=0;
    int len=sizeof(arr)/sizeof(arr[0]);
     for(int i=0;i<len;i+=1)
    {
        if(arr[i]<m)
        {
            sc+=1;
        }
    }
    return sc;
}
int larger(int* arr,int m)
{
    int gc=0;int len=sizeof(arr)/sizeof(arr[0]);
     for(int i=0;i<len;i+=1)
    {
        if(arr[i]>m)
        {
            gc+=1;
        }
    }
    return gc;
}