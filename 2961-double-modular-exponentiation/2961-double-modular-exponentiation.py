class Solution:
    def getGoodIndices(self, a: List[List[int]], t: int) -> List[int]:
        n = len(a)
        ans = []
        for i,(a,b,c,m) in enumerate(a):
            if pow(pow(a,b,10),c,m) == t:
                ans.append(i)
        return ans