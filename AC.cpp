// 1e6 scanf
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> v, f(n, 0);
    int f1 = 1, f2 = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(f1) {
            if(v.empty()) {
                f[i] = 1;
                v.push_back(x);
            }
            else if(x >= v.back()) {
                f[i] = 1;
                v.push_back(x);
            }
            else if(x < v.back() && x <= *v.begin()) {
                f1 = 0;
                f2 = 1;
                f[i] = 1;
                v.push_back(x);
            }
        }
        else if(f2) {
            if(x >= v.back() && x <= *v.begin()) {
                f[i] = 1;
                v.push_back(x);
            }
        }
    }

    for(int i = 0; i < n; i++) cout << f[i];
    cout << '\n';
}

signed main(){
    freopen("./data/in.in", "r", stdin);
    freopen("./data/AC.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
