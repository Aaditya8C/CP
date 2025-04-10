vector<pair<int, int>> bridges;
int timer = 0;
void dfsBridge(int u, int p, vector<vector<int>> &g, vector<int> &tin, vector<int> &low, vector<bool> &vis)
{
    vis[u] = true;
    tin[u] = low[u] = timer++;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        if (vis[v])
            low[u] = min(low[u], tin[v]);
        else
        {
            dfsBridge(v, u, g, tin, low, vis);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u])
                bridges.emplace_back(u, v);
        }
    }
}