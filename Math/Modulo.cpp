ll mod(ll x, ll m){
    if (m == 0) return 0;
    if (m < 0) m*=-1;
    return (x%m + m)%m;
}

ll EEA(ll a, ll b, ll &x, ll &y){
    if (b==0){x = 1; y = 0; return a;}
    ll g = eea(b, a%b, x, y);
    ll z = x - a/b*y;
    x = y; y = z; return g;
}

ll modinv(ll a, ll m) { 
    ll x, y; ll g = extended_euclid(a, m, x, y); 
    if (g == 1 || g == -1) return mod(x * g, m); 
    return 0; // 0 if invalid
}

pair<ll, ll> modsolve(ll a, ll b, ll m){
    ll x, y; ll g = eea(a, m, x, y);
    if (b % g != 0) return {-1, -1};
    return {mod(x*b/g, m/g), abs(m/g)};
}

ll fast_exp(ll b, ll e, ll m){
    ll res = 1;
    while (e > 0){
        if (e & 1) res = mod(res*b, m);
        b = mod(b*b, m);
        e >>= 1;
    }
    return res;
}