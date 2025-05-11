#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"



class dsu
{
    public: 

    vector<ll> parent,size;
    dsu(ll n){
        parent.resize(n+2);
        size.resize(n+2,1);
        for(ll i = 1 ; i <= n ; i++) parent[i] = i;
    }

    ll find(ll x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(ll x , ll y)
    {
        ll a = find(x);
        ll b = find(y);

        if(a != b)
        {
            if(size[a] > size[b]) swap(a,b);
            parent[a] = b;
            size[b] += size[a];
        }

    }

};



int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);


ll c = 1;

ll int t; cin >> t;
while(t--) {

ll n; cin >> n;

vector<vector<ll>> edge;

while(1)
{
    ll x,y,w; cin >> x >> y >> w;
    if(x+y+w == 0) break;

    edge.push_back({w,x,y});
    

}

sort(edge.begin(),edge.end());


dsu con(n),dsu2(n);

ll mn = 0,mx = 0;

for (ll i = 0; i < edge.size(); i++)
{
    ll a = con.find(edge[i][1]);
    ll b = con.find(edge[i][2]);
    if(a != b)  
    {
        mn += edge[i][0];
        con.merge(a,b);
    }
}



sort(edge.rbegin(),edge.rend());

for (ll i = 0; i < edge.size(); i++)
{
    ll a = dsu2.find(edge[i][1]);
    ll b = dsu2.find(edge[i][2]);
    if(a != b)  
    {
        mx += edge[i][0];
        dsu2.merge(a,b);
    }
}

ll sum = mn + mx;

cout << "Case " << c++ << ": ";
if( sum % 2 == 0) cout << sum/2 << endl;
else cout << sum << "/" << 2 << endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}