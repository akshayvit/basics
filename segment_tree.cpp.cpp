#include <iostream>
#include<stdlib.h>
using namespace std;
void segment(int* arr,int l,int r,int node,int* temp);
int main()
{
    int n;
    int* arr;
    std::cin>>n;
    arr=(int*)malloc(sizeof(int)*n);
    int* temp;
    arr=(int*)calloc(n,sizeof(int));
    std::cout<<"here:";
    for(int i=0;i<n;i+=1)
    {
        std::cin>>*(arr+i);
    }
    int len=sizeof(arr)/sizeof(arr[0]);
    segment(arr,0,len-1,len-1,temp);
    for(int i=0;i<n;i+=1)
    {
        std::cout<<temp[i];
    }
}
void segment(int* arr,int l,int r,int node,int* temp){
    if(l==r)
    {
        temp[node]=arr[l];
    }
    int mid=(l+r)/2;
    //temp[node]=temp[2*node]+temp[2*node+1];
    segment(arr,l,mid,2*node,temp);
    segment(arr,mid,r,2*node+1,temp);
    temp[node]=temp[2*node]+temp[2*node+1];
}