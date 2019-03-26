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
