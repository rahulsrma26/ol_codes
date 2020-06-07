//    Date : 2020-06-07
//  Author : Rahul Sharma
// Problem : B. Johnny and Grandmaster
//     Url : https://codeforces.com/contest/1361/problem/B

#include <bits/stdc++.h>
using namespace std;

#define input(t, v) t v; cin >> v
constexpr uint64_t prime1 = 1'000'000'007;
constexpr uint64_t prime2 = 10'000'019;

int modpow(int i, int j, int k) {
    if (j == 0)
        return 1;

    if (i < 2)
        return i;

    int p = 1, v = i;
    while (j) {
        if (j & 1)
            p = ((uint64_t)(p) * v) % k;
        v = ((uint64_t)(v) * v) % k;
        j >>= 1;
    }
    return p;
}

int solve(vector<int>& a, int b){
    sort(a.begin(), a.end(), greater<int>());

    uint64_t v1 = 0, v2 = 0;
    for(auto p: a){
        if(v1 == 0 && v2 == 0){
            v1 = (v1 + modpow(b, p, prime1)) % prime1;
            v2 = (v2 + modpow(b, p, prime2)) % prime2;
        }
        else{
            v1 = (v1 - modpow(b, p, prime1) + prime1) % prime1;
            v2 = (v2 - modpow(b, p, prime2) + prime2) % prime2;
        }
    }
    return v1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input(int, t);
    while(t--){
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        for(auto& x: a)
            cin >> x;
        cout << (p == 1 ? n%2 : solve(a, p)) << '\n';
    }
}