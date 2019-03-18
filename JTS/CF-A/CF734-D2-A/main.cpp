//    Date : 2019-03-12
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/734/problem/A

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin.ignore();
    getline(cin, s);

    int a[4] = {};
    for (char c : s)
        a[c - 'A']++;

    if (a[0] == a[3])
        cout << "Friendship\n";
    else if (a[0] < a[3])
        cout << "Danik\n";
    else
        cout << "Anton\n";
}