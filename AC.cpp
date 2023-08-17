#include <iostream>
#include <cstring>

using namespace std;

using i64 = long long;

int main() {
    int n, m;
    cin >> n >> m;
    int res = 0;
    n -= m;
    while (n > 0) {
        m = (m + 1) / 2;
        if (m == 1) {
            res += n;
            break;
        } 
        n -= m, res++;
    }
    cout << res;
}