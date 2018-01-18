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
        bool isReachable(int s, int d);
};
Graph :: Graph( int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

bool Graph::isReachable(int s, int d){
    vector<bool> visited(V, false);
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        s = Q.front();
        Q.pop();
        if(!visited[s]){
            visited[s] = true;
            cout << s << " ";
            if(s == d)
                return true;
        }
        list<int>::iterator i;
        for(i = adj[s].begin(); i!= adj[s].end(); ++i)
            if(!visited[*i])
                Q.push(*i);
    }
    return false;
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
 
    int u = 1, v = 3;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    return 0;
}