class Solution {
public:
    int compress(vector<char>& a) {
        int n = a.size(), cnt = 0, idx = 0;
        a.push_back(' ');
        char prv = ' ';
        for (auto c : a) {
            if (c==prv) cnt++;
            else {
                if (cnt) {
                    a[idx++] = prv;
                    if (cnt > 1) {
                        for (auto x : to_string(cnt)) a[idx++] = x;
                    }
                }
                prv = c;
                cnt = 1;
            }
        }
        return idx;
    }
};