#include <bits/stdc++.h>
#define pii pair<int, int>
#define all(sbe) sbe.begin(),sbe.end()
// #define int long long
using namespace std;
typedef long long ll;

void exgcd(ll a, ll b, ll &x, ll &y) {
    if(b==0) {
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

signed main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    
    int n, p, x, q, y; cin >> n >> p >> x >> q >> y;
    ll s = 0;
    for(int i = 0; i < n; i++) {
        int u; cin >> u; s += u;
    }
    ll ans = 1e18;
    ans = min(ans, (((s - 1) / n + 1) * n - s) * p);

    // ll xx, yy;
    // exgcd(y, n, xx, yy);
    // // cout << xx << ' ' << yy << ' ';
    // xx = (xx % n + n) % n;
    // // cout << xx << ' ';
    // ll te = 1;
    // if(__gcd(s, xx * y) != 1 || y == 1) {
    //     while((s - xx * te * y) % n != 0) {
    //         te ++;
    //         // cout << (s - xx * te * y) << ' ';
    //     }
    //     ans = min(ans, 1ll * xx * te * q);
    // }
    
    ll k1, k2;
    exgcd(y, n, k1, k2);
    if(s % __gcd(y, n) == 0) {
        int S = n / __gcd(y, n);
        cout << "k1 " << k1 << '\n';
        k1 = ((k1 % S) - S) % S;
        cout << "k1 " << k1 << '\n';
        s = s + k1 * y;
        int te = 0;
        while((s - te * y) % n != 0) {
            te ++;
            cout << (s - k1 * te * y) << ' ';
        }
        ans = min(ans, 1ll * (te - k1) * q);
    }
    // cout << k1 << ' ' << k2 << '\n';

    cout << ans << '\n';
    return 0;
}