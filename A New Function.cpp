#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll range_sum (ll l , ll r)
{
    l--;
    ll x = (l * (l+1))/2;
    ll y = (r * (r+1))/2;
    return y - x;
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll int t; cin >> t;
while(t--) {


ll n; cin >> n;
ll ans = 0;

ll range = LLONG_MAX;

for (ll i = 2; i <= sqrt(n); i++)
{
    ll x = (n / (i + 1)) + 1;
    ll y = (n/i);
    range = min(range , x );
    ans += (i-1) * range_sum(x , y);
}

if(range != LLONG_MAX) 
{
    for (ll i = 2; i < range; i++)
        {
            ans += ((n / i) - 1) * i;
        }
}

cout << "Case " << c++ << ": " << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}