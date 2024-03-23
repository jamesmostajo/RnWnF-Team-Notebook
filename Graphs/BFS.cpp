// BFS
void bfs(int n, int s){  // number of nodes, source vertex
    vector<vector<int>> adj;  // adjacency list representation
    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n), p(n);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
}}}}

// python pseudocode(not tested)
distance = [-1 for _ in range(n + 1)]
distance[source] = 0
shortest_path_tree_parent = [-1 for _ in range(n + 1)]
queue = [source]
for u in queue:
  for v in adj[u]:
    if distance[v] == -1:
      distance[v] = distance[u] + 1
      shortest_path_tree_parent[v] = u
      queue.append(v)

