class Solution {
public:
    string toHex(int x) {
        if (x == 0) return "0";
        vector<int> a;
        for (int i=0; i<8; i++) {
            int y = (x>>(4*i))&15;
            a.push_back(y);
        }
        while (a.size() && a.back() == 0) 
            a.pop_back();

        string ans;
        while (a.size()) {
            auto y = a.back();
            a.pop_back();
            if (y < 10) ans += '0' + y;
            else ans += 'a' + (y-10);
        }
        return ans;
    }
};