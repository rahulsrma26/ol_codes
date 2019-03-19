//    Date : 2019-03-15
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/208/problem/A

#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);

    regex p("WUB");
    regex w(" +");

    cout << regex_replace(regex_replace(s, p, " "), w, " ");
}
