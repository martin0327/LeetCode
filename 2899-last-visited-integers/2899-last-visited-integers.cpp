class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int cnt = 0;
        vector<int> a, ret;
        for (auto s : words) {
            if (s=="prev") {
                int sz = a.size();
                if (sz-1-cnt >= 0) {
                    ret.push_back(a[sz-cnt-1]);
                }
                else ret.push_back(-1);
                cnt++;
            }
            else {
                a.push_back(stoi(s));
                cnt = 0;
            }
        }
        return ret;

    }
};