struct edge {
  size_t i; // index at edges
  int v, c, f; // directed to v, capacity, flow
  int residue() { return c - f; }
};
struct flow_network {
  int n, s, t;
  vector<edge> edges;  // even indeces are forward flows, e_i+1 are reverse flows.
  vector<vector<int>> adj; // stores index pointing in edges
  vector<int> parent;
  flow_network(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
    parent.resize(n);
}
  void add_edge(int u, int v, int cap) {
    edges.push_back({edges.size(), v, cap, 0});
    adj[u].push_back((int)edges.size()-1);
    edges.push_back({edges.size(), u, 0, 0}); // reverse
    adj[v].push_back((int)edges.size()-1);
}
  bool aug_path() {
    for (int i=0; i<n; i++) parent[i] = -1;
    parent[s] = s;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      // cout << "Pop: " << u << endl;
      if (u == t) break;
      for (auto ind : adj[u]){
        edge& e = edges[ind];
        // cout << e.i << " " << e.v << endl;
        if (e.residue() > 0 && parent[e.v] == -1) {
          parent[e.v] = e.i;
          q.push(e.v);
} }
}
    return parent[t] != -1;
  };
  int augment() {
    int bottleneck = numeric_limits<int>::max();
    for (int v = t; v != s; v = edges[parent[v] ^ 1].v) {
      bottleneck = min(bottleneck, edges[parent[v]].residue());
    }
    for (int v = t; v != s; v = edges[parent[v] ^ 1].v) {
      edges[parent[v]].f += bottleneck;
      edges[parent[v] ^ 1].f -= bottleneck;
}
    return bottleneck;
  }
  int calc_max_flow() {
    int flow = 0;
    while (aug_path()){
      flow += augment();
    }
    return flow;
  }
  void get_min_cut(){
    // only call after running calc_max_flow()
    queue<int> q;
    vector<int> vis(n+1, 0);
    vector<vector<int>> pted (51, vector<int>(51, 0));
    q.push(s);
    while (!q.empty()){
      int u = q.front(); q.pop();
      for (auto ind: adj[u]){
        edge& e = edges[ind];
        if (e.residue() > 0 && !vis[e.v]) {
          vis[e.v] = 1;
          q.push(e.v);
} }
    }
    for (int i=0; i<n+1; i++){
      if (vis[i]){
        for (auto ind: adj[i]){
          edge& e = edges[ind];
          if ( (!vis[e.v]) and (!pted[i][e.v]) ) {
            printf("%d %d\n", i+1, e.v+1);
            pted[i][e.v] = 1;
          }
} }
} }
};
int main(){
  int n, m;
  cin >> n >> m;
  flow_network fn(n, 0, 1);
  for (int i=0; i<m; i++){
    int u, v, cap;
    cin >> u >> v >> cap;
    fn.add_edge(u-1, v-1, cap);
    fn.add_edge(v-1, u-1, cap);
}
  // cout << fn.calc_max_flow() << endl;
  fn.calc_max_flow();
  fn.get_min_cut();
}