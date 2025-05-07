#include <bits/stdc++.h>
using namespace std;
#define ll long long

void cal(map<ll,map<ll,ll>>&store ,ll x)
{
ll tem =x;
for (ll i = 2; i*i <=tem && x!=1; i++)
{
while (x%i==0){store[tem][i]++;x/=i;}
}
if(x!=1)store[tem][x]++;
}


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

map<ll,map<ll,ll>>store;

for (ll i = 2; i <= 100; i++)
{
cal(store,i);
for(auto u:store[i-1])store[i][u.first]+=u.second;
}

ll int o; cin >> o;
for (ll t = 1; t<=o; t++)
{

ll n; cin>>n;

cout<<"Case "<<t<<": "<<n<<" = ";
for(auto u:store[n]) {cout<<u.first<< " ("<<u.second<<")";if(store[n].rbegin()->first!=u.first){cout<<" * ";}}
cout << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}