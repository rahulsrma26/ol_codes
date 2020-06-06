//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/768/problem/A

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int ans(vector<int>& a){
    const int n = a.size();
    sort(a.begin(), a.end());
    if(a.front() == a.back())
        return 0;

    int l = 1;
    while(a[l - 1] == a[l])
        l++;
    if(l == n - 1)
        return 0;

    int r = n - 1;
    while(a[r - 1] == a[r])
        r--;

    return r - l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if(n <= 2){
        cout << '0' << '\n';
    }
    else{
        vector<int> a(n);
        for(auto& x: a)
            cin >> x;
        cout << ans(a) << "\n";
    }
}