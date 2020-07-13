//    Date : 2019-03-29
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/714/problem/B

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a = -1, b = -1, c = -1, i = 1;
    cin >> a;
    for (int x; i < n; i++) {
        cin >> x;
        if(x != a){
            b = x;
            i++;
            break;
        }
    }
    for (int x; i < n; i++) {
        cin >> x;
        if(x != a && x != b){
            c = x;
            i++;
            break;
        }
    }
    bool possible = true;
    for (int x; i < n; i++) {
        cin >> x;
        if(x != a && x != b && x != c){
            possible = false;
            break;
        }
    }
    if(possible && c != -1){
        if(a > b)
            swap(a, b);
        if(b > c)
            swap(b, c);
        if(a > b)
            swap(a, b);
        if(c - b != b - a)
            possible = false;
    }

    cout << (possible ? "YES" : "NO") << '\n';
}
