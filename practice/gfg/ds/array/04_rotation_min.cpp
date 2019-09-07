//    Date : 2019-07-11
//  Author : Rahul Sharma
// Problem :
// https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/

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
ForwardIterator min_right_rotate(ForwardIterator left, ForwardIterator right) {
    if (left == right)
        return left;
    if (left == right - 1)
        return *left <= *right ? left : right;
    ForwardIterator mid = left + (right - left) / 2;
    if (*left > *mid)
        return min_right_rotate(left, mid);
    else if (*mid > *right)
        return min_right_rotate(mid, right);
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> ary = {1, 2, 3, 4, 5};
    print(ary);
    cout << *min_right_rotate(ary.begin(), ary.end() - 1) << '\n';

    ary = {4, 5, 1, 2, 3};
    print(ary);
    cout << *min_right_rotate(ary.begin(), ary.end() - 1) << '\n';
}
