class Solution:
    def finalValueAfterOperations(self, a: List[str]) -> int:
        # return sum(1 if '+' in x else -1 for x in a)
        ret = 0
        for x in a:
            if '+' in x: ret += 1
            else: ret -= 1
        return ret