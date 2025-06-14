#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll int t; cin >> t;
while(t--) {

double v1,v2,v3,a1,a2; cin >> v1 >> v2 >> v3 >> a1 >> a2;

double t1 = (v1 / a1);
double t2 = (v2 / a2);

double bird = max(t1, t2) * v3;
double distance = ((v1 * v1) / (2 * a1)) + ((v2 * v2 ) / (2 * a2));

cout << "Case " << c++ << ": " << fixed << setprecision(7) << distance << " " << bird << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}