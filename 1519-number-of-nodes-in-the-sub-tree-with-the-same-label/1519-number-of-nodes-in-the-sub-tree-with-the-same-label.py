class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        cnt = [[0 for j in range(26)] for i in range(n)]
        adj = [[] for _ in range(n)]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        l = [ord(labels[i]) - ord('a') for i in range(n)]
        
        def dfs(u, p, c):
            cnt[u][c] += (c==l[u])
            for v in adj[u]:
                if v == p: continue
                cnt[u][c] += dfs(v,u,c)
            return cnt[u][c]
        
        for c in range(26): dfs(0,-1,c)
            
        ret = [cnt[i][l[i]] for i in range(n)]
        return ret