//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : A. Case of the Zeros and Ones
//     Url : https://codeforces.com/contest/556/problem/A

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
    input(string, s);

    int stk = 0;
    for(auto c: s){
        if(c == '1')
            stk++;
        else
            stk--;
    }

    cout << abs(stk) << '\n';
}