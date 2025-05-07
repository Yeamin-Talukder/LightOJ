#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
for (ll c = 1; c <=t ; c++){
cout<<"Case "<<c<<": ";

ll p,l;cin >> p>>l;
if((p-l)<=l){cout<<"impossible"<<endl;continue;}

vector<ll>v;
ll n = p-l;
for (ll i = 1; i*i <= n; i++)
{
if(n%i==0 && i>l)v.push_back(i);
if(n%i==0 && (n/i)>l && i!=n/i)v.push_back(n/i);

}
sort(v.begin(),v.end());
for(auto u:v) cout<<u<< " ";
cout << endl;



}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}