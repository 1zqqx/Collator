#include <iostream>
#include <ctime>

using namespace std;

const int N = 1e2+7;

signed main(){
    // freopen("./data/in.in", "w", stdout);
    srand(time(0));
    
    long long n = rand() % 10, p = rand() % 20, x = 1, q = rand() % 20, y = rand() % 20;
    cout << n << ' ' << p << ' ' << x << ' ' << q << ' ' << y << '\n';
    for(int i = 1; i <= n; i++) cout << rand() % 20 << ' ';
    return 0;
}