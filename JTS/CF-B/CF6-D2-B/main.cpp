//    Date : 2019-03-26
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/6/problem/B

#include <iostream>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    char p;
    cin >> p;

    char d[128] = {};
    auto check = [&](const string& s) {
        if (m > 1) {
            if (s[0] == p)
                d[s[1]] = 1;
            if (s[m - 1] == p)
                d[s[m - 2]] = 1;
        }
        for (int j = 1; j < m - 1; j++)
            if (s[j] == p)
                d[s[j - 1]] = d[s[j + 1]] = 1;
    };

    string s[2];
    cin >> s[0];
    check(s[0]);
    for (int i = 1; i < n; i++) {
        auto& top = s[1 - (i & 1)];
        auto& bot = s[i & 1];
        cin >> bot;
        check(bot);
        for (int j = 0; j < m; j++)
            if (top[j] == p)
                d[bot[j]] = 1;
            else if (bot[j] == p)
                d[top[j]] = 1;
    }

    int c = 0;
    for (int i = 'A'; i <= 'Z'; i++)
        if (i != p && d[i])
            c++;
    cout << c;
}
