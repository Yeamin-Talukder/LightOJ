#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 10000007;
int dp[10000+9];

ll cheak(ll n,ll a, ll b, ll c, ll d, ll e,ll f)
{
    if(dp[n]!=-1)return dp[n]%mod;
    if(n==0)return a%mod;
    if(n==1)return b%mod;
    if(n==2)return c%mod;
    if(n==3)return d%mod;
    if(n==4)return e%mod;
    if(n==5)return f%mod;

    dp[n]=(cheak(n-1,a,b,c,d,e,f)%mod+cheak(n-2,a,b,c,d,e,f)%mod+cheak(n-3,a,b,c,d,e,f)%mod+cheak(n-4,a,b,c,d,e,f)%mod+cheak(n-5,a,b,c,d,e,f)%mod+cheak(n-6,a,b,c,d,e,f)%mod)%mod;
   
    return dp[n];
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
ll Case =1;
while(t--) {
for (ll i = 0; i < 10000+9; i++)dp[i]=-1;


ll a,b,c,d,e,f,n; cin>>a>>b>>c>>d>>e>>f>>n;
cout<<"Case "<<Case<<": "<<cheak(n,a,b,c,d,e,f)<<endl;
Case++;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}