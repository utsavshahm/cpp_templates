#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M = 1e9 + 7;
const int N = 2e5 + 5;
ll fact[N];

ll power(ll a, ll x){
    ll ans = 1;
    while (x){
        if (x & 1)
            ans = (ans * a) % M;
        a = (a * a) % M;
        x >>= 1;
    }
    return ans;
}

void preprocess(){
    fact[0] = 1;
    for (int i = 1; i < N; ++i){
        fact[i] = (fact[i - 1] * i) % M;
    }
}

ll nCr(ll n, ll r){
    if (n < r)
        return 0LL;
    ll num = fact[n];
    ll den = (fact[n - r] * fact[r]) % M;

    ll res = (num * power(den, M - 2)) % M;

    return res;
}
