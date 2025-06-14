#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll int t; cin >> t;
while(t--) {

ll n; cin >> n;
unordered_map<ll,ll> track;

ll ans = 0;
for (ll i = 0; i < n; i++)
{
    ll x; cin >> x;
    track[x]++;
    if(track[x] == x+1)
    {
        ans += x+1;
        track.erase(x);
    }
}

for(auto u : track) ans += u.first +1;
cout << "Case " << c++ << ": " << ans << endl; 

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}