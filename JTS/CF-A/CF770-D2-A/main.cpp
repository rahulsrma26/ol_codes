//    Date : 2019-03-14
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/770/problem/A

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++)
        cout << (char)('a' + i%k);
    cout << '\n';
}
