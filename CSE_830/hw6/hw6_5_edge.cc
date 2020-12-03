#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

int minDistance(vector<int> dist, vector<bool> sptSet, int n_node)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n_node; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void find_parent(vector<int> parent, int j, vector<int> &path, int &n_path)
{
    if (parent[j] == -1)
        return;
    find_parent(parent, parent[j], path, n_path);
    path[n_path] = j;
    n_path++;
}

void dijkstra(vector<vector<int>> graph, int src, vector<int> &dist, vector<int> &parent, int n_node)
{
    vector<bool> sptSet;
    sptSet.resize(n_node);

    for (int i = 0; i < n_node; i++)
        dist[i] = INT_MAX, sptSet[i] = false, parent[i] = -1;

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n_node; count++)
    {
        int u = minDistance(dist, sptSet, n_node);

        sptSet[u] = true;

        for (int v = 0; v <= n_node; v++)
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
}

int main()
{
    int n_node, n_edges, n_node_critical, ans = 0;

    cin >> n_node >> n_edges >> n_node_critical;

    vector<vector<int>> edge_matrix;
    vector<int> critical_node, dist, parent, mst, path;
    int n_path = 0, n_mst = 0;

    edge_matrix.resize(n_node);
    critical_node.resize(n_node_critical);
    dist.resize(n_node);
    parent.resize(n_node);
    mst.resize(n_node);
    path.resize(n_node);

    vector<int> critical_node_flag, node_processed;
    vector<vector<int>> edge_matrix_added, edge_matrix_included;

    critical_node_flag.resize(n_node_critical);
    node_processed.resize(n_node);
    edge_matrix_added.resize(n_node);
    edge_matrix_included.resize(n_node);

    for (int i = 0; i < n_node; i++)
    {
        edge_matrix[i].resize(n_node);
        edge_matrix_added[i].resize(n_node);
        edge_matrix_included[i].resize(n_node);
    }

    int a, b;
    for (int i = 0; i < n_edges; i++)
    {
        cin >> a >> b;
        edge_matrix[a][b] = 4 * n_node+1;
        edge_matrix[b][a] = 4 * n_node+1;
    }

    vector<int> node_importance;
    node_importance.resize(n_node);
    //record the critical node
    for (int i = 0; i < n_node_critical; i++)
    {
        cin >> a;
        critical_node[i] = a;
        node_importance[a]=n_node_critical;
    }

    for (int i = 0; i < n_node_critical; i++)
    {
        for (int j = 0; j < n_node; j++)
        {
            if (edge_matrix[critical_node[i]][j] != 0)
            {
                node_importance[j]++;
            }
        }
    }

    for (int i = 0; i < n_node - 1; i++)
    {
        for (int j = i + 1; j < n_node; j++)
        {
            if (edge_matrix[i][j] != 0)
            {
                int weight_loss = node_importance[i] + node_importance[j];
                edge_matrix[i][j] -= weight_loss;
                edge_matrix[j][i] -= weight_loss;
            }
        }
    }

    // printf("Critical Vertex \"%d\" is added to MST\n", critical_node[0]);
    dijkstra(edge_matrix, critical_node[0], dist, parent, n_node);
    node_processed[critical_node[0]] = 1;
    mst[0] = critical_node[0];
    n_mst++;

    int critical_node_included = 1;
    int critical_node_source, critical_node_target;
    while (critical_node_included < n_node_critical)
    {
        critical_node_target = 0;
        int min_val = INT_MAX;
        for (int i = 1; i < n_node_critical; i++)
        {
            int critical_node_target_temp = critical_node[i];
            if ((min_val > dist[critical_node_target_temp]) &&
                (dist[critical_node_target_temp] != 0) &&
                ((node_processed[critical_node_target_temp]) == 0))
            {
                critical_node_target = critical_node_target_temp;
                min_val = dist[critical_node_target_temp];
            }
        }

        // printf("Next Critical Vertex to be added to MST is : \"%d\" \n", critical_node_target);

        int min_cost = INT_MAX;
        int cost_temp;
        for (int i = 0; i < n_mst; i++)
        {
            dijkstra(edge_matrix, mst[i], dist, parent, n_node);
            n_path = 0;
            path.resize(n_node);
            find_parent(parent, critical_node_target, path, n_path);

            for (int j = 0; j < n_path; j++)
            {
                if (j == 0)
                {
                    if (edge_matrix_added[mst[i]][path[0]] == 0)
                    {
                        edge_matrix_added[mst[i]][path[0]] = 1;
                    }
                }
                else
                {
                    if (edge_matrix_added[path[j - 1]][path[j]] == 0)
                    {
                        edge_matrix_added[path[j - 1]][path[j]] = 1;
                    }
                }
            }
            cost_temp = n_path;
            if (cost_temp < min_cost)
            {
                min_cost = cost_temp;
                critical_node_source = mst[i];
            }

            for (int l = 0; l < n_node; l++)
            {
                for (int m = 0; m < n_node; m++)
                {
                    edge_matrix_added[l][m] = edge_matrix_included[l][m];
                }
            }
        }
        dijkstra(edge_matrix, critical_node_source, dist, parent, n_node);
        n_path = 0;
        path.resize(n_node);
        find_parent(parent, critical_node_target, path, n_path);

        for (int j = 0; j < n_path; j++)
        {
            if (j == 0)
            {
                if (edge_matrix_included[critical_node_source][path[0]] == 0)
                {
                    edge_matrix_included[critical_node_source][path[0]] = 1;

                    if (node_processed[path[0]] == 0)
                    {
                        node_processed[path[0]] = 1;
                        mst[n_mst] = path[0];
                        n_mst++;
                    }
                }
            }
            else
            {
                if (edge_matrix_included[path[j - 1]][path[j]] == 0)
                {
                    edge_matrix_included[path[j - 1]][path[j]] = 1;
                    if (node_processed[path[j - 1]] == 0)
                    {
                        node_processed[path[j - 1]] = 1;
                        mst[n_mst] = path[j - 1];
                        n_mst++;
                    }
                    if (node_processed[path[j]] == 0)
                    {
                        node_processed[path[j]] = 1;
                        mst[n_mst] = path[j];
                        n_mst++;
                    }
                }
            }
        }
        ans += n_path;
        critical_node_included++;
    }
    std::cout << n_mst << std::endl;
    // std::cout << accumulate(node_processed.begin(), node_processed.end(), 0) << std::endl;
}