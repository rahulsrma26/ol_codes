#include <bits/stdc++.h>
using namespace std;


int binarySearchBF(const vector<int>& ary, const int x){
    auto result = find(ary.begin(), ary.end(), x);
    return result != ary.end() ? result - ary.begin() : -1;
}

int binarySearch(const vector<int>& ary, const int x){
    if(ary.empty())
        return -1;

    int l = 0, r = ary.size() - 1;
    while(l <= r){
        const int m = l + (r - l) / 2;
        // if(ary[m] == x){
        //     while(m > 0 && ary[m - 1] == x)
        //         m--;
        //     return m;
        // }
        if(x < ary[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return ary[l] == x ? l : -1;
}

class Tester{
    mt19937 rng_m;
    uniform_int_distribution<int> dist_m;

    auto testSet(int size){
        vector<int> result(size);
        for(auto& x: result)
            x = dist_m(rng_m);
        sort(result.begin(), result.end());
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

    Tester& test(unsigned int base, unsigned int max_size){
        if(binarySearchBF({}, 0) != binarySearch({}, 0)){
            cout << "Base test failed {},0 " << endl;
            cout << binarySearchBF({}, 0) << " != " << binarySearch({}, 0) << endl;
            return *this;
        }
        unsigned int total = 1, cases = base;
        for(unsigned int size = 1; size <= max_size; size++, cases *= base){
            uniform_int_distribution<int> dist(1, size);
            for(unsigned int i = 0; i < cases * size; i++, total++){
                const int item = dist_m(rng_m);
                auto test_set = testSet(size);
                auto bf = binarySearchBF(test_set, item);
                auto ur = binarySearch(test_set, item);
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
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // vector<int> a = {-4, 2, -5, 3, 6};
    // for(int x: binarySearch(a, 3))
    //     cout << x << ',';
    // cout << endl;
    // for(int x: binarySearchBF({-8}, 1))
    //     cout << x << ',';
    // cout << endl;

    Tester().test(4, 7);
}