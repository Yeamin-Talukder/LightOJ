#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

 bool is_valid(ll i , ll j , vector<string> &v)
   {
        if(i < 0 || j < 0 || i >= v.size() || j >= v[0].size()) return false;
        else return true;
   }

void BFS(pair<ll,ll> node , vector<string> &v  , vector<vector<ll>> &depth )
{
    queue<pair<ll,ll>> q;
    q.push(node);

    vector<pair<ll,ll>> move = {{1,0},{-1,0},{0,1},{0,-1}};
    map<pair<ll,ll>,ll> vis;

    while(!q.empty())
    {
        auto [i , j] = q.front();
        q.pop();

        if(vis[{i,j}] == 1) continue;
        vis[{i,j}] = 1;

        for(auto u:move)
        {
            
            ll x = i + u.first;
            ll y = j + u.second;
            if(is_valid(x,y,v) && v[x][y] != '#' && v[x][y] != 'm' && vis[{x,y}] == 0) 
            {
                q.push({x,y}); 
                depth[x][y] = depth[i][j] + 1;
            }
        }
    }

}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {


ll m,n; cin >> m >> n;

vector<string> v(m); for(auto &u:v) cin>>u;
vector<vector<ll>> depth(m+1,vector<ll>(n+1,0));

pair<ll,ll> home = {-1,-1};

for (ll i = 0; i < m; i++)
{
    for (ll j = 0; j < n; j++) if(v[i][j] == 'h') {home = {i,j}; break;}
    if(home.first != -1) break;
}

ll ans = 0;

for (ll i = 0; i < m; i++)
{
    for (ll j = 0; j < n; j++)
    {
        if(v[i][j] == 'a' || v[i][j] == 'b' || v[i][j] == 'c') 
        {
            BFS({i,j},v,depth);
            ans = max(ans , depth[home.first][home.second] );
            depth.clear();
            depth.resize(m+1,vector<ll>(n+1,0));
        }
    }
}

cout << "Case " << c++ << ": " << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}