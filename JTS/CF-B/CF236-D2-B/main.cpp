//    Date : 2019-09-04
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/236/problem/B

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    const int lim = a * b * c;
    vector<int> divisors(lim + 1, 1);
    for (int i = 2; i <= lim; i++)
        for (int j = i; j <= lim; j += i)
            divisors[j]++;

    int s = 0;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++) {
                s += divisors[i * j * k];
                if (s > 1073741824)
                    s -= 1073741824;
            }

    cout << s << '\n';
}
