#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int kthmedian(int arr[],size_t n);
void push(int* stack,int n ,int tot);
int t=-1;
int main()
{
    //cout << "Hello World!" << endl;
    int arr[]={1, 3, 2, 4, 5, 6, 8, 7};
    //std::cout<<arr[1];
    std::cout<<kthmedian(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}
int kthmedian(int arr[],size_t n){
    int* len=(int*)n;
    int m=rand()*(log(*len));
    int* st=new int[m];
    memset(st,0,m);
    int k=0;
    while(k<m){
        push(st,arr[rand()%(0-*len+2)],m);
        k++;
    }
    sort(st,st+m);
    int mid=(0+sizeof(st)/sizeof(st[0]))/2;
    int a=st[mid];
    //delete[] st;
    return a;
}
void push(int* stack,int n ,int tot){
    if(t<tot-1){
        t+=1;
        stack[t]=n;
    }
}