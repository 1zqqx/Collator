#include <bits/stdc++.h>
#define pii pair<int, int>
#define all(sbe) sbe.begin(),sbe.end()
// #define int long long
using namespace std;
typedef long long ll;

signed main(){
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
#endif
    
    int n, p, x, q, y; cin >> n >> p >> x >> q >> y;
    ll s = 0;
    for(int i = 0; i < n; i++) {
        int u; cin >> u; s += u;
    }
    ll ans = 1e18;
    ans = min(ans, (((s - 1) / n + 1) * n - s) * p);

    for(int i = 0; i < 10000000; i++) {
        if((s - i * y) % n == 0) {
            ans = min(ans, 1ll * i * q);
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}