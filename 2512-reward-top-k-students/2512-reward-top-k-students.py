class Solution:
    def topStudents(self, pf: List[str], nf: List[str], rp: List[str], ids: List[int], k: int) -> List[int]:
        pf = set(pf)
        nf = set(nf)
        d = defaultdict(int)
        for s,idx in zip(rp,ids):
            for x in s.split():
                if x in pf:
                    d[idx] += 3
                elif x in nf:
                    d[idx] -= 1
        res = []
        for key,val in d.items():
            res.append((val,-key))
        res.sort(reverse = True)
        return [-key for val,key in res[:k]]
                