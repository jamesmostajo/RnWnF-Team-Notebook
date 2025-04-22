struct segtree {
    ll n, *vals, *mdeltas;
    segtree() {}
    void init(vi &ar){
        n = ar.size();
        vals = new ll[4*n];
        mdeltas = new ll[4*n];
        build(ar, 1, 0, n-1);
    }
     
    // constructs segtree
    void build(vi &ar, int p, int i, int j) {
        mdeltas[p] = 1;
        if (i == j) vals[p] = ar[i];
        else {
        int k = (i + j) / 2;
        build(ar, p<<1, i, k);
        build(ar, p<<1|1, k+1, j);
        pull(p); } }
     
    void pull(int p) { vals[p] = mod(vals[p<<1] + vals[p<<1|1]); }
    void push(int p, int i, int j) {
        if (mdeltas[p] != 1) {
            vals[p] = mod(vals[p]*mdeltas[p]);
            if (i != j) {
                mdeltas[p<<1] =  mod(mdeltas[p<<1]*mdeltas[p]);
                mdeltas[p<<1|1] = mod(mdeltas[p<<1|1]*mdeltas[p]);
            }
        }
        mdeltas[p] = 1;
    }
     
    void mult_update(int _i, int _j, int v, int p, int i, int j) {
      push(p, i, j);
      if (_i <= i && j <= _j) {
         mdeltas[p] = mod(mdeltas[p]*v);
        push(p, i, j);
      } else if (_j < i || j < _i) {
      // do nothing
      } else {
        int k = (i + j) / 2;
        mult_update(_i, _j, v, p<<1, i, k);
        mult_update(_i, _j, v, p<<1|1, k+1, j);
        pull(p); } }
     
    ll query(int _i, int _j, int p, int i, int j) {
        push(p, i, j);
        if (_i <= i and j <= _j)
            return vals[p];
        else if (_j < i || j < _i) 
        return 0;
        else {
        int k = (i + j) / 2;
        return mod(query(_i, _j, p<<1, i, k) + 
         query(_i, _j, p<<1|1, k+1, j)); 
            } 
        }
     
    ll query(ll l, ll r) {
        return query(l-1, r-1, 1, 0, n-1);
        } 
     
    ll query(ll i) {
        return query(i-1, i-1, 1, 0, n-1);
        } 
     
    void mult_update(ll l, ll r, ll v) {
        mult_update(l-1, r-1, v, 1, 0, n-1);
    }
};