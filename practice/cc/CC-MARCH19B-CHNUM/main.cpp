//    Date : 2019-03-30
//  Author : Rahul Sharma
// Problem : https://www.codechef.com/MARCH19B/problems/CHNUM

#include <iostream>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int pc = 0, nc = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            if (x > 0)
                pc++;
            else
                nc++;
        }

        int min = !nc ? pc : (!pc ? nc : (pc < nc ? pc : nc));
        int max = pc < nc ? nc : pc;

        cout << max << ' ' << min << '\n';
    }
}
