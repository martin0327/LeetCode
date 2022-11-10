class Solution {
public:
  string removeDuplicates(string s) {
    string t;
    for (auto c : s) {
      if (t.size() && t.back()==c) t.pop_back();
      else t += c;
    }
    return t;
  }
}; 