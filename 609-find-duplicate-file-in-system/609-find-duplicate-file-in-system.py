class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for s in paths:
            a = s.split()
            pre = a[0]
            for fc in a[1:]:
                f,c = fc.split('(')
                c = c[:-1]
                d[c].append(pre + '/' + f)
        return [x for x in d.values() if len(x) > 1] 