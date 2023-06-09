class Solution {
public:
    char nextGreatestLetter(vector<char>& a, char x) {
        auto it = upper_bound(a.begin(), a.end(), x);
        if (it == a.end()) return a.front();
        return *it;
    }
};