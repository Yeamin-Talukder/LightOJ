#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<pair<int,int>> value;

ll t; cin >> t;
for (ll i = 1; i <= t; i++)
{
    ll n; cin >> n;
    value.push_back({n,i});
}

sort(value.begin(),value.end());

vector<double> ans(t+1);

double x = 0;
ll index = 0;

for (ll i = 1; i <= value[t-1].first ; i++)
{
    x += (1.0 / i);
    while(index < t && value[index].first == i)
    {
        ans[ value[index].second ] = x;
        index++;
    }
}


for (ll i = 1; i <= t; i++)
{
    cout  << "Case " << i << ": " << fixed << setprecision(10) << ans[i] << endl;
}


// Time Complexcity  : O() 
// Space Complexcity : O() 
}