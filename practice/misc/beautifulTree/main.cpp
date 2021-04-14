#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* parent;
    vector<Node*> children;
    int value;
    int64_t sum;
};

struct Tree{
    vector<Node> nodes;
    explicit Tree(int size): nodes(size + 1){}

    void create(int u, int v){
        nodes[u].children.push_back(&nodes[v]);
    }
};

int X, M = 998244353;
vector<pair<int64_t, int>> numbers{{0,0}};
int64_t beautiful(int k){
    if(k < numbers.size())
        return numbers[k].first;
    int lastDigit = numbers.back();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, x;
    cin >> n >> m >> x;

    Tree tree(n);
    for(int i = 1, u, v; i < n; i++, tree.create(u, v))
        cin >> u >> v;
    for(int i = 0, x; i < n; tree.nodes[i++].value = x)
        cin >> x;


}