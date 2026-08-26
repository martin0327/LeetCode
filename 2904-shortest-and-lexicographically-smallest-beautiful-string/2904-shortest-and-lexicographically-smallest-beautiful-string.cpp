class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        for (int l=k; l<=n; l++) {
            int cnt = 0;
            vector<string> a;
            vector<int> idx;
            for (int i=0; i<l; i++) {
                if (s[i] == '1') cnt++;
            }
            if (cnt==k) idx = {0};
            for (int i=l; i<n; i++) {
                cnt += s[i] == '1';
                cnt -= s[i-l] == '1';
                if (cnt==k) {
                    idx.push_back(i-l+1);
                }
            }
            for (auto i : idx) {
                a.push_back(s.substr(i,l));
            }
            if (a.size()) {
                return *min_element(a.begin(),a.end());
            }
        }
        return "";
    }
};