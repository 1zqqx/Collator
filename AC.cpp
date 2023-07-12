#include <bits/stdc++.h>
#define pii pair<int, int>
#define all(sbe) sbe.begin(),sbe.end()
// #define int long long
using namespace std;
typedef long long ll;

signed main(){
    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    int z = 0;
    for(int i = 1; i <= n; i++) {
        while(v[i] != i) {
            swap(v[i], v[v[i]]);
            z ++;
        }
    }

    cout << z << '\n';
    return 0;
}