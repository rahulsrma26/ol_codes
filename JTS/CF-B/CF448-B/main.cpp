//    Date : 2020-07-14
//  Author : Rahul Sharma
// Problem : Suffix Structures
//     Url : https://codeforces.com/contest/448/problem/B

#include <bits/stdc++.h>
using namespace std;

auto possible(const string& a, const string& b){
    for(size_t i = 0, j = 0; i < a.size(); i++)
        if(a[i] == b[j])
            if(++j == b.size())
                return true;
    return false;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;

    if(a.size() < b.size()){
        cout << "need tree" << '\n';
    }
    else if(possible(a, b)){
        cout << "automaton" << '\n';
    }
    else{
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b)
            cout << "array" << '\n';
        else if(possible(a, b))
            cout << "both" << '\n';
        else
            cout << "need tree" << '\n';
    }
}