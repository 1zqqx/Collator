#include <iostream>
#include <ctime>

using namespace std;

void gen(){
    int n = rand() % 10 + 1;
    cout << n << '\n';
    for(int i = 1; i <= n; i++) {
        cout << rand() % 10 << ' ';
    }
    cout << '\n';
}

signed main(){
    freopen("./data/in.in", "w", stdout);
    srand(time(0));
    int n = 5;
    cout << n << '\n';
    for(int i = 1; i <= n; i++) {
        gen();
    }
    return 0;
}