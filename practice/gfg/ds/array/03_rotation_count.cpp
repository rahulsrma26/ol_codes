//    Date : 2019-07-11
//  Author : Rahul Sharma
// Problem :
// https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

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

template <class ForwardIterator>
ForwardIterator max_right_rotate(ForwardIterator left, ForwardIterator right) {
    if (left == right)
        return left;
    if (left == right - 1)
        return *left <= *right ? right : left;
    ForwardIterator mid = left + (right - left) / 2;
    // cout << *left << '.' << *mid << '.' << *right << '\n';
    if (*left == *mid && *mid == *right) {
        auto res = max_right_rotate(left, mid);
        if (res != mid)
            return res;
        return max_right_rotate(mid, right);
    } else if (*left > *mid)
        return max_right_rotate(left, mid);
    else
        return max_right_rotate(mid, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //vector<int> ary = {2, 1, 2, 2, 2};
    vector<int> ary = {2, 2, 2, 2, 1, 2};
    print(ary);
    auto max_elem = max_right_rotate(ary.begin(), ary.end() - 1);
    cout << (max_elem - ary.begin() + 1) % ary.size() << '\n';
}
