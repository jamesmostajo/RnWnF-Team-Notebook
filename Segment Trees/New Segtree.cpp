#define pb push_back
typedef long long ll;
typedef vector<int> vi;
struct segtree {
ll n, *vals, *adeltas, *sdeltas;
 
segtree(vi &ar) {
    n = ar.size();
    vals = new ll[4*n];
    adeltas = new ll[4*n];
    sdeltas = new ll[4*n];
    build(ar, 1, 0, n-1); }
 
// constructs segtree
void build(vi &ar, int p, int i, int j) {
    adeltas[p] = 0;
    sdeltas[p] = -1;
    if (i == j) vals[p] = ar[i];
    else {
    int k = (i + j) / 2;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);
    pull(p); } }
 
void pull(int p) { vals[p] = vals[p<<1] + vals[p<<1|1]; }
void push(int p, int i, int j) {
    if (sdeltas[p] != -1) {
        // cout << "went here" << endl;
        vals[p] = (j - i + 1) * sdeltas[p];
        if (i != j) {
            sdeltas[p<<1] = sdeltas[p];
            adeltas[p<<1] = 0;
            adeltas[p<<1|1] = 0;
            sdeltas[p<<1|1] = sdeltas[p]; }
        sdeltas[p] = -1; }
    if (adeltas[p]) {
        vals[p] += (j - i + 1) * adeltas[p];
        if (i != j) {
            adeltas[p<<1] += adeltas[p];
            adeltas[p<<1|1] += adeltas[p]; }
        adeltas[p] = 0; } }
 
void add_update(int _i, int _j, int v, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
       adeltas[p] += v;
        push(p, i, j);
    } else if (_j < i || j < _i) {
    // do nothing
    } else {
        int k = (i + j) / 2;
        add_update(_i, _j, v, p<<1, i, k);
        add_update(_i, _j, v, p<<1|1, k+1, j);
        pull(p); } }
 
void set_update(int _i, int _j, int v, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
        sdeltas[p] = v;
        adeltas[p] = 0;
        push(p, i, j);
    } else if (_j < i || j < _i) {
    // do nothing
    } else {
        int k = (i + j) / 2;
        set_update(_i, _j, v, p<<1, i, k);
        set_update(_i, _j, v, p<<1|1, k+1, j);
        pull(p); } }
 
ll query(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i and j <= _j)
    return vals[p];
    else if (_j < i || j < _i)
    return 0;
    else {
    int k = (i + j) / 2;
    return query(_i, _j, p<<1, i, k) +
            query(_i, _j, p<<1|1, k+1, j); } } 
 
ll query(int l, int r){
    return query(l-1, r-1, 1, 0, n-1);
}
 
void add_update(int b, int c, int d){
    add_update(b-1, c-1, d, 1, 0, n-1);
}};