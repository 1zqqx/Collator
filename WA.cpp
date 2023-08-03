#include <bits/stdc++.h>
#define pii pair<int, int>
#define all(sbe) sbe.begin(),sbe.end()
// #define int long long
using namespace std;
typedef long long ll;

struct A{
    int ism;
    vector<string> ord;
};
map<string, int> abcd;
stack<int> stk;
vector<A> vec;

int get16(int u) {
    int re = 0;
    for(int i = 0; i < 16; i++) {
        if((u >> i) & 1) re |= (1 << i);
    }
    return re;
}
int dig(string s) {
    for(auto i:s) if(isdigit(i)) return 1;
    return 0;
}
void make(int p) {
    vec[p].ism = 1;
    if(vec[p].ord.size() == 2) {
        string od = vec[p].ord[0], od1 = vec[p].ord[1];
        if(od == "pop") {
            abcd[od1] = stk.top(); stk.pop();
        }
        else if(od == "push") {
            if(dig(od1)) stk.push(get16(stoi(od1)));
            else stk.push(abcd[od1]);
        }
        else if(od == "div"){
            if(dig(od1)) abcd["ax"] /= stoi(od1);
            else abcd["ax"] /= abcd[od1];
            abcd["ax"] = get16(abcd["ax"]);
        }
        else if(od == "mul") {
            if(dig(od1)) abcd["ax"] *= stoi(od1);
            else abcd["ax"] *= abcd[od1];
            abcd["ax"] = get16(abcd["ax"]);
        }
    }
    else if(vec[p].ord.size() == 3) {
        string od1 = vec[p].ord[0], od2 = vec[p].ord[1], od3 = vec[p].ord[2];
        if(od1 == "mov") {
            if(dig(od3)) abcd[od2] = stoi(od3);
            else abcd[od2] = abcd[od3];
        }
        else if(od1 == "add") {
            if(dig(od3)) abcd[od2] += stoi(od3);
            else abcd[od2] += abcd[od3];
        }
        else if(od1 == "sub") {
            if(dig(od3)) abcd[od2] -= stoi(od3);
            else abcd[od2] -= abcd[od3];
        }
        abcd[od2] = get16(abcd[od2]);
    }
}

signed main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    
    abcd["ax"] = 0; abcd["bx"] = 0; abcd["cx"] = 0; abcd["dx"] = 0;
    
    string op;
    while(cin >> op) {
    again:
        if(op == "a") {
            string order; cin >> order;
            do {
                if(order == "a" || order == "g" || order == "u" || order == "d" || order == "r") {
                    op = order;
                    goto again;
                }
                A a; a.ism = 0, a.ord.push_back(order);
                if(order == "mov" || order == "sub" || order == "add") {
                    for(int i = 0; i < 2; i++) {
                        string cs; cin >> cs;
                        a.ord.push_back(cs);
                    }
                }
                else {
                    string cs; cin >> cs;
                    a.ord.push_back(cs);
                }
                vec.push_back(a);
            } while(cin >> order);
        }
        else if(op == "g") {
            int n; cin >> n;
            for(int i = 0; i < n && i < vec.size(); i++) {
                if(!vec[i].ism) make(i);
            }
        }
        else if(op == "u") {
            for(int i = 0; i < vec.size(); i++) {
                if(!vec[i].ism) {
                    for(int j = 0; j < vec[i].ord.size(); j++) {
                        cout << vec[i].ord[j] << " \n"[j == vec[i].ord.size() - 1];
                    }
                }
            }
        }
        else if(op == "d") {
            string reg; cin >> reg;
            cout << abcd[reg] << '\n';
        }
        else if(op == "r") {
            string reg; int v; cin >> reg >> v;
            abcd[reg] = get16(v);
        }
    }
    return 0;
}