class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int mx) {
        int n = words.size();
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            a[i] = words[i].size();
        }
        int cur = 0;
        vector<vector<int>> b;
        for (int i=0; i<n; i++) {
            if (cur==0 || cur + a[i] + 1 > mx) {
                cur = a[i];
                b.push_back({i});
            }
            else {
                cur += a[i]+1;
                b.back().push_back(i);
            }
        }
        vector<string> ans;
        for (int j=0; j<b.size()-1; j++) {
            auto v = b[j];
            int m = v.size();
            if (m==1) {
                string t = words[v[0]];
                t += string(mx-a[v[0]], ' ');
                ans.push_back(t);
                continue;
            }
            int ex = mx;
            for (auto i : v) ex -= a[i];
            vector<int> sp(m-1, ex/(m-1));
            int r = ex%(m-1);
            for (int i=0; i<m-1; i++) {
                if (r-- > 0) sp[i]++;
            }
            string t;
            for (int i=0; i<m-1; i++) {
                t += words[v[i]];
                t += string(sp[i], ' ');
            }
            t += words[v.back()];
            ans.push_back(t);
        }
        string t;
        for (auto i : b.back()) {
            t += words[i];
            t += " ";
        }
        while (t.size() > mx) t.pop_back();
        while (t.size() < mx) t += " ";
        ans.push_back(t);
        return ans;
        
        
    }
};