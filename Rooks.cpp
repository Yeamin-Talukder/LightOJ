#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);
ll c = 1;

ll int t; cin >> t;
while(t--) {

ll n,k; cin >> n >> k;

 if(k > n ) {cout << "Case " << c++ << ": " << 0 << endl; continue;}

map<ll,ll> map;
for (ll i = 2; i <=k ; i++) map[i] = 1;

ll ans = 1;
ll x = n;

for (ll i = 1; i <= k; i++)
{
    ans *= (x*x);
    x--;
   for(auto &u : map)
   {
      if(ans%u.first == 0 && u.second == 1)  {ans/=u.first; u.second = 0; }
   }

}

 cout << "Case " << c++ << ": " << ans << endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}