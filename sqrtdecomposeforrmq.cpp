#include <iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int* rmq(int* arr,int n);
int minm(int* arr,int l,int min);
int main()
{
    int n;
    std::cin>>n;
    int* arr;
    for(int i=0;i<n;i+=1)
    {
        std::cin>>*(arr+i);
    }
    int* tm;
    tm=new int[n];
    tm=rmq(arr,n);
    int size=sizeof(tm)/sizeof(tm[0]);
    std::cout<<size;
    for(int i=0;i<size;i+=1)
    {
        std::cout<<tm[i];
    }
    delete[] tm;
}
int minm(int* arr,int l,int r,int min){
    int n=sizeof(arr)/sizeof(arr[0]);
    if(l>r)
    {
        return 0;
    }
    if(arr[l]>min)
    {
        min=arr[l];
    }
    minm(arr,l+1,r,min);
    return min;
}
int* rmq(int* arr,int n){
    int ind=sqrt(n);
    int* temp=new int[ind];
    for(int i=0;i<ind;i+=1)
    {
        temp[i]=minm(arr,i+1,i+ind,arr[i]);
    }
    return temp;
}