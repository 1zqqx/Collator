// 1e6 scanf
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <functional>
#include <vector>
#include <numeric>
#include <bitset>
#include <time.h>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#define PI acos(-1.0)
#define pii pair<int, int>
#define ldb long double
#define vint vector<int>
#define all(sbe) (sbe).begin(),(sbe).end()
#define rall(sbe) (sbe).rbegin(),(sbe).rend()
// #define int long long
typedef long long ll;
using namespace std;
const int32_t INF = 0x3f3f3f3f;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
void debug() {};
template<class T, class...Args>
void debug(T obj, Args...args) {cout << "[ " << obj << " ]\n";debug(args...);}
#define prind(temp_) do{ printf("[=] " #temp_ " -> %d\n", (temp_)); }while(0);
template<class T> inline T cabs(const T &x) { return x > 0 ? x : (-x); }
template<class T> inline T gcd(const T &x, const T &y) { return (y == 0) ? x : gcd(y, x % y); }
template<class T> inline T sgn(const T &x) { return (x > 0) - (x < 0); }
template<class T>T pow(T a, T b){T re = 1;while(b) {if(b & 1) re *= a;b >>= 1;a *= a;}return re; }
template <typename T>
inline void read(T &f) {
    f = 0;T fu = 1;char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') { fu = -1;}c = getchar();}
    while (c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15);c = getchar();}
    f *= fu;
}
template <typename T>
void print(T x) {if (x < 0) putchar('-'), x = -x;if (x < 10) putchar(x + 48);else print(x / 10), putchar(x % 10 + 48);}
template <typename T>
void print(T x, char t) {print(x);putchar(t);}

#define lowbit(x) (x & -x)

ll get(ll n) {
    if(n % 5 == 0) return 1;
    if(n % 5 == 2) return 2;
    if(n % 5 == 4) return 3;
    if(n % 5 == 1) return 4;
    if(n % 5 == 3) return 0;
    return 0;
}
ll calc1(ll x){ // odd
    ll z = 0;
    z = (x - 2) / 10 * 5 + get(x) * 5;
    // z = z * (z + 1) / 2;
    return z;
}
ll calc2(ll x) { // even
    ll z = 0;
    z = (x - 7) / 10 * 5 + get(x) * 5;
    // z = z * (z + 1) / 2;
    return z;
}
void solve(){
    ll n; cin >> n;
    ll z = 0;
    if(n & 1) z = calc1(n) + calc2(n - 1);
    else z = calc1(n - 1) + calc2(n);

    cout << z << '\n';
}

signed main(){
    // ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
