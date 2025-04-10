struct DSU
{
    vector<int> par;
    DSU(int n) : par(n) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        par[y] = x;
        return true;
    }
};
int kruskal(int n, vector<tuple<int, int, int>> &edges)
{
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int total = 0;
    for (auto [w, u, v] : edges)
        if (dsu.unite(u, v))
            total += w;
    return total;
}