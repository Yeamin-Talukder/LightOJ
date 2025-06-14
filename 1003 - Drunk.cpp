#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<ll> vis,in_stack;
 void dfs(ll node , vector<vector<ll>> &edge , ll &found)
 {
    vis[node] = 1;
    in_stack[node] = 1;

    for(auto child : edge[node])
    {
        if(in_stack[child] == 1) found = 1;
        if(found == 1) return;
        if(vis[child] == 0) dfs(child,edge,found);
    }
    in_stack[node] = 0;
 }

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {

ll m; cin >> m;

vector<vector<ll>> edge(m*2+1);

ll id = 1;
unordered_map<string,ll> cheak;

for (ll i = 0; i < m; i++)
{
    string a,b; cin >> a >> b;
    if(cheak[a] == 0) cheak[a] = id++;
    if(cheak[b] == 0) cheak[b] = id++;
    edge[cheak[a]].push_back(cheak[b]);
}

vis.assign(id+1,0);
in_stack.assign(id+1,0);

ll found = 0;
for(auto u:cheak)
{
    if(vis[u.second] == 0) dfs(u.second,edge,found);
    if(found == 1) break;
}

cout << "Case " << c++ << ": " << ((found == 0)? "Yes" : "No") << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}