class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # intuition is loop through points adding (distance,x,y)
        #then it would be easy to pop
        heap=[]
        for p in points:
            x,y=p 
            distance=math.sqrt((x)**2+(y)**2)
            heapq.heappush(heap,(distance,(x,y)))
        
        res=[]
        print(heap)
        # now we pop from the heap till k=0
        while k>0:
            distance,(x,y)=heapq.heappop(heap)
            res.append([x,y])
            k-=1
        
        return res


        