void primeSieve(){
    vector<bool> isPrime;
    vector<int> numFact;
    ll n;

    isPrime.resize(n, true);
    numFact.resize(n);

    isPrime[0] = isPrime[1] = false;
    for (ll i=2; i<n; i++){
        if (isPrime[i]){
            numFact[i] = 1;
            for (ll j=2*i; j<n; j+=i){
                isPrime[j] = false;
                numFact[j]++;
            }
        }
    }
}