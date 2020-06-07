//    Date : 2020-06-07
//  Author : Rahul Sharma
// Problem : A. Shell Game
//     Url : https://codeforces.com/contest/777/problem/A

#include <bits/stdc++.h>
using namespace std;

#define input(t, v) t v; cin >> v

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input(int, n);
    input(int, x);
    // const int ans[3][6] = {
    //     {0, 1, 2, 2, 1, 0},
    //     {1, 0, 0, 1, 2, 2},
    //     {2, 2, 1, 0, 0, 1},
    // };
    // const int k = n % 6;
    // for(int i = 0; i < 3; i++)
    //     if(ans[i][k] == x)
    //         cout << i << '\n';
    n = n % 6;
    if(n % 2 == 0)
        cout << (n / 2 + x) % 3 << '\n';
    else
        cout << ((n+1)/2 - x + 3) % 3 << '\n';
}
