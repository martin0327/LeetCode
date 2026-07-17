using vi = vector<int>;
class Solution {
public:
    NestedInteger deserialize(string s) {
        int n = s.size();
        map<int,int> br;
        map<int,vi> dl;
        vi st;
        for (int i=0; i<n; i++) {
            auto ch = s[i];
            if (ch == '[') {
                st.push_back(i);
            }
            else if (ch == ']') {
                br[st.back()] = st.size();
                st.pop_back();
            }
            else if (ch == ',') {
                dl[st.size()].push_back(i);
            }
        }
        function<NestedInteger(int,int)> f = [&](int l, int r) {
            if (s[l] == '[') {
                assert(s[r] == ']');
                auto ret = NestedInteger();
                if (l+1 == r) return ret;
                auto lv = br[l];
                vi b;
                auto &idx = dl[lv];
                auto it = lower_bound(idx.begin(), idx.end(), l);
                while (it != idx.end()) {
                    if (*it < r) b.push_back(*it);
                    it++;
                }
                int pr = l;
                for (auto i : b) {
                    ret.add(f(pr+1,i-1));
                    pr = i;
                }
                ret.add(f(pr+1,r-1));
                return ret;
            }
            else {
                string t;
                for (int i=l; i<=r; i++) t += s[i];
                auto ret = NestedInteger(stoi(t));
                return ret;
            }
        };
        auto ret = f(0,n-1);
        return ret;
    }
};