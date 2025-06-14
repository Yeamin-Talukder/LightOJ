#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

bitset<1000000+9>seive;
vector<ll>prime;
for (ll i = 2; i < 1e6+5; i++)
{
if(seive[i] == 0)
{
prime.push_back(i);
for (ll j = i*i; j < 1e6+5; j+=i)seive[j] =1;
}
}

ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
ll c=1;
while(t--) {

ll a,b,l; cin >> a >> b >> l;

if(l%a!=0 || l%b!=0){cout<<"Case "<<c++<<": "<<"impossible"<<endl;continue;}


map<ll,ll>lc,x,y;

for(auto u:prime)
{
    if(u*u > l && u*u > a && u*u > b)break;
    while(l%u == 0) {lc[u]++;l/=u;}
    while(a%u == 0) {x[u]++;a/=u;}
    while(b%u == 0) {y[u]++;b/=u;}
}

if(l>1)lc[l]++;
if(a>1)x[a]++;
if(b>1)y[b]++;

ll ans=1;
for(auto u:lc)
{
if(x[u.first]!=u.second && y[u.first]!=u.second)
    {
        for (ll i = 0; i < u.second; i++)ans*=u.first;
    }
}

cout<<"Case "<<c++<<": "<<ans<<endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}