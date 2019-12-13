#include <bits/stdc++.h>
using namespace std;

class hamilton
{
	private:
	int n;
	vector<int>* adj;
	vector<int> path;
	void findcycleutil(int src,int dest,bool v[])
	{
		path.push_back(src);
		if(src!=0)
		{
			v[src]=true;
		}
		if(src==dest)
		{
			if(path.size()==n+1)
			{
				for(int i=0;i<path.size();i++)
				{
					cout<<path[i]<<" ";
				}
				cout<<"\n";
			}
		}
		for(int i=0;i<adj[src].size();i++)
		{
			if(!v[adj[src][i]])
			{
				findcycleutil(adj[src][i],dest,v);
			}
		}
		path.pop_back();
		v[src]=false;
	}
	public:
	hamilton(int m)
	{
		n=m;
		adj=new vector<int>[n];
	}
	void addedge(int u,int v)
	{
		adj[u].push_back(v);
	}
	void findcycle()
	{
		bool visited[n];
		memset(visited,false,n*sizeof(bool));
		findcycleutil(0,0,visited);
	}
};
main()
{
	hamilton g(4);
	g.addedge(0,1);
	g.addedge(0,3);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(3,0);
	g.findcycle();
}
