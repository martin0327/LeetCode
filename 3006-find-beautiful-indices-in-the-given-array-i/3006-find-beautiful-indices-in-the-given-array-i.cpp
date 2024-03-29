class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size(), m1 = a.size(), m2 = b.size();
        vector<int> idx_a, idx_b;
        for (int i=0; i+m1-1<n; i++) {
            string t = s.substr(i,m1);
            if (t==a) idx_a.push_back(i);
        }
        for (int i=0; i+m2-1<n; i++) {
            string t = s.substr(i,m2);
            if (t==b) idx_b.push_back(i);
        }
        
        vector<int> ans;
        
        auto it = idx_b.begin();
        for (auto i : idx_a) {
            while (it != idx_b.end() && *it < i-k) it++;
            if (it != idx_b.end() && abs(*it-i) <= k) ans.push_back(i);
        }
        
        return ans;
    }
};