#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<double>dp(1e6+9);
for (ll i = 1; i < 1e6+2; i++) dp[i]=dp[i-1]+log10(i);


ll int t; cin >> t;
ll c=1;

while(t--) {

ll a,b; cin>>a>>b;
ll ans = (dp[a]/log10(b))+1;

cout<<"Case "<<c++<<": "<<ans<<endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}