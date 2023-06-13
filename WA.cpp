// 1e6 scanf
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    vector<int> v(n), f(n, 0);
    for(int& i:v) cin >> i;
    int p = 1;
    while(p < n && v[p] >= v[p - 1]) p++;
    for(int i = 0; i < p; i++) f[i] = 1;
    for(int i = p, la = p; i < n; i++) {
        if(v[i] >= v[la] && v[i] <= v[0]) la = i, f[i] = 1;
    }
    for(int i = 0; i < n; i++) {
        cout << f[i];
    }
    cout << '\n';
}

signed main(){
    freopen("./data/in.in", "r", stdin);
    freopen("./data/WA.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
