//    Date : 2019-03-14
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/339/problem/A

#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);

    int a[3] = {};
    for(char c: s)
        if('1' <= c && c <= '3')
            a[c - '1']++;

    for(int i=0, k=0; i<3; i++)
        for(int j=0; j<a[i]; j++, k+=2)
            s[k] = '1' + i;

    cout << s << '\n';
}
