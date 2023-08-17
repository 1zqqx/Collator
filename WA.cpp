#include <bits/stdc++.h>
#define pii pair<int, int>
#define all(sbe) sbe.begin(),sbe.end()
// #define int long long
using namespace std;
typedef long long ll;

signed main(){
    int n, m; cin >> n >> m;
    if(n == m) {
        cout << "0\n";
        return 0;
    }
    n -= m;
    vector<int> v; v.push_back(m);
    while(m != 1) {
        int u = m / 2 + (m & 1);
        v.push_back(u);
        m = u;
    }
    
    ll s = 0, k = 0;
    for(auto& i:v) {
        s += i;
        k ++;

        if(s >= n) {
            cout << k << "\n";
            return 0;
        }
    }

    k += n - s;
    cout << k << '\n';
    return 0;
}