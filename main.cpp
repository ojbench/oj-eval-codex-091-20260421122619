#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector< set<LL> > s(1);

    set<LL>::iterator it;
    int it_a = -1;
    bool valid = false;
    int lst = 0;

    int op;
    while ( (cin >> op) ){
        LL a,b,c;
        switch(op){
            case 0:{
                cin >> a >> b;
                if ((size_t)a >= s.size()) s.resize((size_t)a + 1);
                auto res = s[(size_t)a].insert(b);
                if (res.second){
                    it = res.first;
                    it_a = (int)a;
                    valid = true;
                }
                break;
            }
            case 1:{
                cin >> a >> b;
                if ((size_t)a < s.size()){
                    if (valid && it_a==(int)a) {
                        auto &st = s[(size_t)a];
                        if (it != st.end() && *it == b) valid = false;
                    }
                    s[(size_t)a].erase(b);
                }
                break;
            }
            case 2:{
                cin >> a;
                if ((size_t)a >= s.size()) s.resize((size_t)a + 1);
                ++lst;
                if ((size_t)lst >= s.size()) s.resize((size_t)lst + 1);
                s[(size_t)lst] = s[(size_t)a];
                break;
            }
            case 3:{
                cin >> a >> b;
                if ((size_t)a >= s.size()){
                    cout << "false\n";
                } else {
                    auto it2 = s[(size_t)a].find(b);
                    if (it2 != s[(size_t)a].end()){
                        cout << "true\n";
                        it = it2; it_a = (int)a; valid = true;
                    } else {
                        cout << "false\n";
                    }
                }
                break;
            }
            case 4:{
                cin >> a >> b >> c;
                if ((size_t)a >= s.size()){
                    cout << 0 << "\n";
                } else {
                    auto &st = s[(size_t)a];
                    auto itl = st.lower_bound(b);
                    auto itr = st.upper_bound(c);
                    size_t cnt = 0;
                    for (auto itx = itl; itx != itr; ++itx) ++cnt;
                    cout << cnt << "\n";
                }
                break;
            }
            case 5:{
                if (valid && (size_t)it_a < s.size()){
                    auto &st = s[(size_t)it_a];
                    if (it == st.begin()){
                        valid = false;
                    } else {
                        auto it2 = it; --it2;
                        cout << *it2 << "\n";
                        it = it2;
                        break;
                    }
                }
                cout << -1 << "\n";
                break;
            }
            case 6:{
                if (valid && (size_t)it_a < s.size()){
                    auto &st = s[(size_t)it_a];
                    auto nxt = it; ++nxt;
                    if (nxt == st.end()){
                        valid = false;
                    } else {
                        it = nxt;
                        cout << *it << "\n";
                        break;
                    }
                }
                cout << -1 << "\n";
                break;
            }
            default: break;
        }
    }
    return 0;
}
