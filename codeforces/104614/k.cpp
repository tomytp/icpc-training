#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

bool is_digit(char c){
    return (c >= '0') and (c <= '9');
}

ll build (string s, map<ll, v64> &tree){
    bool in_number = true, finish_number = false;
    ll num = 0, root;
    stack<ll> pilha;
    forn(i, 0, s.size()){
        char c = s[i];
        if(in_number and !is_digit(c)){
            in_number = false;
            finish_number = true;
        }
        if(!in_number and is_digit(c)) in_number = true;
        if(in_number) num = 10*num + (c - '0');

        if(finish_number){
            finish_number = false;
            if(pilha.empty()) root = num, debug(root);
            else tree[pilha.top()].push_back(num);

            pilha.push(num);
            num = 0;
        }

        if(c == ')'){
            ll aux = pilha.top();
            if(tree.count(aux)!=0){
                sort(tree[aux].begin(), tree[aux].end());
            }
            pilha.pop();
        }
    }

    if (num != 0) {
        return num;
    }

    sort(tree[root].begin(), tree[root].end());
    return root;
}

bool dfs(ll root1, ll root2, map<ll, v64> &tree1, map<ll, v64> &tree2){
    if(root1 != root2) return false;
    if(tree1[root1].size() != tree2[root2].size()) return false;
    ll sz = tree1[root1].size();
    forn(i, 0, sz){
        debug(tree1[root1].size());
        debug(tree2[root2].size());
        debug(i);
        if(!dfs(tree1[root1][i], tree2[root2][i], tree1, tree2)) return false;
    }
    return true;
}

int main(){
    _; string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    map<ll, v64> tree1, tree2;
    ll r1 = build(s1, tree1);
    ll r2 = build(s2, tree2);

    // for(auto x : tree1){
    //     cout << x.first << ": ";
    //     for(auto y : x.second) cout << y << " ";
    //     cout << ln;
    // }

    // cout << ln;

    // for(auto x : tree2){
    //     cout << x.first << ": ";
    //     for(auto y : x.second) cout << y << " ";
    //     cout << ln;
    // }

    cout << ((tree1 == tree2 && r1 == r2) ? "Yes\n" : "No\n");

    return 0;
}