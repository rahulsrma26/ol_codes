//    Date : 2019-03-14
//  Auther : Rahul Sharma
// Problem : http://codeforces.com/contest/136/problem/A

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0, x; i < n; a[x-1]=++i)
        cin >> x;

    for(auto x: a)
        cout << x << ' ';
}
