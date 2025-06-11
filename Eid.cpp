#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class String_Arithmetic
{
    public : 
     void mul_si(string &a , ll b)
     {
        ll carry = 0;
        ll n = a.size();

        for (ll i = n-1; i >= 0 ; i--)
        {
            ll x = (b * (a[i] - '0')) + carry;
            a[i] = (x % 10) + '0';
            carry = x / 10;
        }
        if(carry > 0) a = to_string(carry) + a;
     }
}; 

ll power(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b & 1) result *= a;        
        a *= a;
        b >>= 1;              
    }
    return result;
}


ll c = 1;
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);


vector<ll> seive(10000+10);
for (ll i = 2; i*i < seive.size(); i++)
{
    if(seive[i] == 0)
    {
         for (ll j = i*2; j < seive.size(); j+=i)
        {
            if(seive[j] == 0) seive[j] = i;
        }
    }
}

ll t; cin >> t;
while(t--) {

ll n; cin >> n;

map<ll,ll> save;

for (ll i = 0; i < n; i++)
{
    ll x; cin >> x;
    unordered_map<ll,ll> tem;
    while(seive[x] != 0)
    {
        tem[seive[x]]++;
        x /= seive[x];
    }
    if(x > 1 && seive[x] == 0) tem[x]++;
    for(auto &u : tem) save[u.first] = max(save[u.first] , u.second);  
}

string ans = "1";
String_Arithmetic op;
for(auto &u : save) op.mul_si(ans,power(u.first,u.second));

cout << "Case " << c++ << ": " << ans << endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}