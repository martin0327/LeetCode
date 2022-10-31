class Solution:
    def numIslands(self, a: List[List[str]]) -> int:
        n = len(a)
        m = len(a[0])
        
        visited = [[0 for j in range(m)] for i in range(n)]
        
        dr = [0,0,-1,1]
        dc = [-1,1,0,0]
        
        dq = deque()
        ans = 0
        print(visited)
        print(a)
        for i in range(n):
            for j in range(m):
                if a[i][j]=='0': continue
                if visited[i][j]: continue
                dq.append((i,j))                
                while dq:
                    r,c = dq.pop()
                    for k in range(4):
                        nr = r + dr[k]
                        nc = c + dc[k]                                
                        if nr < 0 or nr >= n: continue
                        if nc < 0 or nc >= m: continue
                        if visited[nr][nc]: continue
                        if a[nr][nc] == '0': continue
                        visited[nr][nc] = 1
                        dq.append((nr,nc))
                ans += 1
        return ans
                