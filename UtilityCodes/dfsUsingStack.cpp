#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph{
	int V;
	list<int> * adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int s);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int> [V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFS(int s){
	vector<bool> Visited(V, false);
	stack<int> Stack;
	Stack.push(s);
	while(!Stack.empty()){
		s = Stack.top();
		Stack.pop();
		if(!Visited[s]){
			Visited[s]= true;
			cout << s << " ";
		}
		list<int>::iterator i;
		for( i = adj[s].begin();  i!=adj[s].end() ; ++i ){
			if(!Visited[*i])
				Stack.push(*i);
		}
	}
}


int main()
{
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
 
    cout << "Following is Depth First Traversal\n";
    g.DFS(0);
 
    return 0;
}