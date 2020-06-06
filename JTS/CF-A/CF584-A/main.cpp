//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : https://codeforces.com/contest/584/problem/A

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define input(t, v) t v; cin >> v

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input(int, n);
    input(int, t);

    if(n == 1){
        cout << (t == 10 ? -1: t);
    }
    else if(t == 10){
        cout << 1;
        for(int i = 1; i < n; i++)
            cout << 0;
    }
    else{
        for(int i = 0; i < n; i++)
            cout << t;
    }
    cout << '\n';
}
