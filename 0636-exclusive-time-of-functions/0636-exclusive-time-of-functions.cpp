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
            int key = stoi(t[0]);
            int tp = (t[1] == "start");
            int pos = stoi(t[2]);
            if (tp == 0) pos++;
            b.push_back({pos,tp,key});
        }
        sort(b.begin(), b.end());
        vi ans(n), st;
        for (int i=0; i<int(b.size()); i++) {
            auto [pos,tp,key] = b[i];
            if (i > 0) {
                auto [ppos,ptp,pkey] = b[i-1];
                if (tp) {
                    if (ptp) ans[pkey] += pos - ppos;
                    else {
                        if (st.size()) {
                            ans[st.back()] += pos - ppos;
                        }
                    }
                }
                else {
                    ans[key] += pos - ppos;
                    assert(key == st.back());
                    st.pop_back();
                }
            }
            if (tp) st.push_back(key);
        }
        return ans;
    }
};