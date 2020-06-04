#include <bits/stdc++.h>
using namespace std;

// 11 - 11
//  5 - 5, 16
//  6 - 6, (11), 22
//  2 - 2, 8, 13, 24
//  8 - (8), 10, (16), 21, 32
// 10 - (10), 18, 20, 26, 31, 42

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& x: a)
        cin >> x;

    map<int, int> g = {{a[0], 1}};
    vector<map<int, int>> d;
    d.push_back(g);

    for(int i = 1; i < n; i++){
        map<int, int> c;
        for(int j = i, s = 0; j > 0; j--){
            s += a[j];
            auto r = d[j - 1].find(s);
            if(r != d[j - 1].end())
            {}
        }
        // for(int j = ; j < i; j++)
    }
}