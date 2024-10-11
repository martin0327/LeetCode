class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        n = len(times)
        t = times[targetFriend][0]
        
        times.sort(reverse=True)
        chairs = list(range(n))
        leave = defaultdict(list)
        
        for i in range(int(1e5+1)):
            if times[-1][0] == i:
                start, end = times.pop()
                chair = heappop(chairs)
                leave[end-1].append(chair)
            if i == t:
                return chair
            for chair in leave[i]:
                heappush(chairs, chair)
            
        return -1