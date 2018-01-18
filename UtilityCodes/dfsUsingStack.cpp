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
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}