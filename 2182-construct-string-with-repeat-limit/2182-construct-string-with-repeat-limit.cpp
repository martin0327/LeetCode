class Solution {
   public:
    string repeatLimitedString(string s, int k) {
        int n = s.size();
        vector<int> cnt(26);
        for (auto c : s) {
            cnt[c - 'a']++;
        }

        vector<int> ans;
        int repeat = 0;
        int cur = -1;
        bool flag = true;
        while (flag) {
            for (int i = 25; i >= 0; i--) {
                if (cnt[i]) {
                    if (cur == i) {
                        if (repeat >= k) {
                            if (i == 0) flag = false;
                            continue;
                        } else {
                            ans.push_back(i);
                            cnt[i]--;
                            repeat++;
                            break;
                        }
                    } else {
                        ans.push_back(i);
                        cnt[i]--;
                        repeat = 1;
                        cur = i;
                        break;
                    }
                }
                if (i == 0) flag = false;
            }
        }
        string ret;
        for (auto x : ans) {
            ret += 'a' + x;
        }
        return ret;
    }
};