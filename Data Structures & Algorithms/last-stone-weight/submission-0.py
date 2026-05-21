class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # intuition -> since you need to smash the heaviest stones each step
        # maintain a heap so its easily accessible
        heapq.heapify_max(stones)
        if len(stones)==1:
            return stones[0]
        
        while len(stones)>1:
            x=heapq.heappop_max(stones)
            y=heapq.heappop_max(stones)
            # now we have the two heaviest stones
            if x==y:
               continue
            else:
                heapq.heappush_max(stones,x-y)
        if len(stones)==1:
            return stones[0]
        else:
            return 0

        




        