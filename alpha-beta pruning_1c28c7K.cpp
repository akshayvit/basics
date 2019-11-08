#include <iostream>
#define inf 1000000
using namespace std;
void prune(int arr[],int node,int l,int r,int & alpha,int & beta,bool ismax);
int min(int a,int b);
int max(int a,int b);
int main()
{
    //cout << "Hello World!" << endl;
    int values[8] = { 3, 5, 6, 9, 1, 2, 0, -1 };
    int alpha=-inf;
    int beta=+inf;
    prune(values,0,0,7,alpha,beta,true);
    std::cout<<alpha<<" "<<beta;
    return 0;
}
void prune(int arr[],int node,int l,int r,int & alpha,int & beta,bool ismax){
    if(l==r){
        if(arr[l]>=beta){
            if(arr[l]>=alpha){
                alpha=arr[l];
//                ismax=false;
            }
            
        }
        else{
            if(arr[l]<=beta){
                beta=arr[l];
              //  ismax=true;
            }
        }
    }
    if(l<r){
        int mid=(l+r)/2;
        prune(arr,2*node+1,l,mid,alpha,beta,ismax);
        prune(arr,2*node+2,mid+1,r,alpha,beta,ismax);
        int a=min(arr[2*node+1],arr[2*node+2]);
        int b=max(arr[2*node+1],arr[2*node+2]);
       if(ismax){
           if(b>=beta){
               if(alpha<=b){
               alpha=b;
               }
           }
           ismax=true;
           
       }else{
           if(a<=alpha){
               if(beta>=a){
                   beta=a;
               }
           }
           ismax=false;
       }
       
    }
}
int max(int a,int b){
    return a>b ? a:b;
}
int min(int a,int b){
    return a<b ? a:b;
}