//    Date : 2019-03-25
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/102/problem/B

#include <iostream>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int t = 0;
    if(s.length() > 1){
        int d = 0;
        for(auto& c: s)
            d += c -'0';

        for(t++; d > 9; t++){
            int ds = d;
            d = 0;
            for(; ds; ds /= 10)
                d += ds % 10;
        }
    }

    cout << t << '\n';
}
