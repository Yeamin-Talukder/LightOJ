#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"


bool is_valid(ll x , ll y , pair<ll,ll> target , vector<string> &v)
{
    if( x < 0 || x >= v.size() || y < 0 || y >= v.size() || v[x][y] == '#' || (v[x][y] != '.' && make_pair(x,y) != target )) return false;
    return true;
}

ll BFS(pair<ll,ll> node , pair<ll,ll> target , vector<string> &v)
{
    vector<vector<ll>> vis(v.size(),vector<ll>(v.size()));
    vector<vector<ll>> depth(v.size(),vector<ll>(v.size()));

    queue<pair<ll,ll>> q;
    vector<pair<ll,ll>> move = {{1,0} , {-1,0} , {0,1} , {0,-1}};

    q.push(node);
    vis[node.first][node.second] = 1;
    
    while(!q.empty())
    {
        auto [x,y] = q.front(); q.pop();

        for(auto u : move)
        {
            ll i = x + u.first;
            ll j = y + u.second;

            if(is_valid(i,j,target,v) && vis[i][j] == 0) 
            {
                depth[i][j] = depth[x][y] + 1;
                vis[i][j] = 1;
                if( make_pair(i,j) == target) return depth[i][j];
                q.push({i,j});
            }
        }

    }

    return -1;
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {

ll n; cin >> n;
vector<string> v(n); for(auto &u:v) cin>>u;

map<char,pair<ll,ll>> point;

for (ll i = 0; i < n; i++)
{
    for (ll j = 0; j < n; j++)
    {
        if(v[i][j] != '.' && v[i][j] != '#') point[v[i][j]] = {i,j};
    }
}

if(point.size() == 1) {cout << "Case " << c++ << ": " << 0 << endl; continue;}

ll imp = 0;
ll ans = 0;
for (ll i = 1; i < point.size(); i++)
{
   ll dis =  BFS(point['A' + (i-1)] , point['A' + i] , v );
   if(dis == -1) {imp = 1; break;}
    ans += dis;
    
    ll x = point['A' + (i-1)].first;
    ll y = point['A' + (i-1)].second;
    v[x][y] = '.';
}

cout << "Case " << c++ << ": " << ((imp == 1)? "Impossible" : to_string(ans) ) << endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}