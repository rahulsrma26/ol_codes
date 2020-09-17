#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    double r = 0;
    for (int i = 1; i <= n; i++)
        r += 1 / (double)(i);

    cout << fixed << setprecision(6) << r << endl;
}