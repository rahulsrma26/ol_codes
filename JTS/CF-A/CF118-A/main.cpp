//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : A. String Task
//     Url : https://codeforces.com/contest/118/problem/A

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define input(t, v) t v; cin >> v

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input(string, s);
    stringstream ss;

    for(auto c: s){
        if('b' <= c && c <= 'z'){
            if(c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y')
                ss << '.' << c;
        }
        else if('B' <= c && c <= 'Z'){
            if(c != 'E' && c != 'I' && c != 'O' && c != 'U' && c != 'Y')
                ss << '.' << (char)(c + 32);
        }
    }

    cout << ss.str() << '\n';
}