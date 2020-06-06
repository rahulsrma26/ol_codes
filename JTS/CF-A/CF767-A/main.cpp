//    Date : 2020-06-05
//  Author : Rahul Sharma
// Problem : http://codeforces.com/problemset/problem/767/A

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string a(n + 1, 0);

    for(int i = 0, x, j = n; i < n; i++){
        cin >> x;
        a[x] = 1;
        if(x == j){
            for(; a[j]; j--)
                cout << j << ' ';
            cout << '\n';
        }
        else{
            cout << ' ' << '\n';
        }
    }
}
