#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
ll c = 1;
while(t--) {

ll n; cin >> n;

ll l = n , r = LLONG_MAX;
ll ans = LLONG_MAX;

while(l <= r)
{
    ll mid = (l + r) / 2;
    ll value = n + (mid / 10); 
    
    if( value < mid) r = mid-1;
    else if( value > mid ) l = mid+1;
    else if ( value == mid ) {ans = min(ans,mid); r = mid-1;}
}

cout << "Case " << c++ << ": ";
for (ll i = ans; i <= ans + 510 ; i++)
{
    if( n + (i/10) == i) cout << i << " ";
}
cout << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}