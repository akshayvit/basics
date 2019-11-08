#include <iostream>
#include <string.h>
#include <vector>
#define n 5
struct point{
    int x,point,y;
};
using namespace std;
void mst(int mat[][n]);
void merge_sort(point* arr,int l,int r);
void merge(point* arr,int l,int mid,int r);
bool isconnected(int** m,int i,int j);
int main()
{
    //printf("Hello World!\n");
    int mat[][n]={{12,0,0,1,2},
    {16,1,2,0,0},
    {23,12,11,5,2},
    {8,0,0,0,1},
    {19,12,1,4,0}};
    mst(mat);
    return 0;
}
void mst(int mat[][n]){
    point temp[n*n];
    for(int i=0;i<n*n;i++){
        temp[i]=point(0,0,0);
    }
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[k]=mat[i][j];
            k++;
        }
    }
    merge_sort(temp);
    int** m=new int[][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=0){
                m[i][j]=1;
            }
        }
    }
    bool check[n*n];
    memset(check,false,n*n);
    vector<point> v;
    for(int i=0;i<sizeof(check)/sizeof(check[0]);i++){
        if(m[p[i].x][p[i].y]==1){
            m[p[i].x][p[i].y]=0;
            if(isconnected(m,p[i].x,p[i].y)){
                v.push_back(p[i]);
            }
        }
    }
    for(int i=0;i<v.size();i++){
        std::cout<<v[i].x<<" "<<v[i].y<<"\n";
    }
}
bool isconnected(int** m,int i,int j){
    m[i][j]=0;
    vector<int> v;
    int visited[n];
    visited[0]=1;
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                    v.push_back(j);
            }
        }
        visited[i]=1;
        }
    }
    return v[v.size()-1]==n-1 ? true:false;
}
void merge_sort(point* arr,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
    }
}
void merge(point* arr,int l,int mid,int r){
    int temp[mid-l+1];
    int temp1[r-mid+1];
    int j=mid+1;
    for(int i=l;i<mid && j<r;i++){
        if(arr[i].point<arr[j].point){
            temp[i]=arr[i];
            temp1[j]=arr[j];
        }
        else{
            temp[i]=arr[j];
            temp1[j]=arr[i];
        }
    }
    for(int i=l;i<mid;i++){
        arr[i]=temp[i];
    }
    for(int i=mid+1;i<r;i++){
        arr[i]=temp1[i];
    }
}