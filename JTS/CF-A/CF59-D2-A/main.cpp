//    Date : 2019-03-12
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/59/problem/A

#include <algorithm>
#include <iostream>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    int lc = 0;
    for (auto c : s)
        lc += c < 'a' ? -1 : 1;

    transform(s.begin(), s.end(), s.begin(),
              (lc >= 0 ? ::tolower : ::toupper));
    cout << s << '\n';
}
