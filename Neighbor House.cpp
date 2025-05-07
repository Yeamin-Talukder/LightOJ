#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll> > dp(100,vector<ll> (100));
ll traverse(vector<vector<ll> > &v , ll l , ll r)
{
   if(l < 0 || r < 0 || r >=3 || l >=v.size() ) return 0;

   if(dp[l][r] != 0) return dp[l][r];
   if(l == v.size() - 1) return dp[l][r] = v[l][r];

   ll x =LLONG_MAX;
   ll y = LLONG_MAX;
   ll z = LLONG_MAX;
   if(r != 0)  x = traverse(v, l+1, 0);
   if(r!= 1 ) y = traverse(v, l+1 , 1);
   if(r!= 2 )  z = traverse(v, l+1, 2);

   return dp[l][r] = v[l][r] + min(x,min(y,z));

}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {

ll n; cin >> n;

vector<vector<ll>>v(n , vector<ll>(3));
for(auto &u : v) { for(auto &x : u) cin >> x; }

traverse(v, 0, 0);
traverse(v,0,1);
traverse(v,0,2);

ll ans = min(dp[0][0] , min( dp[0][1] , dp[0][2] ) );

cout <<"Case " << c++ <<  ": " <<  ans << endl;

dp.assign(100,vector<ll>(100,0));

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}