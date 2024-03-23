// Dijkstra

// For non-sparse graphs O(n^2 + m)

const int INF = INT_MAX;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    // can be implemented using a priority queue with negative values but this works as well
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
}}}}

// python pseudocode(not tested)
import heapq
distance = [float('inf') for _ in range(n + 1)]
distance[source] = 0
shortest_path_tree_parent = [-1 for _ in range(n + 1)]
queue = [(distance[source], source)]
done = [False for _ in range(n + 1)]
while len(queue) > 0:
  _, u = heapq.heappop(queue)
  if not done[u]:
    for v, w in adj[u]:
      if distance[v] > distance[u] + w:
        distance[v] = distance[u] + w
        shortest_path_tree_parent[v] = u
        heapq.heappush((distance[v], v))
    done[u] = True