//    Date : 2019-03-29
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/714/problem/B

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (find(a.begin(), a.end(), x) == a.end())
            a.push_back(x);
        if (a.size() > 3)
            break;
    }
    sort(a.begin(), a.end());

    cout << (a.size() > 3 || (a.size() == 3 && a[1] - a[0] != a[2] - a[1])
                 ? "NO"
                 : "YES")
         << '\n';
}
