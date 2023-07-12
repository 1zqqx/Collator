#include <bits/stdc++.h>
#define pii pair<int, int>
#define all(sbe) sbe.begin(),sbe.end()
#define int long long
using namespace std;
typedef long long ll;

const int N = 1e5+10;
int g[N];

signed main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> g[i];

    int a = 0, b = 0;
    for(int i = 1; i <= n; i++) {
        if(g[i] == i) continue;
        if(g[i] != i) a ++;
        if(i == g[g[i]]) b ++;
    }

    int ans = b / 2 + max(0ll, a - b - 1);
    cout << ans << '\n';
    return 0;
}