class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        do {
            if (s.front()=='0') continue;
            int x = stoll(s);
            if ((x&(x-1))==0) return true;
        } while(next_permutation(s.begin(), s.end()));
        return false;
    }
};