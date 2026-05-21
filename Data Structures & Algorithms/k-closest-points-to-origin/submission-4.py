class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # intuition is loop through points adding (distance,x,y)
        #then it would be easy to pop
        heap=[]
        max_distance=0
        for p in points:
            x,y=p 
            distance=math.sqrt((x)**2+(y)**2)
            if len(heap)<k:
                heapq.heappush_max(heap,(distance,(x,y)))
            else:
                heapq.heappush_max(heap,(distance,(x,y)))
                heapq.heappop_max(heap)
        return [[x, y] for dist, (x, y) in heap]


        