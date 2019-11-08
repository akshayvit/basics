#include <iostream>
#define V 4
using namespace std;
void closure(bool graph[][V]); 
int main()
{
    //printf("Hello World!\n");
    bool graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
    closure(graph);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            std::cout<<graph[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}
void closure(bool graph[][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            for(int k=i;k<j;k++){
                graph[i][j]=graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}