#include <bits/stdc++.h>
using namespace std;
#define ll long long

class segment_tree
{

public:
    vector<ll> save, lazy;

    segment_tree(ll size)
    {
        save.resize(4 * size);
        lazy.resize(4 * size);
    }

    void create(ll node, ll start, ll end, vector<ll> &v)
    {
        if (start == end)
        {
            save[node] = v[start];
            return;
        }

        ll mid = (start + end) / 2;
        create(node * 2, start, mid, v);
        create((node * 2) + 1, mid + 1, end, v);

        save[node] = save[node * 2] + save[(node * 2) + 1];
    }

    void update(ll node, ll start, ll end, ll l, ll r, ll value)
    {
        if (start > r || end < l) return;

        if (l == start && end == r)
        {
            save[node] += value; return;
        }

        ll mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, value);
        update((node * 2) + 1, mid + 1, end, l, r, value);

        save[node] = save[node * 2] + save[(node * 2) + 1];
    }

    void query1(ll node, ll start, ll end, ll l, ll r, ll carry, ll &ans)
    {

        if (start > r || end < l) return;
        if (l == start && end == r)
        {
            ans += save[node];
            save[node] = 0;
            return;
        }
        ll mid = (start + end) / 2;

        query1(node * 2, start, mid, l, r, carry, ans);
        query1((node * 2) + 1, mid + 1, end, l, r, carry, ans);
        save[node] = save[node * 2] + save[(node * 2) + 1];
    }

    void query3(ll node, ll start, ll end, ll l, ll r, ll carry, ll &ans)
    {

        if (start > r || end < l) return;
        if (l <= start && end <= r)
        {
            ans += save[node];
            return;
        }
        ll mid = (start + end) / 2;

        query3(node * 2, start, mid, l, r, carry, ans);
        query3((node * 2) + 1, mid + 1, end, l, r, carry, ans);
    }
};



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    for (ll ti = 1; ti <= t; ti++)
    {

        ll n, q;
        cin >> n >> q;

        vector<ll> v(n);
        for (auto &u : v)
            cin >> u;

        segment_tree *segment = new segment_tree(n);

        segment->create(1, 0, n - 1, v);

        cout << "Case " << ti << ":" << endl;

        for (ll i = 0; i < q; i++)
        {

            ll type;
            ;
            cin >> type;
            if (type == 1)
            {
                ll l;
                cin >> l;

                ll ans = 0;
                segment->query1(1, 0, n - 1, l, l, 0, ans);
                cout << ans << endl;
            }

            else if (type == 2)
            {
                ll l, v;
                cin >> l >> v;
                segment->update(1, 0, n - 1, l, l, v);
            }

            else if (type == 3)
            {
                ll l, r;
                cin >> l >> r;
                ll ans = 0;
                segment->query3(1, 0, n - 1, l, r, 0, ans);
                cout << ans << endl;
            }
        }
    }
}
// Time Complexcity  : O()
// Space Complexcity : O()