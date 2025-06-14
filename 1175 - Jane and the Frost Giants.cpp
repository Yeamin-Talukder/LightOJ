#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"

class multi_source_BFS
{
    public : 

    vector<vector<ll>> vis,vis2;
    vector<pair<ll,ll>> move = {{1,0},{-1,0},{0,1},{0,-1}};

    ll ans = 0;

    multi_source_BFS(vector<string> &grid)
    {
        vis.resize(grid.size()+1,vector<ll>(grid[0].size()+1 , -1));
        vis2.resize(grid.size()+1,vector<ll>(grid[0].size()+1 , -1));

        queue<pair<ll,ll>> q;
        pair<ll,ll> source = {0,0};

        for (ll i = 0; i < grid.size(); i++)
        {
            for (ll j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 'F'){ q.push({i,j}); vis[i][j] = 0;}
                else if(grid[i][j] == 'J') source = {i,j};
            }
        }

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            for(auto [i,j] : move)
            {
                ll a = x + i;
                ll b = y + j;
                if(is_valid(a,b,grid) && vis[a][b] == -1 && grid[a][b] != '#') 
                {
                    vis[a][b] = vis[x][y]+1;
                    q.push({a,b});
                }
            }
        }

            queue<pair<ll,ll>> track;
            vis2[source.first][source.second] = 0;

            track.push( {source.first ,  source.second  } );

            while(!track.empty())
            {
                auto [x,y] = track.front();
                track.pop();
                for(auto [i,j] : move)
                {
                    ll a = x + i;
                    ll b = y + j;
                    if( is_valid(a,b,grid) == 0 ) {ans = vis2[x][y] + 1; break; }
                    else if( is_valid(a,b,grid) && grid[a][b] != '#' && vis2[a][b] == -1 && vis[a][b] > vis2[x][y] + 1) {
                        
                        vis2[a][b] = vis2[x][y] + 1;	
                        track.push({a,b});
                    }
                }

                if(ans != 0) break;
            }
    }

    bool is_valid(ll x , ll y ,  vector<string> &grid)
    {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ) return 0;
        else return 1;
    }

};

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll ca = 1;

ll t; cin >> t;
while(t--) {

ll r,c; cin >> r >> c;

vector<string> grid(r); for(auto &u:grid) cin>>u;
multi_source_BFS path(grid);

cout << "Case " << ca++ << ": " << ((path.ans == 0)?  "IMPOSSIBLE" : to_string(path.ans)) << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}