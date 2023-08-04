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
    int k = rand() % 100;

    // while(k --) {
    //     std::next_permutation(v.begin(), v.end());
    // }

    std::cout << k << '\n';
    // for(auto i:v) std::cout << i << ' ';
    return 0;
}