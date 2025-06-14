#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll> > dp(300,vector<ll> (300));

ll traverse(vector<vector<ll> > &v ,ll n, ll l , ll r)
{
   if (l >= 2 * n - 1 || r >= v[l].size() || l<0 || r<0 ) return 0;
    
    if(dp[l][r] != 0) return dp[l][r];
    if(l == (2*n - 2) ) {return dp[l][r] = v[l][r];}

   if(l < n-1)
   {
    ll x = v[l][r] + traverse(v, n , l+1 ,r);
    ll y = v[l][r] + traverse(v, n , l+1 , r+1 );
    dp[l][r] = max(x,y);
   }


   else{
    if(r == 0) dp[l][r] = v[l][r] + traverse(v, n , l+1 ,r);
    else if(r == v[l].size() - 1 )  dp[l][r] = v[l][r] + traverse(v, n , l+1 ,r-1);
    else 
    {
       ll x = v[l][r] +   traverse(v, n, l+1 , r-1);
       ll y = v[l][r] +  traverse(v , n , l+1 , r);
       dp[l][r] = max(x,y);
    }
   }

return dp[l][r];

}


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {

ll n; cin>>n;

vector<vector<ll> > v;

ll cheak = 0;
ll count = 1;

for (ll i = 1; i <= (2*n)-1; i++)
{

vector<ll> tem;
for (ll j = 0; j < count; j++)
{
ll x; cin >> x; 
tem.push_back(x);
}

v.push_back(tem);
if(i<n && cheak == 0)count++;
else {count--; cheak = 1; }

}


traverse(v,n,0,0);

cout <<"Case "<< c++ << ": " <<  dp[0][0] << endl;

dp.assign(300,vector<ll> (300,0));


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}