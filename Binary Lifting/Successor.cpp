// given directed edges
// find where you end up after k steps from node i
vector<vector<int>> succpow2;
 
int succ(int x, int k){
    int node = x;
    for (int i=0; i<30; i++){
        if (k & (1 << i)){
            node = succpow2[i][node];
        }
    }
    return node;
}
 
int main(){
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, q; cin >> n >> q;
    succpow2.resize(30, vector<int>(n+1));
 
    for (int i=1; i<=n; i++){cin >> succpow2[0][i];}
    for (int i=1; i<30; i++){
        for (int j=1; j<=n; j++){
            succpow2[i][j] = succpow2[i-1][succpow2[i-1][j]];
        }
    }
 
    while (q--){
        int x, k; cin >> x >> k;
        cout << succ(x, k) << endl;
    }
    return 0;
}