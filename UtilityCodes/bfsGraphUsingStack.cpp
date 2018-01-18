#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

class Graph{
        int V;
        list<int> *adj;
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void BFS(int s);
};
Graph :: Graph( int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    vector<bool> visited(V, false);
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        s = Q.front();
        Q.pop();
        if(!visited[s]){
            visited[s] = true;
            cout << s << " ";
        }
        list<int>::iterator i;
        for(i = adj[s].begin(); i!= adj[s].end(); ++i)
            if(!visited[*i])
                Q.push(*i);
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
    g.BFS(0);
 
    return 0;
}