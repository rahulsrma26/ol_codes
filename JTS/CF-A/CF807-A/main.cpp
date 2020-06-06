//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : https://codeforces.com/contest/807/problem/A

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
    input(int, b);
    input(int, a);

    if(a != b){
        cout << "rated" << '\n';
    }
    else{
        bool decreasing = true, rated = false;
        for(int i = 1, b1, a1; i < n; i++){
            cin >> b1 >> a1;
            if(b1 != a1){
                rated = true;
                break;
            }
            if(b1 > b)
                decreasing = false;
            b = b1;
        }
        cout << (rated ? "rated" : (decreasing ? "maybe": "unrated")) << '\n';
    }
}