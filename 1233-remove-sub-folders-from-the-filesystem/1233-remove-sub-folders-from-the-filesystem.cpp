class Solution {
public:
    vector<string> removeSubfolders(vector<string>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<int> rm(n);
        set<string> ss = {a[0]};
        for (int i=1 ; i<n; i++) {
            bool ok = true;
            auto s = a[i];
            while (s.size()) {
                if (ss.count(s)) {
                    ok = false;
                    break;
                }
                while (s.size()) {
                    if (s.back() == '/') {
                        s.pop_back();
                        break;
                    }
                    else s.pop_back();
                }
            }
            if (ok) ss.insert(a[i]);
            else rm[i] = 1;
        }
        
        vector<string> ans;
        for (int i=0; i<n; i++) {
            if (!rm[i]) ans.push_back(a[i]);
        }
        return ans;
    }
};