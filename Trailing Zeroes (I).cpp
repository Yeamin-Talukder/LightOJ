#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

int seive[1000000+9];
vector<ll> prime;
for (ll i = 2; i < 1e6+2; i++)
{
if(seive[i]==0) { prime.push_back(i); for (ll j = i*2; j < 1e6+2; j+=i)seive[j]=1; }
}


ll int t; cin >> t;
ll c=1;
while(t--) {

ll n;cin>>n;
ll ans = 1;

for(auto u:prime)
{
    if(u*u>n)break;
    ll count = 0;
    while(n%u==0){count++;n/=u;}
    ans*=(count+1);
}

if(n>1)ans*=2;
cout<<"Case "<<c++<<": " << ans-1<<endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}