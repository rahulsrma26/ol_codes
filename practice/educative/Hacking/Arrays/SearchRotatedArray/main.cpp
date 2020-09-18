#include <bits/stdc++.h>
using namespace std;


int searchRotatedArrayBF(const vector<int>& ary, const int x){
    auto result = find(ary.begin(), ary.end(), x);
    return result != ary.end() ? result - ary.begin() : -1;
}

int searchRotatedArray(const vector<int>& ary, const int x){
    if(ary.empty())
        return -1;

    int l = 0, r = ary.size() - 1;
    while(l <= r){
        const int m = l + (r - l) / 2;
        if(ary[m] == x)
            return m;
        if(ary[l] < ary[m]){ // left sorted
            if(ary[l] <= x && x <= ary[m])
                r = m - 1;
            else
                l = m + 1;
        }
        else{ // right sorted (one half must be sorted)
            if(ary[m] <= x && x <= ary[r])
                l = m + 1;
            else
                r = m -1;
        }
    }
    return -1;
}

class Tester{
    mt19937 rng_m;

    auto testSet(int size){
        vector<int> result(size);
        if(size){
            int i = 0;
            for(auto& x: result)
                x = i++;
            sort(result.begin(), result.end());
            const int shift = uniform_int_distribution<int>(0, size - 1)(rng_m);
            std::rotate(result.rbegin(), result.rbegin() + shift, result.rend());
        }
        return result;
    }

    void print(const string& msg, const vector<int>& ary){
        cout << msg << ": ";
        for(auto x: ary)
            cout << x << ',';
        cout << endl;
    }

    public:
    Tester() : rng_m(chrono::steady_clock::now().time_since_epoch().count())
    {}

    Tester& test_b(unsigned int base, unsigned int max_size){
        if(searchRotatedArrayBF({}, 0) != searchRotatedArray({}, 0)){
            cout << "Base test failed {},0 " << endl;
            cout << searchRotatedArrayBF({}, 0) << " != " << searchRotatedArray({}, 0) << endl;
            return *this;
        }
        unsigned int total = 1, cases = base;
        for(unsigned int size = 1; size <= max_size; size++, cases *= base){
            uniform_int_distribution<int> dist(1, size);
            for(unsigned int i = 0; i < cases * size; i++, total++){
                const int item = dist(rng_m);
                auto test_set = testSet(size);
                auto bf = searchRotatedArrayBF(test_set, item);
                auto ur = searchRotatedArray(test_set, item);
                if(bf != ur){
                    print("test_set", test_set);
                    cout << "item: " << item << endl;
                    cout << bf << " != " << ur << endl;
                    return *this;
                }
            }
        }
        cout << "All passed: " << total << '\n';
        return *this;
    }

    Tester& test_r(unsigned int cases, unsigned int max_size=6){
        uniform_real_distribution<float> randf(0.0, 1.0);
        for(unsigned int i = 0; i < cases; i++){
            auto r = sqrt(randf(rng_m));
            int size = static_cast<int>(r * max_size);
            // cout << size << ',';
            const int item = size ? uniform_int_distribution<int>(1, size)(rng_m) : 0;
            auto test_set = testSet(size);
            auto bf = searchRotatedArrayBF(test_set, item);
            auto ur = searchRotatedArray(test_set, item);
            if(bf != ur){
                print("test_set", test_set);
                cout << "item: " << item << endl;
                cout << bf << " != " << ur << endl;
                return *this;
            }
        }
        cout << "All passed: " << cases << '\n';
        return *this;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // vector<int> a = {-4, 2, -5, 3, 6};
    // for(int x: maximumSlidingWindow(a, 3))
    //     cout << x << ',';
    // cout << endl;
    // for(int x: maximumSlidingWindowBF({-8}, 1))
    //     cout << x << ',';
    // cout << endl;

    Tester().test_b(3, 7).test_r(10'000);
}