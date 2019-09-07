//    Date : 2019-07-11
//  Author : Rahul Sharma
// Problem : https://www.geeksforgeeks.org/array-rotation/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void print(const vector<T>& ary) {
    cout << '{';
    for (const auto& x : ary)
        cout << ' ' << x << ',';
    cout << "\b }\n";
}

template <class T>
void rotate_left(vector<T>& ary, size_t offset) {
    offset %= ary.size();
    std::reverse(ary.begin(), ary.begin() + offset);
    std::reverse(ary.begin() + offset, ary.end());
    std::reverse(ary.begin(), ary.end());
}

template <class T>
void rotate_right(vector<T>& ary, size_t offset) {
    offset %= ary.size();
    std::reverse(ary.begin(), ary.end());
    std::reverse(ary.begin(), ary.begin() + offset);
    std::reverse(ary.begin() + offset, ary.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> ary = {1, 2, 3, 4, 5};
    print(ary);
    rotate_left(ary, 2);
    // std::rotate(ary.begin(), ary.begin() + 2, ary.end());
    print(ary);
    rotate_right(ary, 2);
    // std::rotate(ary.rbegin(), ary.rbegin() + 2, ary.rend());
    print(ary);
}
