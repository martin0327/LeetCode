class Solution:
    def sumPrefixScores(self, a: List[str]) -> List[int]:
        mp = defaultdict(int)
        for s in a:
            t = ""
            for c in s:
                t += c
                mp[t] += 1
        n = len(a)
        ans = [0 for i in range(n)]
        for i in range(n):
            t = ""
            for c in a[i]:
                t += c
                ans[i] += mp[t]
        return ans