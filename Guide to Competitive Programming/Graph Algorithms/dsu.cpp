struct DSU {
    vi pars, sizes;

    DSU(const int n) : pars(n), sizes(n, 1) {
      for (int i = 0; i < n; i++) pars[i] = i;
    }

    int root(const int v) {
        return pars[v] == v ? v : (pars[v] = root(pars[v]));
    }

    void unite(const int u, const int v) {
        if (root(u) == root(v)) return;

        int U = root(u), V = root(v);

        if (sizes[U] < sizes[V]) swap(U, V);

        sizes[U] += sizes[V]; pars[V] = U;
    }

    bool connected(const int u, const int v) {
        return root(u) == root(v);
    }
};
