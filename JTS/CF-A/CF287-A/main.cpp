//    Date : 2020-06-07
//  Author : Rahul Sharma
// Problem : A. IQ Test
//     Url : https://codeforces.com/contest/287/problem/A

#include <bits/stdc++.h>
using namespace std;

#define input(t, v) t v; cin >> v

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string m[4];
    for(auto& s: m)
        cin >> s;

    for(int i = 1; i < 4; i++)
        for(int j = 1; j < 4; j++){
            int h = 0;
            for(int y = 0; y < 2; y++)
                for(int x = 0; x < 2; x++)
                    if(m[i - y][j - x] == '#')
                        h++;
            if(h != 2){
                cout << "YES" << '\n';
                return 0;
            }
        }

    cout << "NO" << '\n';
}