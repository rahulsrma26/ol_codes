//    Date : 2019-03-18
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/318/problem/A

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using ll=long long;

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll o = (n + 1) / 2;
    cout << (k <= o ? 2*k - 1 : 2*(k-o)) << '\n';
}
