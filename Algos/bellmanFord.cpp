vector<int> bellmanFord(int n, int src, vector<tuple<int, int, int>> &edges)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
        for (auto [u, v, w] : edges)
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
    return dist;
}
