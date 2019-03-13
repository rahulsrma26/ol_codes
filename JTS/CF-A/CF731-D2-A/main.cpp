#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int p = 0;

    string s;
    getline(cin, s);

    int r = 0;
    for(auto c: s){
        int i = c - 'a';
        int ccd = (i - p + 26) % 26;
        int cd = (p - i + 26) % 26;
        r += min(cd, ccd);
        p = i;
    }

    cout << r << '\n';
}
