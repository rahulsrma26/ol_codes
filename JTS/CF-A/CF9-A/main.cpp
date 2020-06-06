//    Date : 2020-06-05
// Problem : http://codeforces.com/contest/9/problem/A

#include <iostream>
#include <algorithm>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int c = 6 - max(a, b) + 1;
    int d = 6;
    if(c % 2 == 0 && d % 2 == 0){
        c /= 2;
        d /= 2;
    }
    if(c % 2 == 0 && d % 2 == 0){
        c /= 2;
        d /= 2;
    }
    if(c % 3 == 0 && d % 3 == 0){
        c /= 3;
        d /= 3;
    }

    cout << c << '/' << d << '\n';
}
