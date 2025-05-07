#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<ll> ans(1);
vector<vector<ll>> vis;

void traverse(vector<string> &v, ll l, ll r)
{
    if (l < 0 || r < 0 || l >= v.size() || r >= v[0].size()) return;
    if (vis[l][r] == 1 || v[l][r] == '#') return;

    vis[l][r] = 1;
    ans[0]++;

    traverse(v, l + 1, r);
    traverse(v, l - 1, r);
    traverse(v, l, r + 1);
    traverse(v, l, r - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll int t; cin >> t;
    ll c = 1;
    while (t--)
    {

        ll w, h;
        cin >> w >> h;

        vis.resize(h, vector<ll>(w));
        vector<string> v;

        ll l = 0, r = 0;

        for (ll i = 0; i < h; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);

            for (ll j = 0; j < w; j++)
                if (s[j] == '@')
                {
                    l = i;
                    r = j;
                    break;
                }
        }

        traverse(v, l, r);

        cout << "Case " << c++ << ": " << ans[0] << endl;

        vis.clear();
        ans[0] = 0;
    }
    // Time Complexcity  : O(h * w )
    // Space Complexcity : O(h * w)
}