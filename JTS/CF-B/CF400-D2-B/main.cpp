//    Date : 2019-03-29
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/400/problem/B

#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    auto diff = [&]() {
        string l;
        cin >> l;
        int g, s;
        for (int i = 0; i < m; i++)
            if (l[i] == 'G')
                g = i;
            else if (l[i] == 'S')
                s = i;
        return s - g;
    };

    vector<int> a(m);
    for (int i = 0, d; i < n; i++) {
        if ((d = diff()) < 0) {
            a[0] = -1;
            break;
        }
        a[d] = 1;
    }

    if (!a[0])
        for (int i = 1; i < m; i++)
            a[0] += a[i];

    cout << a[0] << '\n';
}
