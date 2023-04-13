class Solution:
    def validateStackSequences(self, a: List[int], b: List[int]) -> bool:
        st = []
        i = 0
        for x in a:
            st.append(x)
            while st and st[-1] == b[i]:
                st.pop()
                i += 1
        return not st