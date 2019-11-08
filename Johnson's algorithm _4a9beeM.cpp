#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#define max 1000
using namespace std;
class graph{
    public:
    vector<int> arr[4];
    graph(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                arr[i].push_back(0);
            }
        }
    }
    void addedge(int u,int v,int w){
        arr[u][v]=w;
    }
    int* bellman(){
        int temp[4];
        bool visited[4];
        memset(visited,false,4);
        for(int i=0;i<4;i++){
            if(!visited[i]){
                for(int j=0;j<4;j++){
                    if(temp[i]+arr[i][j]>temp[j]){
                        temp[j]=temp[i]+arr[i][j];
                    }
                }
                visited[i]=true;
            }
        }
        return temp;
    }
    void updateweight(){
        int* temp=bellman();
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                arr[i][j]+=abs(temp[i]-temp[j]);
            }
        }
    }
    void dijkastra(){
        updateweight();
        vector<int> temp=arr[0];
        bool visited[4];
        memset(visited,false,4);
        for(int i=0;i<4;i++){
            if(!visited[i]){
                for(int j=0;j<4;j++){
                    if(temp[i]+arr[i][j]>temp[j]){
                        temp[j]=temp[i]+arr[i][j];
                    }
                }
                visited[i]=true;
            }
        }
        for(int i=0;i<4;i++){
            std::cout<<i<<" "<<temp[i]<<"\n";
        }
    }
};
int main()
{
    //cout << "Hello World!" << endl;
    graph g;
    g.addedge(0,1,3);
    g.addedge(0,2,-2);
    g.addedge(0,3,5);
    g.addedge(1,2,-4);
    g.addedge(2,3,6);
    g.dijkastra();
    return 0;
}
