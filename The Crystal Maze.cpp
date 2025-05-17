#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class DFS
{
    public : 

    vector<vector<ll>> vis;
    unordered_map<ll,ll> store;
    ll id = 1;
    vector<pair<ll,ll>> move = {{1,0},{-1,0},{0,1},{0,-1}};
    
    DFS(ll m , ll n , vector<string> &grid)
    { 
        vis.resize(m+1,vector<ll>(n+1,0));
        for (ll i = 0; i < m; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if(vis[i][j] == 0 )  {
                    ll count = 0;
                    dfs(i,j,id,count,grid);
                    store[id] = count;
                    id++;
                }
            }
        }

    }

    bool is_valid(ll i , ll j , ll m , ll n)
    {
        if(i < 0 || i >= m  || j < 0 || j >= n) return false;
        else return true;
    }

    void dfs(ll i , ll j , ll id , ll &count , vector<string> &grid)
    {
        vis[i][j] = id;
        if(grid[i][j] == 'C') count++;

        for(auto &u : move)
        {
            ll x = i + u.first;
            ll y = j + u.second;

            if(is_valid(x,y,grid.size(),grid[0].size()) && vis[x][y] == 0 && grid[x][y] != '#')
            {
                dfs(x,y,id,count,grid);
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


ll m,n,q; cin >> m >> n >> q;

vector<string> v(m); for(auto &u:v) cin>>u;
DFS dfs(m,n,v);

cout << "Case " << c++ << ": " << endl;

for (ll i = 0; i < q; i++)
{
    ll x,y; cin >> x >> y;
    ll  id = dfs.vis[x-1][y-1];
    cout << dfs.store[id] << endl;
}



}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}