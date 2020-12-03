#include <iostream>  // std::cout
#include <algorithm> // std::swap
#include <vector>    // std::vector
#include <numeric>
#include <limits>

#define MAX_WEIGHT 1e7;

using namespace std;
class Graph
{
    int n_node;
    vector<vector<int>> edges;
    int min_weight_edge(vector<int> ans_weights, vector<bool> included);

public:
    Graph(int n_node);
    void addEdge(int v, int w,int weight);
    unsigned long long int spanningGraph();
};

Graph::Graph(int n_node)
{
    this->n_node = n_node;
    this->edges.resize(n_node);
    for (int i = 0; i < n_node; ++i)
    {
        this->edges[i].resize(n_node,-1);
    }
}

void Graph::addEdge(int v, int w, int weight)
{
    edges[v][w]=weight;
    edges[w][v]=weight;
}

int Graph::min_weight_edge(vector<int> ans_weights, vector<bool> included)
{

    int cur_weight=MAX_WEIGHT;
    int min_index;
 
    for (int i = 0; i < n_node; i++)  
        if ((!included[i]) && (ans_weights[i] < cur_weight)){
            cur_weight = ans_weights[i];
            min_index = i;  
        }
  
    return min_index;  

}

unsigned long long int Graph::spanningGraph()
{

    vector<bool> included;
    included.resize(n_node);

    vector<int> ans_weights;
    ans_weights.resize(n_node);

    for (int i = 0; i < n_node; ++i)
    {
        ans_weights[i]=MAX_WEIGHT;
    }

    ans_weights[0]=0;

    for (int i = 0; i < n_node - 1; i++) 
    {  
        int k = min_weight_edge(ans_weights, included);  
        included[k] = true;  
        for (int j = 0; j < n_node; j++)  
            if (edges[k][j]!=-1 && (!included[j]) && edges[k][j] < ans_weights[j])  
                ans_weights[j] = edges[k][j];  
    }  
    return accumulate(ans_weights.begin(), ans_weights.end(), 0);
}

int main()
{
    unsigned n_node, n_edge;
    unsigned a, b, c;
    cin >> n_node >> n_edge;

    Graph g(n_node);

    for (int i = 0; i < n_edge; i++)
    {
        cin >> a >> b>>c;
        g.addEdge(a, b,c);
    }

    std::cout << g.spanningGraph() << std::endl;
}