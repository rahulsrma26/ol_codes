#include <bits/stdc++.h>
using namespace std;

int lower(const vector<int>& ary, const int x){
    int l = 0, r = ary.size() - 1;
    while(l <= r){
        const int m = l + (r - l) / 2;
        if(x <= ary[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return l;
}

int upper(const vector<int>& ary, const int x){
    int l = 0, r = ary.size() - 1;
    while(l <= r){
        const int m = l + (r - l) / 2;
        if(x < ary[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> ary(n);
    for(int& x: ary)
        cin >> x;
    sort(ary.begin(), ary.end());

    int t;
    cin >> t;
    for(int i = 0, l, r; i < t; i++){
        cin >> l >> r;
        cout << upper(ary, r) - lower(ary, l) << ' ';
    }
}