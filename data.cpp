#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

const int N = 1e2+7;

signed main(){
    // freopen("./data/in.in", "w", stdout);
    // int n = 7;
    // std::vector<int> v(7);
    // for(int i = 0; i < n; i++) v[i] = 1 + i;
    srand(time(0));
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    // while(k --) {
    //     std::next_permutation(v.begin(), v.end());
    // }

    std::cout << std::max(1, a - a % 10) << " + " << std::max(1, b - b % 10) << " = " << a + b - (a + b) % 10 << '\n';
    // for(auto i:v) std::cout << i << ' ';
    return 0;
}