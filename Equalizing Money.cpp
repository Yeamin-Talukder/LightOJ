#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class DFS
{
    public:

    vector<ll> vis;

    DFS(ll n , vector<vector<ll>> &edge)
    {
        vis.resize(n+2);
        ll id = 1;

        for (ll i = 1; i <= n ; i++)
        {
            if(vis[i] == 0) dfs(i,-1,id++,edge);
        }

    }

void dfs(ll node , ll parent , ll id , vector<vector<ll>> &edge)
{
    vis[node] = id;
    
    for(auto child : edge[node])
    {
        if(child !=parent &&  vis[child] == 0)
        {
            dfs(child,node,id,edge);
        }
    }
}

};


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {


ll n,m; cin >> n >> m;
vector<ll> money(n); for(auto &u:money) cin>>u;

vector<vector<ll>> edge(n+1);
for (ll i = 0; i < m; i++)
{
    ll x,y; cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
}

DFS dfs(n,edge);

unordered_map<ll,pair<ll,ll>> store;

for (ll i = 1; i <= n; i++)
{
    store[dfs.vis[i]].first += money[i-1];
    store[dfs.vis[i]].second++;
}

ll found = 0;
set<ll> set;
for(auto [id,pair] : store)
{
    auto [total,count] = pair;
    if(total % count == 0) set.insert(total/count);
    else found = 1;
}

cout << "Case " << c++ << ": " << ((set.size()>1 || found)?"No":"Yes") << endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}