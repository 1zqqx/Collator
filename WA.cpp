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

void solve(){
    string a, b, c, te; cin >> a >> te >> b >> te >> c;

    function<int(string&)> stoi = [](string& s) {
        int re = 0;
        for(auto c:s) re = re * 10 + c - '0'; return re;
    };
    function<int(string&, string&, string&)> check = [&](string& sa, string& sb, string& sc) {
        int a = stoi(sa), b = stoi(sb), c = stoi(sc);
        if(a + b == c) {
            cout << "Yes\n";
            cout << a << " + " << b << " = " << c << '\n';
            return 1;
        }
        return 0;
    };
    
    if(check(a, b, c)) {
        return ;
    }
    for(int i = 0; i < a.size(); i++) {
        for(char j = (i == 0 ? '1' : '0'); j <= '9'; j++) {
            string stea = a.substr(0, i) + j + a.substr(i);
            if(check(stea, b, c)) {
                return;
            }
        }
    }
    for(int i = 0; i < b.size(); i++) {
        for(char j = (i == 0 ? '1' : '0'); j <= '9'; j++) {
            string steb = b.substr(0, i) + j + b.substr(i);
            if(check(a, steb, c)) {
                return;
            }
        }
    }
    for(int i = 0; i < c.size(); i++) {
        for(char j = (i == 0 ? '1' : '0'); j <= '9'; j++) {
            string stec = c.substr(0, i) + j + c.substr(i);
            if(check(a, b, stec)) {
                return;
            }
        }
    }
    cout << "No\n";
    return ;
}

signed main(){
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    clock_t start = clock();
#endif

    // ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }

#ifdef LOCAL
    clock_t end = clock();
    std::cerr << "\n\nRunning Time : " 
        << (double) (end - start) / CLOCKS_PER_SEC * 1000 
        << "ms" << '\n';
#endif
    return 0;
}
