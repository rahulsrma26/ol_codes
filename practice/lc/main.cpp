#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) const{
        if(!s.length())
            return true;
        const int n = s.length();
        if(n == 1)
            return false;
        int t = 1;
        cout << 'n' << n << ' ';
        cout << 't' << t << ' ';
        for(int i = 1; i < n; i++){
            if(s[i] == ')' || s[i] == '}' || s[i] == '}'){
                if(!t || s[i] < s[t - 1] || s[i] - s[t - 1] > 2)
                    return false;
                t--;
            }
            else
                s[t++] = s[i];
            cout << 't' << t << ' ';
        }
        return !t;
    }
};

int main(){
    Solution s;
    cout << s.isValid("(){}[]") << endl;
}