//    Date : 2020-06-07
//  Author : Rahul Sharma
// Problem : A. Johnny and Contribution
//     Url : https://codeforces.com/contest/1361/problem/A

#include <bits/stdc++.h>
using namespace std;

#define input(t, v) t v; cin >> v

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input(int, v);
    input(int, e);
    vector<unordered_set<int>> g(v + 1);

    for(int i = 0, a, b; i < e; i++){
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    vector<vector<int>> topics(v + 1);
    vector<int> colors(v + 1);
    for(int i = 1, t; i <= v; i++){
        cin >> t;
        topics[t].push_back(i);
        colors[i] = t;
    }

    vector<int> order;
    vector<bool> visited(v + 1);

    for(int topic = 1; topic <= v; topic++){
        for(auto& blog: topics[topic]){
            set<int> covered;
            for(auto& neighbour: g[blog])
                if(visited[neighbour])
                    covered.insert(colors[neighbour]);
            int uncovered = 1;
            for(auto i : covered){
                if(uncovered != i)
                    break;
                uncovered++;
            }
            if(colors[blog] != uncovered){
                cout << -1;
                return 0;
            }
            order.push_back(blog);
            visited[blog] = true;
        }
    }
    for(auto blog: order)
        cout << blog << ' ';
    cout << '\n';
}