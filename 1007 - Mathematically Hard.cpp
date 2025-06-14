#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

const ll size =5e6;
ll seive[size+9];

for (ll i = 1; i < size+5; i++)seive[i]=i;

for (ll i = 2; i < size+2; i++)
{

if(seive[i] ==i)
{
for (ll j = i; j < size+2; j+=i){seive[j]-=seive[j]/i;}
}

seive[i]*=seive[i];
seive[i]+=seive[i-1];

}

ll int t; cin >> t;
ll c =1;
while(t--) {

ll a,b;cin>>a>>b;

cout<<"Case "<<c++<<": " << seive[b]-seive[a-1] <<endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}