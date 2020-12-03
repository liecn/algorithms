#include <iostream>  // std::cout
#include <algorithm> // std::swap
#include <vector>    // std::vector

using namespace std;
class Graph
{
    int n_node;
    vector<vector<int>> edges;
    void DFS(int v, vector<bool> &visited);

public:
    Graph(int n_node);
    void addEdge(int v, int w);
    int countSubgraph();
};

Graph::Graph(int n_node)
{
    this->n_node = n_node;
    this->edges.resize(n_node);
}

void Graph::addEdge(int v, int w)
{
    edges[v].push_back(w);
    edges[w].push_back(v);
}

int Graph::countSubgraph()
{

    vector<bool> visited;
    visited.resize(n_node);

    int count = 0;
    for (int v = 0; v < n_node; v++)
    {
        if (visited[v] == false)
        {
            DFS(v, visited);
            count += 1;
        }
    }

    return count;
}

void Graph::DFS(int v, vector<bool> &visited)
{

    visited[v] = true;
    vector<int>::iterator i;
 
    for (i = edges[v].begin(); i != edges[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}

int main()
{
    unsigned n_node, n_edge;
    unsigned a, b;
    cin >> n_node >> n_edge;

    Graph g(n_node);

    for (int i = 0; i < n_edge; i++)
    {
        cin >> a >> b;
        g.addEdge(a, b);
    }

    std::cout << g.countSubgraph() << std::endl;
}