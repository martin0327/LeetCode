class Solution {
public:
    int calPoints(vector<string>& b) {
        vector<int> a;
        for (auto s : b) {
            if (s == "+") {
                a.push_back(a.back() + a[a.size()-2]);
            }
            else if (s == "D") {
                a.push_back(2*a.back());
            }
            else if (s == "C") a.pop_back();
            else a.push_back(stoi(s));
        }
        return accumulate(a.begin(), a.end(), 0);
    }
};