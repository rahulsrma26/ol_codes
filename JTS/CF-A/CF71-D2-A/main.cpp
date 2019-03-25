//    Date : 2019-03-14
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/71/problem/A

#include <iostream>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int l = s.length();
        if(l > 10)
            s = s[0] + to_string(l - 2) + s[l-1];
        cout << s << '\n';
    }
}
