//    Date : 2019-04-08
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/144/problem/B

#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto split(string s) {
    vector<string> a;
    string w;
    for (char c : s)
        if (c == ' ')
            a.push_back(w), w = "";
        else
            w += c;
    if (w != "")
        a.push_back(w);
    return a;
}

auto removeDup(string s) {
    string w;
    for (char c : s)
        if (w.find(c) == string::npos)
            w += c;
    return w;
}

int main() {
    string s;
    getline(cin, s);

    for (auto w : split(s))
        cout << removeDup(w) << ' ';
}
