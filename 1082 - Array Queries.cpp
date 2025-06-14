#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<ll>save;

void create(ll node,ll begin,ll end,vector<ll>&v)
{
if(begin==end){save[node]=v[begin];return;}
ll mid= (begin+end)/2;
create(node*2,begin,mid,v);
create((node*2)+1,mid+1,end,v);
save[node]=min(save[node*2],save[(node*2)+1]);
}


void cheak(ll node,ll begin,ll end,ll l ,ll r,ll &ans)
{
if(end<l||begin>r)return;
if(l<=begin && end<=r){ans= min(ans,save[node]);return;}
ll mid= (begin+end)/2;
cheak(node*2,begin,mid,l,r,ans);
cheak((node*2)+1,mid+1,end,l,r,ans);
}


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int o; cin >> o;
for (ll t = 1; t <=o ; t++){

ll n,q;cin>>n>>q;
vector<ll>v(n);for(auto &u:v) cin>>u;

save.resize(4*n);
create(1,0,n-1,v);


cout<<"Case "<<t<<":"<<endl;
for (ll i = 0; i < q; i++)
{
    ll l,r;cin>>l>>r;
    ll ans =LLONG_MAX;
    cheak(1,0,n-1,l-1,r-1,ans);
    cout<<ans<<endl;
}


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}