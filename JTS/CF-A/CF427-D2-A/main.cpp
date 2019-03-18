//    Date : 2019-03-13
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/427/problem/A

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

    int c = 0, r = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if(x > 0)
            r += x;
        else if (r <= 0)
            c++;
        else
            r--;
    }

    cout << c << '\n';
}
