#include <iostream>
#include <numeric>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    int c[26] = {};
    for(auto x: s)
        c[x - 'a'] = 1;

    int r = accumulate(begin(c), end(c), 0);

    cout << (r & 1 ? "IGNORE HIM!" : "CHAT WITH HER!") << '\n';
}