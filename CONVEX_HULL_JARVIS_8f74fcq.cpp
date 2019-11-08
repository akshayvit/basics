#include <iostream>
#include<stdlib.h>
using namespace std;
struct point{
    int x;
    int y;
};
static int t=-1;
void push(point* st,int tot,point p);
int orientation(point p, point q, point r);
point sorted(point* p);
void cango(point left,point* arr,point* next,int n,int ind);
bool operator !=(const point &q,const point &p);
bool operator +=(const point &q,const point &p);
int main()
{
    point p[]={{0, 3}, {2, 2}, {1, 1}, {2, 1},{3, 0}, {0, 0}, {3, 3}};
    point left=sorted(p);
    int n=sizeof(p)/sizeof(p[0]);
    point* next=new point[n];
    cango(left,p,next,n,0);
    return 0;
}
bool operator !=(const point &q,const point &p){
    return q.x!=p.x && q.y!=p.y;
}
bool operator +=( point &q, point &p){
    return q.x==p.x && q.y==p.y;
}
void cango(point left,point* arr,point* next,int n,int ind){
    point p=left;
    point* stack=(point*)malloc(sizeof(point)*n);
    while(left!=p){
        point q=arr[ind];
        push(stack,n,p);
        int j=(ind+1)%n;
        for(int i=0;i<n;i+=1)
        {
            if(orientation(p,arr[i],q)==2)
            {
                q+=arr[i];
            }
        }
        next[ind]+=q;
        p+=q;
        ind+=1;
    }
    for(int i=0;i<n;i+=1){
        std::cout<<"x: "<<stack[i].x<<" "<<"y: "<<stack[i].y<<"\n";
    }
    free(stack);
}

int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
point sorted(point* p)
{
    int len=sizeof(p)/sizeof(p[0]);
    for(int i=0;i<len;i+=1)
    {
        if(p[i].y<p[i+1].y){
            point temp=p[i];
            p[i]=p[i+1];
            p[i+1]=temp;
        }
    }
    for(int i=0;i<len;i+=1)
    {
        if(p[i].x>p[i+1].x+1){
            point temp=p[i];
            p[i]=p[i+1];
            p[i+1]=temp;
        }
    }
    return p[0];
}
void push(point* st,int tot,point p){
    if(t<tot-1)
    {
        t+=1;
        st[t]=p;
    }
}