class Solution:
    def simplifyPath(self, path: str) -> str:
        a = path.split('/')
        b = []
        for x in a:
            if x in ['', '.']: continue
            if x == '..':
                if b: b.pop()
            else:
                b.append(x)
        ans = ""
        if b:
            for x in b:
                ans += "/" + x
        else:
            ans = "/"
        return ans