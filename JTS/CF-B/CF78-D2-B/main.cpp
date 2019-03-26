//    Date : 2019-03-26
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/78/problem/B

#include <iostream>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    const char* c = "ROYGBIV";
    for (int i = 0; i < n / 7; i++)
        cout << c;

    const int r = n % 7;
    for (int i = 0, s = r < 4 ? 4 - r : 0; i < r; i++, s++)
        cout << c[s];
}

// ROYGBIV
// ROYGBIV G
// ROYGBIV YG
// ROYGBIV OYG
// ROYGBIV ROYG
// ROYGBIV ROYGB
// ROYGBIV ROYGBI
// ROYGBIV ROYGBIV
