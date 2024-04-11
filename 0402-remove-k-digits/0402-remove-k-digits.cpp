class Solution {
public:
    string removeKdigits(string s, int k) {
        deque<char> dq;
        for (auto c : s) {
            while (dq.size() && k > 0) {
                if (dq.back() > c) {
                    dq.pop_back();
                    k--;
                }
                else break;
            }
            dq.push_back(c);
        }
        while (dq.size() && k > 0) {
            dq.pop_back();
            k--;
        }
        while (dq.size()) {
            if (dq.front() == '0') dq.pop_front();
            else break;
        }
        if (dq.empty()) return "0";
        s.clear();
        while (dq.size()) {
            s += dq.front();
            dq.pop_front();
        }
        return s;
    }
};