//    Date : 2019-03-29
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/26/problem/B

#include <iostream>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string bs;
    cin >> bs;

    int l = 0, s = 0;
    for (char b : bs) {
        if (b == ')' && s)
            s--, l += 2;
        else if (b == '(')
            s++;
    }

    cout << l << '\n';
}
