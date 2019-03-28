//    Date : 2019-03-27
//  Author : Rahul Sharma
// Problem : https://www.spoj.com/problems/TOE1/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<string> bs;

void gen(string& b, int m = 9) {
    if (!m) {
        bs.insert(b);
        return;
    }
    char t = (m & 1) ? 'X' : 'O';
    for (int i = 0; i < 9; i++) {
        if (b[i] == '.') {
            b[i] = t;
            bs.insert(b);
            int r = 3 * (i / 3), c = i % 3;
            bool win = (b[r] == t && b[r + 1] == t && b[r + 2] == t) ||
                       (b[c] == t && b[c + 3] == t && b[c + 6] == t) ||
                       (b[0] == t && b[4] == t && b[8] == t) ||
                       (b[2] == t && b[4] == t && b[6] == t);
            if (!win)
                gen(b, m - 1);
            b[i] = '.';
        }
    }
}

bool is_ttt(vector<string> m) {
    int nx = 0, no = 0;
    for (auto& r : m) {
        for (auto& c : r)
            if (c == 'X')
                nx++;
            else if (c == 'O')
                no++;
    }
    if (no < nx - 1 || no > nx)
        return false;
    bool wx = false, wo = false;
    for (int i = 0; i < 3; i++) {
        if (m[i][0] == m[i][1] && m[i][1] == m[i][2]) {
            if (m[i][0] == 'X')
                wx = true;
            else if (m[i][0] == 'O')
                wo = true;
        }
        if (m[0][i] == m[1][i] && m[1][i] == m[2][i]) {
            if (m[0][i] == 'X')
                wx = true;
            else if (m[0][i] == 'O')
                wo = true;
        }
    }
    if (m[0][0] == m[1][1] && m[1][1] == m[2][2]) {
        if (m[1][1] == 'X')
            wx = true;
        else if (m[1][1] == 'O')
            wo = true;
    }
    if (m[2][0] == m[1][1] && m[1][1] == m[0][2]) {
        if (m[1][1] == 'X')
            wx = true;
        else if (m[1][1] == 'O')
            wo = true;
    }
    if ((wx && wo) || (wx && nx != no + 1) || (wo && nx != no))
        return false;
    return true;
}

void test() {
    const char* s = ".XO";
    int comb = pow(3, 9);
    for (int i = 0; i < comb; i++) {
        string b = ".........";
        for (int j = i, k = 0; k < 9; k++, j /= 3)
            b[k] = s[j % 3];
        vector<string> m;
        m.push_back(b.substr(0, 3));
        m.push_back(b.substr(3, 3));
        m.push_back(b.substr(6, 3));
        bool res1 = bs.find(b) != bs.end();
        bool res2 = is_ttt(m);
        if (res1 != res2) {
            cout << b << ' ' << res1 << " != " << res2 << '\n';
            for (auto& r : m)
                cout << r << '\n';
            break;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s(9, '.');
    bs.insert(s);
    gen(s);
    cout << bs.size() << '\n';
    test();
}
