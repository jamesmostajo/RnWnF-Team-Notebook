int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

// python pseudocode
visited = [False for _ in range(n + 1)]
in_dfs_stack = [False for _ in range(n + 1)]
topologically_sorted = []
def toposort(u):
  in_dfs_stack[u] = True
  visited[u] = True
  for v in rev_adj[u]:
    if in_dfs_stack[v]:
      report_cycle()
    elif not visited[v]:
      toposort(v)
  topologically_sorted.append(u)
  in_dfs_stack[u] = False
for u in range(1, n + 1):
  if not visited[u]:
toposort(u)
