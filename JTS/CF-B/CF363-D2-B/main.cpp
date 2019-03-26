//    Date : 2019-03-26
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/363/problem/B

#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
class RunningArray {
    std::vector<T> _data;
    size_t _n, _i;
    T _sum;

  public:
    RunningArray(size_t n) : _n(n), _i(0), _sum(0) { _data.reserve(_n); }

    T next(const T& x) {
        if (_data.size() < _n) {
            _data.push_back(x);
            _sum += x;
        } else {
            _sum -= _data[_i];
            _sum += x;
            _data[_i] = x;
            if (++_i == _n)
                _i = 0;
        }
        return _sum;
    }
};

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    RunningArray<int> a(k);
    for (int i = 1, x; i < k; i++, a.next(x))
        cin >> x;

    int m, mi = k;
    cin >> m;
    m = a.next(m);

    for (int i = k + 1, x; i <= n; i++) {
        cin >> x;
        int s = a.next(x);
        if (s < m) {
            m = s;
            mi = i;
        }
    }

    cout << mi - k + 1 << '\n';
}
