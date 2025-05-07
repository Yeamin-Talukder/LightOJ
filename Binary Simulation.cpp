#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>save;


void cheak(ll node,ll begin,ll end,ll l ,ll r,ll &ans)
{
if(begin<=l && r<=end){ans+=save[node];}
if(end<l||begin>r )return;
if(begin==end)return;

ll mid= (begin+end)/2;
cheak(node*2,begin,mid,l,r,ans);
cheak((node*2)+1,mid+1,end,l,r,ans);
}


void update(ll node,ll begin,ll end,ll l ,ll r)
{
if(end<l||begin>r)return;
if(l<=begin && end<=r){save[node]++;return;}
ll mid= (begin+end)/2;
update(node*2,begin,mid,l,r);
update((node*2)+1,mid+1,end,l,r);
}



//resize the save vector to (4*n) for work
//declare the create funtion before work on queue oparetions





int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
for (ll o = 1; o <= t; o++)
{

string s; cin>>s;
vector<ll>v;
for(auto u:s){v.push_back(u-'0');}

save.resize(4*v.size());
ll q;cin>>q;

cout<<"Case "<<o<<":"<<endl;
for (ll i = 0; i < q; i++)
{

char c;cin>>c;
if(c=='I') {
ll l,r;cin>>l>>r;
update(1,0,v.size()-1,l-1,r-1);
}

if(c=='Q')
{
    ll l;cin>>l;
    ll r = l;
    ll ans = 0;
    cheak(1,0,v.size()-1,l-1,r-1,ans);
    if(ans%2==0)cout<<v[l-1]<<endl;
    else cout<<((v[l-1]==0)?1:0)<<endl;
}

}

save.clear();
v.clear();
}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}