#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void Inclusion_Exclusion(ll n , vector<ll> &v , ll index ,ll size , ll lcm , ll &ans)
{
    if(index == v.size())
    {
        if(size == 0) return;
        if(size % 2 == 0) ans -= (n/lcm);
        else ans += (n/lcm);
        return;
    }

    Inclusion_Exclusion(n , v , index+1 , size , lcm , ans);

    ll x = (lcm * v[index]) / __gcd(lcm , v[index]);
    if(x <= n) Inclusion_Exclusion(n , v , index+1 , size+1 , x , ans );
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll int t; cin >> t;
while(t--) {

ll n,m; cin >> n >> m;

vector<ll> v; 
for (ll i = 0; i < m; i++)
{
    ll x; cin >> x;
    if( x <= n) v.push_back(x);
}

ll ans = 0;
Inclusion_Exclusion(n , v , 0 , 0 , 1 , ans);

cout << "Case " << c++ << ": " << n - ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}