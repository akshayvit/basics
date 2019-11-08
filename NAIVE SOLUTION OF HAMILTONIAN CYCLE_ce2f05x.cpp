#include <iostream>
using namespace std;
#define n 5
void printpath(int mat[][n]);
int main()
{
    //cout << "Hello World!" << endl;
    int graph1[][n] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
    printpath(graph1);
    return 0;
}
void printpath(int mat[][n]){
    int* visited=new int[n];
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
        for(int j=0;j<n;j++){
                if(mat[i][j]==1 && mat[j][0]==1){
                    std::cout<<i<<" ";
                    
                }
        }
        std::cout<<"\n";
        visited[i]=1;
        }
    }
}