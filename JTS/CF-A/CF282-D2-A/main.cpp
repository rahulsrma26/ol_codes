//    Date : 2019-03-15
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/282/problem/A

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

    cin.ignore();
    int v = 0;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (s[1] == '+')
            v++;
        else
            v--;
    }

    cout << v << '\n';
}
