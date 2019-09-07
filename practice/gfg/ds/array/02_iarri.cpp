//    Date : 2019-07-11
//  Author : Rahul Sharma
// Problem :
// https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/
// https://www.geeksforgeeks.org/maximum-sum-iarri-among-rotations-given-array/

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

/*
R0 =          0*A0 + 1*A1 + 2*A2 + ... + (n-1)*An-1
R1 = 0*An-1 + 1*A0 + 2*A2 + 3*A2 + ... + (n-1)*An-2
R1 - R0 = A0 + A1 + A2 + ... + An-2 - (n-1)*An-1
*/
template <class T>
T maxisum_right(const vector<T>& ary) {
    const int n = ary.size();
    T sum = 0, isum = 0;
    for (int i = 0; i < n; i++)
        sum += ary[i], isum += i * ary[i];
    T msum = isum;
    for (int i = 1; i < n; i++)
        msum = max(msum, isum += sum - n * ary[n - i]);
    return msum;
}

/*
R0 = 0*A0 + 1*A1 + 2*A2 + ... + (n-1)*An-1
R1 =        0*A1 + 1*A2 + ... + (n-2)*An-1 + (n-1)*A0
R1 - R0 = (n-1)*A0 - (A1 + A2 + ... + An-1)
*/
template <class T>
T maxisum_left(const vector<T>& ary) {
    const int n = ary.size();
    T sum = 0, isum = 0;
    for (int i = 0; i < n; i++)
        sum += ary[i], isum += i * ary[i];
    T msum = isum;
    for (int i = 0; i < n - 1; i++)
        msum = max(msum, isum += n * ary[i] - sum);
    return msum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> ary = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(ary);
    cout << maxisum_right(ary) << '\n';

    ary = {8, 3, 1, 2};
    print(ary);
    cout << maxisum_left(ary) << '\n';
}
