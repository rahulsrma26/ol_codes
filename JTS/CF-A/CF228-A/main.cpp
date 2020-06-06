//    Date : 2020-06-05
// Problem : http://codeforces.com/contest/228/problem/A

#include <iostream>
#include <unordered_set>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_set<int> s;
    for(int i = 0, x; i < 4; i++){
        cin >> x;
        s.insert(x);
    }

    cout << 4 - s.size() << '\n';
}
