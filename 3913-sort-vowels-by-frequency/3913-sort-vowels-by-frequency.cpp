class Solution {
public:
    string sortVowels(string s) {
        string vv = "aeiou";
        set<char> sv(vv.begin(), vv.end());
        map<char,int> cnt, occ;
        int n = s.size();
        vector<int> idx;
        for (int i=0; i<n; i++) {
            auto &ch = s[i];
            if (sv.count(ch)) {
                cnt[ch]++;
                if (!occ.count(ch)) occ[ch] = i;
                idx.push_back(i);
            }
        }
        reverse(idx.begin(), idx.end());
        vector<tuple<int,int,char>> a;
        for (auto &[k,v] : cnt) {
            a.push_back({-v,occ[k],k});
        }
        sort(a.begin(), a.end());
        for (auto [frq,j,ch] : a) {
            frq *= -1;
            while (frq--) {
                s[idx.back()] = ch;
                idx.pop_back();
            }
        }
        return s;
    }
};