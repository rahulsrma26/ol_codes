#include <iostream>
#include <vector>
using namespace std;

void fun(vector<int>& ary) {
    const auto n = ary.size();
    if (n == 1) {
        cout << ary[0] << '\n';
        return;
    }

    vector<vector<int>> sols(n);
    sols[n - 1].push_back({ary[n - 1]});
    sols[n - 2].push_back({ary[n - 2]});

    vector<int> maxSum(n);
    maxSum[n - 1] = ary[n - 1];
    maxSum[n - 2] = ary[n - 2];

    for (int i = n - 3; i >= 0; i--) {
        if (ary[i] < 0 && (ary[i] < maxSum[i + 1] || ary[i] < maxSum[i + 1])) {
            int maxi = maxSum[i + 1] > maxSum[i + 2] ? 1 : 2;
            if (maxSum[i + 1] == maxSum[i + 2]) {
                int l = min(sols[i + 1].size(), sols[i + 2].size());
                for (int j = 0; j < l; j++) {
                    if (sols[i + 1][j] != sols[i + 2][j]) {
                        maxi = sols[i + 1][j] > sols[i + 2][j] ? 1 : 2;
                        break;
                    }
                }
            }
            maxSum[i] = maxSum[i + maxi];
            sols[i] = sols[i + maxi];
            continue;
        }
        int maxi = 2;
        if (i + 3 < n) {
            maxi = maxSum[i + 2] > maxSum[i + 3] ? 2 : 3;
            if (maxSum[i + 2] == maxSum[i + 3]) {
                int l = min(sols[i + 2].size(), sols[i + 3].size());
                for (int j = 0; j < l; j++) {
                    if (sols[i + 2][j] != sols[i + 3][j]) {
                        maxi = sols[i + 2][j] > sols[i + 3][j] ? 2 : 3;
                        break;
                    }
                }
            }
        }
        if (maxSum[i + maxi] > 0 || maxSum[i + maxi] > ary[i]) {
            maxSum[i] = maxSum[i + maxi];
            sols[i] = sols[i + maxi];
        }
        if (ary[i] > 0 || ary[i] > maxSum[maxi]) {
            maxSum[i] += ary[i];
            sols[i].push_back(ary[i]);
        }
    }
    int maxi = maxSum[0] > maxSum[1] ? 0 : 1;
    if (maxSum[0] == maxSum[1]) {
        int l = min(sols[0].size(), sols[1].size());
        for (int j = 0; j < l; j++) {
            if (sols[0][j] != sols[1][j]) {
                maxi = sols[0][j] > sols[1][j] ? 0 : 1;
                break;
            }
        }
    }
    for (auto& x : sols[maxi])
        cout << x;
    cout << '\n';
}

// struct solution {
//     int sum;
//     int soln;
//     int prev;
// };

// void fun1(vector<int>& ary) {
//     const int n = ary.size();
//     if (n == 1) {
//         cout << ary[0] << '\n';
//         return;
//     }

//     vector<solution> sol(n);
//     sol[n - 1] = solution{ary[n - 1], n - 1, -1};
//     sol[n - 2] = solution{ary[n - 2], n - 2, -1};

//     for (int i = n - 3; i >= 0; i--) {
//         if (ary[i] < 0) {
//             int maxi = sol[i + 1].sum > sol[i + 2].sum ? 1 : 2;
//             if (sol[i + 1].sum == sol[i + 2].sum) {
//                 int l1 = sol[i + 1].soln, l2 = sol[i + 2].soln;
//                 while (l1 >= 0 && l2 >= 0) {
//                     if (ary[l1] != ary[l2]) {
//                         maxi = ary[l1] > ary[l2] ? 1 : 2;
//                         break;
//                     }
//                     l1 = sol[l1].prev;
//                     l2 = sol[l2].prev;
//                 }
//             }
//             sol[i] = sol[i + maxi];
//             continue;
//         }
//         int maxi = 2;
//         if (i + 3 < n) {
//             maxi = sol[i + 2].sum > sol[i + 3].sum ? 2 : 3;
//             if (sol[i + 2].sum == sol[i + 3].sum) {
//                 int l1 = sol[i + 2].soln, l2 = sol[i + 3].soln;
//                 while (l1 >= 0 && l2 >= 0) {
//                     if (ary[l1] != ary[l2]) {
//                         maxi = ary[l1] > ary[l2] ? 2 : 3;
//                         break;
//                     }
//                     l1 = sol[l1].prev;
//                     l2 = sol[l2].prev;
//                 }
//             }
//         }
//         if (sol[i + maxi].sum > 0) {
//             sol[i] = sol[i + maxi];
//             sol[i].sum += ary[i];
//             sol[i + maxi].prev = i;
//         } else {
//             sol[i] = solution{ary[i], i, -1};
//         }
//     }
//     int maxi = sol[0].sum > sol[1].sum ? 0 : 1;
//     if (sol[0].sum == sol[1].sum) {
//         int l1 = sol[0].soln, l2 = sol[1].soln;
//         while (l1 >= 0 && l2 >= 0) {
//             if (ary[l1] != ary[l2]) {
//                 maxi = ary[l1] > ary[l2] ? 0 : 1;
//                 break;
//             }
//             l1 = sol[l1].prev;
//             l2 = sol[l2].prev;
//         }
//     }
//     for (int l = sol[maxi].soln; l >= 0; l = sol[l].prev)
//         cout << ary[l];
//     cout << '\n';
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        fun(a);
    }
}
