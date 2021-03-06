//    Date : 2019-03-27
//  Author : Rahul Sharma
// Problem : https://www.spoj.com/problems/TOE1/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (vector<string> m(3); n; n--) {
        cin.ignore();
        for (auto& r : m)
            getline(cin, r);
        cout << (is_ttt(m) ? "yes" : "no") << '\n';
    }
}
