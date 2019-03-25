//    Date : 2019-03-12
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/791/problem/A

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    double ratio = (double)(b) / a;
    cout << ceil((log2(ratio) / log2(1.5)) + 1e-12) << '\n';
}