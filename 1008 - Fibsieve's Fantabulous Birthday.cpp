#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

pair<ll , ll > position(ll n , ll square , ll val)
{
    ll gap = square - n;
    if(gap < val) return {val , gap+1};
    else return {val - (gap-val+1)  , val};
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {

ll n; cin >> n;

ll square = ceil(sqrt(n));
ll val = square;
square = square * square;

if(square == n ) 
{
    cout << "Case " << c++ << ": "; 
    if((ll)sqrt(n) % 2 == 0) cout << sqrt(n) << " " << 1 << endl;
    else cout << 1 << " " << sqrt(n) << endl;
    continue;
}

pair<ll,ll> ans = position(n , square , val);

if(val % 2 == 0 )cout << "Case " << c++ << ": " << ans.first << " " << ans.second << endl;
else cout << "Case " << c++ << ": " << ans.second << " " << ans.first << endl; 

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}