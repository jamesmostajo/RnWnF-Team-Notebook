// Bellman-Ford

struct Edge {
    int a, b, cost;
};

int n, m, v;
vector<Edge> edges;
const int INF = 1000000000;

void solve(){
    vector<int> d(n, INF);
    d[v] = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool any = false;

        for (Edge e : edges)
            if (d[e.a] < INF)
                if (d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = d[e.a] + e.cost;
                    any = true;
                }

        if (!any)
            break;
    }
    // display d, for example, on the screen
}

// python pseudodcode (not tested)
distance = [float('inf') for _ in range(n + 1)]
for k in range(1, n):
  for u in range(1, n + 1):
    for v, w in adj[u]:
      distance[v] = min(distance[v], distance[u] + w)
for u in range(1, n + 1):
  for v, w in adj[u]:
    if distance[v] > distance[u] + w:
      report_negative_cycle()