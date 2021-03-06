#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class graph
{
	int v;//No. of vertices
	list <int> *adj;//Adjacency list

public:
	graph(int V)
	{
		this->v=V;
		adj = new list<int>[V];
	}

	void addEdge(int V, int w) //This function adds an edge to the graph
	{
		adj[V].push_back(w);
	}

	void BFS(int V);// This function carries out BFS
	
	~graph()// Destructor
	{
		delete[] adj;
	}

};

void graph::BFS(int V)
{
	bool *visited = new bool[V];
	memset(visited , false , V);

	list<int> queue;

	queue.push_back(V);

	while(!queue.empty())
	{
		int f = queue.front();
		cout<<f<<' ';
		queue.pop_front();

		list <int>::iterator i;

		for(i=adj[f].begin();i!=adj[f].end();i++)
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}

	}	

	delete visited;

}

int main()
{
	//Sample test
	graph g(11);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(0,4);
	g.addEdge(1,5);
	g.addEdge(1,6);
	g.addEdge(1,7);
	g.addEdge(1,8);
	g.addEdge(2,9);
	g.addEdge(1,10);				
	g.BFS(0);

	return 0;

}