#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class Diameter
{
    public : 

    ll ans = 0;
    vector<ll> save;
    Diameter(ll n , vector<vector<pair<ll,ll>>> &adj)
    {
        save.resize(n+1);
        dfs(0,-1,adj);
    }

ll dfs(ll node, ll parent, vector<vector<pair<ll,ll>>> &adj)
{
    vector<ll> mx;

    for(auto u:adj[node])
    {
        if(u.second != parent)
        {   
            ll x = dfs(u.second,node,adj);
            save[node] = max(save[node],x+u.first); 
            mx.push_back(x+u.first);
        }
    }

    sort(mx.rbegin(),mx.rend());
    ll x = (mx.size() > 0 ?  mx[0]:0) + (mx.size() > 1 ? mx[1] : 0) ;
    ans = max(ans,x);

    return save[node];
}

};


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll int t; cin >> t;
while(t--) {

ll n; cin >> n;

vector<vector<pair<ll,ll>>> adj(n);
for (ll i = 0; i < n-1; i++)
{
    ll x,y,w; cin >> x >> y >> w;
    adj[x].push_back({w,y});
    adj[y].push_back({w,x});
}

Diameter dis(n,adj);

cout << "Case " << c++ << ": " << dis.ans << endl;

}
// Time Complexcity  : O(n) 
// Space Complexcity : O(n) 
}