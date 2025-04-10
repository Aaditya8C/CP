void dfs1(int u, vector<vector<int>> &g, vector<bool> &vis, stack<int> &s)
{
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v])
            dfs1(v, g, vis, s);
    s.push(u);
}
void dfs2(int u, vector<vector<int>> &rev, vector<bool> &vis, vector<int> &comp)
{
    vis[u] = true;
    comp.push_back(u);
    for (int v : rev[u])
        if (!vis[v])
            dfs2(v, rev, vis, comp);
}
vector<vector<int>> kosaraju(int n, vector<vector<int>> &g)
{
    stack<int> s;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs1(i, g, vis, s);

    vector<vector<int>> rev(n);
    for (int u = 0; u < n; u++)
        for (int v : g[u])
            rev[v].push_back(u);

    fill(vis.begin(), vis.end(), false);
    vector<vector<int>> scc;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        if (!vis[u])
        {
            vector<int> comp;
            dfs2(u, rev, vis, comp);
            scc.push_back(comp);
        }
    }
    return scc;
}