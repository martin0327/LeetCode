class Solution:
    def distinctNames(self, a: List[str]) -> int:
        d = defaultdict(set)

        for s in a:
          d[s[0]].add(s[1:])
        # print(d)
        cnt = defaultdict(int)
        for i in range(26):
          c = chr(ord('a') + i)
          for j in range(i+1,26):
            cc = chr(ord('a') + j)
            cnt[(c,cc)] = len(d[c].intersection(d[cc]))

        ans = 0
        for s in a:
          for i in range(26):
            c = chr(ord('a') + i)
            if c == s[0]: continue 
            t = s[1:]
            if t in d[c]:
              continue 
            temp = [c,s[0]]
            temp = tuple(sorted(temp))
            ans += len(d[c]) - cnt[temp]
        return ans