#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"


unordered_map<ll,bool> vis;
ll even = 0, odd = 0;

void dfs (unordered_map<ll,vector<ll>> &edge,ll root, ll parent , bool cheak)
{
    vis[root] = 1;
    if(cheak % 2 == 0) even++;
    else odd++;

    for(auto u:edge[root]) if(u != parent  && !vis[u] ) dfs(edge,u,root,cheak^1);
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {

ll n; cin >> n;
unordered_map<ll,vector<ll>> edge;

for (ll i = 0; i < n; i++)
{
    ll x,y; cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
}

ll ans = 0;

for(auto &u:edge)
{
    if(vis[u.first] == 0)
    {
        dfs(edge,u.first,-1,0);
        ans += max(even,odd);
        even = 0; odd = 0;
    }
}   

cout << "Case " << c++ << ": " << ans << endl;

vis.clear();

}
// Time Complexcity  : O(n) 
// Space Complexcity : O(n) 
}