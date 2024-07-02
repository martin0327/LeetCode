class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        c1 = Counter(nums1)
        c2 = Counter(nums2)
        ans = list()
        for x in s1.intersection(s2):
          cnt = min(c1[x],c2[x])
          for _ in range(cnt):
            ans.append(x)
        return ans