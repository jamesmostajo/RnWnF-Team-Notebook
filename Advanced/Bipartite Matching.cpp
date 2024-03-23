int b, g, m, n;
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
  void get_matching(){
    // only call after running calc_max_flow()
    vector<int> has_match;
    for (auto ind: adj[0]){
      edge& e = edges[ind];
      if (e.residue() == 0) has_match.push_back(e.v);
    }
    for (int a: has_match){
      for (auto ind: adj[a]){
        edge& e = edges[ind];
        if (e.residue() == 0){
          printf("%d %d\n", a, (e.v)-b);
          break;
} }
} }
};
int main(){
  cin >> b >> g >> m;
  n = b+g+2;
  flow_network fn(n, 0, n-1);
  for (int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    fn.add_edge(u,b+v,1);
}
  for (int i=1; i<=b; i++){
    fn.add_edge(0, i, 1);
  }
  for (int i=b+1; i<(n-1); i++){
    fn.add_edge(i, n-1, 1);
  }
  cout << fn.calc_max_flow() << endl;
  fn.calc_max_flow();
  fn.get_matching();
}