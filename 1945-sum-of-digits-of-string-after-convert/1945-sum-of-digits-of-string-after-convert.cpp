class Solution {
public:
    int getLucky(string s, int k) {
        string t;
        for (auto c : s) t += to_string(c-'a'+1);
        auto f = [&] (string s) {
            int x = 0;
            for (auto c : s) x += c - '0';
            return to_string(x);
        };
        while (k--) t = f(t);
        return stoi(t);
    }
};