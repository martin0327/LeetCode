vector<string> split_str(string s, const char delim = ' ') {
    vector<string> ret;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        ret.push_back(t);
    }
    return ret;
}
using vi = vector<int>;
using vvi = vector<vi>;
using ti3 = tuple<int,int,int>;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& a) {
        vector<ti3> b;
        for (auto s : a) {
            auto t = split_str(s,':');
            auto key = stoi(t[0]);
            int tp = (t[1] == "start");
            auto pos = stoi(t[2]);
            if (tp == 0) pos++;
            b.push_back({pos,tp,key});
        }
        sort(b.begin(), b.end());
        vi ans(n);
        vector<ti3> lst;
        vi st;
        for (auto [pos,tp,key] : b) {
            if (lst.size()) {
                auto [lpos,ltp,lkey] = lst.back();
                if (tp) {
                    if (ltp) ans[lkey] += pos - lpos;
                    else {
                        if (st.size()) {
                            ans[st.back()] += pos - lpos;
                        }
                    }
                }
                else {
                    ans[key] += pos - lpos;
                    assert(key == st.back());
                    st.pop_back();
                }
            }
            if (tp) st.push_back(key);
            lst.push_back({pos,tp,key});
        }
        return ans;
    }
};