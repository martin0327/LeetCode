class Solution {
public:
    vector<string> removeComments(vector<string>& a) {
        int cur = 0;
        bool to_back = false;
        vector<string> ans;
        auto emp = [&] (string &s) {
            for (auto ch : s) {
                if (ch != ' ') return false;
            }
            return true;
        };
        for (auto &s : a) {
            int n = s.size();
            auto f = [&] (int i) {
                if (s[i] == '/' && s[i+1] == '/') {
                    return 1;
                }
                if (s[i] == '/' && s[i+1] == '*') {
                    return 2;
                }
                if (s[i] == '*' && s[i+1] == '/') {
                    return 3;
                }
                return 0;
            };
            string t;
            for (int i=0; i<n; i++) {
                if (cur == 1) continue;
                else if (cur == 2) {
                    if (i+1 < n) {
                        int x = f(i);
                        if (x == 3) {
                            cur = 0;
                            i++;
                        }
                    }
                }
                else if (cur == 0) {
                    if (i+1 < n) {
                        int x = f(i);
                        if (x == 1) {
                            cur = 1;
                            i++;
                        }
                        else if (x == 2) {
                            cur = 2;
                            i++;
                        }
                        else t += s[i];
                    }
                    else t += s[i];
                }
                else assert(false);
            }
            if (t.size()) {
                if (to_back) {
                    ans.back() += t;
                    to_back = false;
                }
                else ans.push_back(t);
            }
            else {
                if (to_back && cur == 0) {
                    to_back = false;
                }
            }
            if (cur == 1) cur = 0;
            if (cur == 2 && t.size()) {
                to_back = true;
            }
        }
        return ans;
    }
};