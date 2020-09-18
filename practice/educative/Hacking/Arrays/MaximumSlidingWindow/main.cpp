#include <bits/stdc++.h>
using namespace std;


auto maximumSlidingWindowBF(const vector<int>& ary, const int w){
    vector<int> result;
    const int n = ary.size();
    if(n){
        for(int i = 0; i <= n - w; i++)
            result.push_back(*max_element(ary.begin() + i, ary.begin() + i + w));
    }
    return result;
}

auto maximumSlidingWindow(const vector<int>& ary, const int w){
    vector<int> result;
    const int n = ary.size();
    if(n){
        deque<int> window;
        for(int i = 0; i < w; i++){
            while(!window.empty() && ary[window.back()] <= ary[i])
                window.pop_back();
            window.push_back(i);
        }
        result.push_back(ary[window.front()]);
        for(int i = w; i < n; i++){
            while(!window.empty() && ary[window.back()] <= ary[i])
                window.pop_back();
            if(!window.empty() && window.front() <= i - w)
                window.pop_front();
            window.push_back(i);
            result.push_back(ary[window.front()]);
        }
    }
    return result;
}

class Tester{
    mt19937 rng_m;
    uniform_int_distribution<int> dist_m;

    auto testSet(int size){
        vector<int> result(size);
        for(auto& x: result)
            x = dist_m(rng_m);
        return result;
    }

    void print(const string& msg, const vector<int>& ary){
        cout << msg << ": ";
        for(auto x: ary)
            cout << x << ',';
        cout << endl;
    }

    public:
    Tester(int vmin=-9, int vmax=9) : rng_m(chrono::steady_clock::now().time_since_epoch().count()), dist_m(vmin, vmax)
    {}

    Tester& test_b(unsigned int base, unsigned int max_size){
        if(maximumSlidingWindowBF({}, 0) != maximumSlidingWindow({}, 0)){
            cout << "Base test failed {},0 " << endl;
            return *this;
        }
        unsigned int total = 1, cases = base;
        for(unsigned int size = 1; size <= max_size; size++, cases *= base){
            uniform_int_distribution<int> dist(1, size);
            for(unsigned int i = 0; i < cases * size; i++, total++){
                const int window_size = dist(rng_m);
                auto test_set = testSet(size);
                auto bf = maximumSlidingWindowBF(test_set, window_size);
                auto ur = maximumSlidingWindow(test_set, window_size);
                if(bf != ur){
                    print("test_set", test_set);
                    cout << "window_size: " << window_size << endl;
                    print("bf", bf);
                    print("ur", ur);
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
            const int window_size = size ? uniform_int_distribution<int>(1, size)(rng_m) : 0;
            auto test_set = testSet(size);
            auto bf = maximumSlidingWindowBF(test_set, window_size);
            auto ur = maximumSlidingWindow(test_set, window_size);
            if(bf != ur){
                print("test_set", test_set);
                cout << "window_size: " << window_size << endl;
                print("bf", bf);
                print("ur", ur);
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