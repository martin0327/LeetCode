class Solution {
public:
    string removeStars(string s) {
        string t;
        for (auto c : s) {
            if (t.size()) {
                if ((t.back()=='*')^(c=='*')) t.pop_back();
                else t.push_back(c);
            }
            else t.push_back(c);
        }
        return t;
    }
};