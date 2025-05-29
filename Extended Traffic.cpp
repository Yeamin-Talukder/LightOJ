#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class Bellman_ford
{
    public : 

    vector<ll> dis;
    bool found_negative_cycle = false;

    Bellman_ford(ll n , ll source , vector<tuple<ll,ll,ll>> &edge)
    {
    dis.resize(n + 1 , LLONG_MAX);
    dis[source] = 0; 

        for (ll i = 1; i <= n; i++)
        {
           found_negative_cycle |= relax(edge , i , n);
        }
    }

    bool relax(vector<tuple<ll , ll , ll>> &edge , ll iteration , ll n)
    {
        for(auto [weight , u , v] : edge)
        {
            if(dis[u] != LLONG_MAX && dis[u] + weight < dis[v])
            {
                if(iteration == n) return true;
                dis[v] = dis[u] + weight;
            }
        }
        return false; 
    }

};


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {


ll n; cin >> n;
vector<ll> busy(n); for(auto &u:busy) cin>>u;

vector<tuple<ll,ll,ll>> edge;

ll m; cin >> m;
for (ll i = 0; i <m; i++)
{
    ll x,y; cin >> x >> y;
    edge.push_back({ pow((busy[y-1]-busy[x-1]) , 3) , x , y });
}


Bellman_ford path(n , 1 , edge);


cout << "Case " << c++ << ": " << endl;

ll q; cin >> q;

for (ll i = 0; i < q; i++)
{
    ll node; cin >> node;
    cout << ((path.dis[node] < 3 || path.dis[node] == LLONG_MAX)? "?" : to_string(path.dis[node])) << endl;
}



}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}