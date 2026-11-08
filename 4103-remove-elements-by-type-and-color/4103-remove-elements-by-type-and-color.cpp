using ll = long long;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
class Solution {
public:
    bool canRemoveAll(vector<int>& tp, vector<int>& col, vector<int>& grpsz) {
        int n = tp.size();
        vti3 st;
        for (int i=0; i<n; i++) {
            int t = tp[i], c = col[i];
            if (st.empty()) {
                st.push_back({t,c,1});
                if (1 == grpsz[t]) st.pop_back();
            }
            else {
                auto &[t2,c2,cnt] = st.back();
                if (t == t2 && c == c2) {
                    cnt++;
                    if (cnt == grpsz[t]) st.pop_back();
                }
                else {
                    st.push_back({t,c,1});
                    if (1 == grpsz[t]) st.pop_back();
                }
            }
        }
        return st.empty();
    }
};