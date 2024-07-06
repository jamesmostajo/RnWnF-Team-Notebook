// given a tree
// find node i's kth ancestor up the tree
vector<vector<int>> ancestor;
 
int anc(int x, int k){
    int node = x;
    for (int i=0; i<20; i++){
        if (node == -1) return -1;
        if (k & (1 << i)){
            node = ancestor[i][node];
        }
    }
    return node;
}
 
int main(){
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, q; cin >> n >> q;
    ancestor.resize(20, vector<int>(n+1));
    
    for (int i=2; i<=n; i++){cin >> ancestor[0][i];}
    ancestor[0][1] = -1;
 
    for (int i=1; i<20; i++){
        for (int j=1; j<=n; j++){
            ancestor[i][j] = ancestor[i-1][j] == -1 ? -1 : ancestor[i-1][ancestor[i-1][j]];
        }
    }

    while (q--){
        int x, k; cin >> x >> k;
        cout << anc(x, k) << endl;
    }
    return 0;
}