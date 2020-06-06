//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : https://codeforces.com/contest/158/problem/A

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int ans(int n, int k, int x){
    for(int i = 1; i < k; i++){
        cin >> x;
        if(x == 0)
            return i;
    }
    for(int i = k, y; i < n; i++){
        cin >> y;
        if(y == 0 || x != y)
            return i;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, x;
    cin >> n >> k >> x;

    cout << (x == 0 ? 0 : ans(n, k, x)) << '\n';
}
// 8 5 10 9 8 7 7 7 5 5