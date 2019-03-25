//    Date : 2019-03-20
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/680/problem/B

#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int c = 0;
    for (auto& x : a) {
        cin >> x;
        c += x;
    }

    for (int l = k - 2, r = k; 0 <= l && r < n; l--, r++)
        if(a[l] + a[r] == 1)
            c--;
    cout << c << '\n';
}
