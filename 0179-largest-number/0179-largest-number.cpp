class Solution {
public:
    string largestNumber(vector<int>& a) {
        vector<string> b;
        for (auto x : a) {
            auto s = to_string(x);
            int l = s.size();
            b.push_back(s);
        }
        int n = b.size();
        sort(b.rbegin(), b.rend());
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                auto s = b[i];
                auto t = b[j];
                string st = s + t;
                string ts = t + s;
                if (st < ts) swap(b[i],b[j]);
            }
        }
        string ans;
        for (auto s : b) ans += s;
        set<char> sc(ans.begin(), ans.end());
        if (sc.size() == 1 && sc.count('0')) return "0";
        return ans;
    }
};