#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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

void dijkstra(vector<vector<int>> graph, int src, vector<int> &dist, vector<int> &parent, int n_node, vector<int> node_importance)
{
    vector<bool> sptSet;
    sptSet.resize(n_node);

    for (int i = 0; i < n_node; i++)
        dist[i] = INT_MAX, sptSet[i] = false, parent[i] = -1;

    dist[src] = 0;

    for (int count = 0; count < n_node; count++)
    {
        int u = minDistance(dist, sptSet, n_node);

        sptSet[u] = true;

        for (int v = 0; v <= n_node; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + node_importance[v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + node_importance[v];
            }
    }
}

int main()
{
    int n_node, n_edges, n_node_critical;

    cin >> n_node >> n_edges >> n_node_critical;

    vector<vector<int>> edge_matrix;
    vector<int> critical_node, critical_node_flag;

    edge_matrix.resize(n_node);
    critical_node.resize(n_node_critical);
    critical_node_flag.resize(n_node);

    for (int i = 0; i < n_node; i++)
    {
        edge_matrix[i].resize(n_node);
    }

    int a, b;
    for (int i = 0; i < n_edges; i++)
    {
        cin >> a >> b;
        edge_matrix[a][b] = 1;
        edge_matrix[b][a] = 1;
    }

    vector<int> node_importance;
    node_importance.resize(n_node, 2 * n_node);
    //record the critical node
    for (int i = 0; i < n_node_critical; i++)
    {
        cin >> a;
        critical_node[i] = a;
        critical_node_flag[a] = 1;
        node_importance[a] -= n_node_critical;
    }

    for (int i = 0; i < n_node_critical; i++)
    {
        for (int j = 0; j < n_node; j++)
        {
            if (edge_matrix[critical_node[i]][j] != 0)
            {
                node_importance[j]--;
            }
        }
    }
    
    int ans = INT_MAX;
    for (int kkk = 0; kkk <n_node_critical; kkk++)
    {
        vector<int> dist, parent, mst, path,node_processed;
        dist.resize(n_node);
        parent.resize(n_node);
        mst.resize(n_node);
        // path.resize(n_node);
        node_processed.resize(n_node);
        int n_path = 0, n_mst = 0;

        int critical_node_index = kkk;
        dijkstra(edge_matrix, critical_node[critical_node_index], dist, parent, n_node, node_importance);
        node_processed[critical_node[critical_node_index]] = 1;
        mst[0] = critical_node[critical_node_index];
        n_mst++;

        int critical_node_included = 1;
        int critical_node_source, critical_node_target;
        int count_try = 0;
        while (critical_node_included < n_node_critical && count_try < n_node_critical)
        {
            int min_val = INT_MAX;
            for (int i = 0; i < n_node_critical; i++)
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

            int min_cost = INT_MAX;
            int cost_temp;
            for (int i = 0; i < n_mst; i++)
            {
                dijkstra(edge_matrix, mst[i], dist, parent, n_node, node_importance);
                n_path = 0;
                path.resize(n_node);
                find_parent(parent, critical_node_target, path, n_path);

                cost_temp = n_path;
                if (cost_temp < min_cost)
                {
                    min_cost = cost_temp;
                    critical_node_source = mst[i];
                }
            }

            dijkstra(edge_matrix, critical_node_source, dist, parent, n_node, node_importance);
            n_path = 0;
            path.resize(n_node);
            find_parent(parent, critical_node_target, path, n_path);

            for (int j = 0; j < n_path; j++)
            {
                if (j == 0)
                {
                    if (node_processed[path[0]] == 0)
                    {
                        node_processed[path[0]] = 1;
                        mst[n_mst] = path[0];
                        n_mst++;
                        if (critical_node_flag[path[0]] == 1)
                        {
                            critical_node_included++;
                        }
                    }
                }
                else
                {
                    if (node_processed[path[j - 1]] == 0)
                    {
                        node_processed[path[j - 1]] = 1;
                        mst[n_mst] = path[j - 1];
                        n_mst++;
                        if (critical_node_flag[path[j - 1]] == 1)
                        {
                            critical_node_included++;
                        }
                    }
                    if (node_processed[path[j]] == 0)
                    {
                        node_processed[path[j]] = 1;
                        mst[n_mst] = path[j];
                        n_mst++;
                        if (critical_node_flag[path[j]] == 1)
                        {
                            critical_node_included++;
                        }
                    }
                }
            }
            count_try++;
        }
        if (critical_node_included == n_node_critical)
        {
            if (n_mst < ans)
                ans = n_mst;
        }
        else{
            if (ans>=200)
                ans = 200;
        }   
    }
    std::cout << ans << std::endl;
}