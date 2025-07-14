#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll cal(ll n , ll c , ll t)
{
    return t * (c - (n*t));
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
ll ca = 1;

while(t--) {

ll n,c; cin >> n >> c;

if(n == 0 || c == 0) { cout << "Case " << ca++ << ": " << 0 << endl; continue;}

ll l = 0 , r = c/n;
pair<ll,ll> ans = {LLONG_MIN,0};

while( r - l + 1 >= 3)
{
    ll mid1 = l + (r-l+1)/3;
    ll mid2 = r - (r-l+1)/3;

    ll a = cal(n,c,mid1);
    ll b = cal(n,c,mid2);

    if( a < b ) l = mid1; 
    else  r = mid2;
}

for (ll i = l; i <= r ; i++)
{
    ll x = cal(n,c,i);
    if(ans.first < x) ans = {x , i};
    else if(ans.first == x ) ans.second = min(ans.second , i);
}

cout << "Case " << ca++ << ": " << ans.second << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}