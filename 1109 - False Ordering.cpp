#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cheak(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    if(a.first == b.first) return a.second>b.second;
    return a.first<b.first;
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);


vector<ll>seive(1e3+1);
for (ll i = 1; i <=1e3; i++)
{
for (ll j = i; j <= 1e3; j+=i)seive[j]++;
}


vector<pair<ll,ll>> ans(1e3+2);


for (ll i = 1; i <1e3+1 ; i++)ans[i]=make_pair(seive[i],i);
sort(ans.begin(), ans.end(),cheak);


ll int t; cin >> t;
for (ll time = 1; time <=t ; time++)
{

ll n; cin>>n;
cout<<"Case "<<time<<": "<<ans[n+1].second<<endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}