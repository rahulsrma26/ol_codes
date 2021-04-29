#include <bits/stdc++.h>
using namespace std;

vector<int> BF(vector<int> arr, int n, int k) {
    // cout << n << ',' << k << '\n';
    if(k < 1)
        return {};
    if(n < 1)
        return vector<int>(k, 0);
    int total = accumulate(arr.begin(), arr.end(), 0);
    if(k == 1)
        return { total };

    int extra = 0;
    if(k > n){
        extra = k - n;
        k = n;
    }

    vector<int> ans;
    int s = 0, best = total + 1, bestP = 0;
    for(int i = 0; i <= n - k; i++) {
        s += arr[i];
        auto res = BF(vector<int>(arr.begin() + i + 1, arr.end()), n - i - 1, k - 1);
        if(max(s, res.back()) < best) {
            ans = res;
            best = max(s, res.back());
            bestP = s;
        }
    }
    ans.push_back(bestP);
    for(int i = 0; i < extra; i++)
        ans.push_back(0);
    sort(ans.begin(), ans.end());
    return ans;
}

vector<int> bottomup(vector<int> arr, int n, int k) {
    if(k < 1)
        return {};
    if(n < 1)
        return vector<int>(k, 0);
    int total = accumulate(arr.begin(), arr.end(), 0);
    if(k == 1)
        return { total };

    int extra = 0;
    if(k > n){
        extra = k - n;
        k = n;
    }

    vector<vector<int>> bst(k + 1, vector<int>(n + 1, 0));
    vector<vector<int>> idx(k + 1, vector<int>(n + 1, 0));

    for(int j = n - 1; j >= 0; j--) {
        bst[1][j] = arr[j] + bst[1][j + 1];
        idx[1][j] = n - 1;
    }

    for(int i = 2; i <= k; i++) {
        for(int j = n - i; j >= 0; j--){
            int best = total + 1, split = 0, sum = 0;
            for(int l = j; l <= n - i; l++){
                sum += arr[l];
                int value = max(bst[i - 1][l + 1], sum);
                if(value < best){
                    best = value;
                    split = l;
                }
            }
            bst[i][j] = best;
            idx[i][j] = split;
        }
    }

    // cout << "Best: \n";
    // for(auto& row: bst) { for(auto& val: row) cout << val << '\t'; cout << '\n'; }
    // cout << "Index: \n";
    // for(auto& row: idx) { for(auto& val: row) cout << val << '\t'; cout << '\n'; }
    vector<int> ans;
    for(int i = k, j = 0; i > 0; i--) {
        int sum = 0;
        for(int l = j; l <= idx[i][j]; l++)
            sum += arr[l];
        ans.push_back(sum);
        j = idx[i][j] + 1;
    }
    for(int i = 0; i < extra; i++)
        ans.push_back(0);
    sort(ans.begin(), ans.end());
    return ans;
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
    Tester(int vmin=0, int vmax=9) : rng_m(chrono::steady_clock::now().time_since_epoch().count()), dist_m(vmin, vmax)
    {}

    Tester& test_b(unsigned int base, unsigned int max_size){
        if(BF({}, 0, 0) != bottomup({}, 0, 0)){
            cout << "Base test failed {},0,0 " << endl;
            return *this;
        }
        unsigned int total = 1, cases = base;
        for(unsigned int size = 1; size <= max_size; size++, cases *= base){
            uniform_int_distribution<int> dist(1, size);
            for(unsigned int i = 0; i < cases * size; i++, total++){
                const int nurses = dist(rng_m);
                auto test_set = testSet(size);
                auto bf = BF(test_set, size, nurses);
                auto ur = bottomup(test_set, size, nurses);
                if(bf != ur){
                    print("test_set", test_set);
                    cout << "nurses: " << nurses << endl;
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
            const int nurses = size ? uniform_int_distribution<int>(1, size)(rng_m) : 0;
            auto test_set = testSet(size);
            auto bf = BF(test_set, size, nurses);
            auto ur = bottomup(test_set, size, nurses);
            if(bf != ur){
                print("test_set", test_set);
                cout << "nurses: " << nurses << endl;
                print("bf", bf);
                print("ur", ur);
                return *this;
            }
        }
        cout << "All passed: " << cases << '\n';
        return *this;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Tester().test_b(5, 7).test_r(100'000);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto& x: arr)
        cin >> x;

    // // int n = 5, k = 3;
    // // vector<int> arr = {5, 10, 30, 20, 15};

    for(auto x: bottomup(arr, n, k))
        cout << x << '\n';
}