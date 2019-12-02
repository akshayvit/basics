#include<bits/stdc++.h> 
using namespace std; 

class edge
{
    int u,v;
};

class Graph 
{ 
	int V; 
	list<int> *adj; 
public: 
	Graph(int V); 
	void addEdge(int v, int w); 
	void printVertexCover(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v);
} 

void Graph::printVertexCover() 
{ 
	bool visited[V];
	memset(visited,false,V*sizeof(bool));
	for(int i=0;i<V;i++)
	{
	    list<int>::iterator itr;
	    if(!visited[i])
	    for(itr=adj[i].begin();itr!=adj[i].end();itr++)
	    {
	              if(!visited[*itr])
	              {
	                  visited[i]=visited[*itr]=true;
	                  break;
	              }
	    }
	}
	for(int i=0;i<V;i++)
	{
	    if(visited[i])
	    {
	        printf("%d ",i);
	    }
	}
	printf("\n");
} 

int main() 
{ 
	Graph g(7); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 3); 
	g.addEdge(3, 4); 
	g.addEdge(4, 5); 
	g.addEdge(5, 6); 

	g.printVertexCover(); 

	return 0; 
} 
