//    Date : 2019-03-12
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/266/problem/A

#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int r = 0;

    char l;
    cin >> l;

    for (int i = 1; i < n; i++){
        char c;
        cin >> c;
        if(c == l)
            r++;
        l = c;
    }

    cout << r << '\n';
}
