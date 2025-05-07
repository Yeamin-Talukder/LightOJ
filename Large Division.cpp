#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
ll c=1;
while(t--) {

string a;cin>>a;
ll b;cin>>b;

ll ans = 0;

for (ll i = 0; i < a.size(); i++)
{
if(a[i] == '-')continue;
ans=(ans*10+(a[i]-'0'))%b;
}
cout<<"Case "<<c++<<": "<<((ans==0)?"divisible":"not divisible")<<endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}