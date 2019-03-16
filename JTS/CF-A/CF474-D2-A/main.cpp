//    Date : 2019-03-15
//  Auther : Rahul Sharma
// Problem : http://codeforces.com/contest/474/problem/A

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<string> k = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

    string d;
    getline(cin, d);

    int o = d[0] == 'L' ? 0: 1, p = 1 - 2*o;
    char map[128];
    for(const auto& r: k)
        for(int i=o; i<r.size() - 1 + o; i++)
            //cout << r[i] << "=" << r[i+p] << '\n';
            map[(int)r[i]] = r[i+p];

    string s;
    getline(cin, s);

    for(auto& c: s)
        c = map[(int)c];
    cout << s;
}
