//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : A. Translation
//     Url : https://codeforces.com/contest/41/problem/A

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

    input(string, a);
    input(string, b);

    bool good = a.length() == b.length();
    if(good){
        const int n = a.length();
        for(int i = n - 1; i >= 0; i--)
            if(a[i] != b[n - i - 1]){
                good = false;
                break;
            }
    }

    cout << (good ? "YES" : "NO") << '\n';
}