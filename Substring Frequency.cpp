#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
 
vector<ll> pfx; 
ll prime = 151;
ll mod = 1e9+7;
 
void hash_prefix(string &s)
{
    pfx.push_back(0);
    for (ll i = 1; i <= s.size(); i++)
    {
    pfx.push_back( ( (pfx[i-1] * prime ) + (ll)s[i-1] ) % mod);
    }
}
 
ll get_hash(string &s)
{
    ll val = 0;
    for (ll i = 0; i < s.size(); i++)
    {
    val = ( (val * prime) + (ll)s[i] ) % mod;
    }
    return val;
}
 

 
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);
 
ll t; cin >> t; 
ll c = 1;
while(t--)
{
    
string a,b; cin >> a >> b;

if(b.size() > a.size()) {cout << "Case " << c++ << ": " << 0 << endl; return 0;}
 
hash_prefix(a);
ll hash = get_hash(b);
 
ll size = b.size();
ll pow = 1;
ll count = 0;
 
for (ll i = 0; i < size; i++) pow = (pow * prime) % mod;
 
for (ll i = 0; i < a.size()-b.size()+1; i++)
{
if(hash == ( ( mod + pfx[i+size] - ( (pfx[i] * pow) % mod ) ) ) % mod )  count++;
}
 
cout << "Case " << c++ << ": " << count << endl;
 
pfx.clear();


}

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
