class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        heap=[]
        f={}
        for t in tasks:
            if t not in f:
                f[t]=1
            else:
                f[t]+=1
        
        heap=[(k,v) for v,k in f.items()]
        # now we heapify this so we get the tasks requiring the mosts work first
        queue=[]
        heapq.heapify_max(heap)
        total_time=0
        while len(heap)>0 or len(queue)>0:
            if queue and queue[0][0] <= total_time:
                time,freq,task=queue.pop(0)
                heapq.heappush_max(heap,(freq,task))
            if len(heap)>0:
                freq,task=heapq.heappop_max(heap)
                freq-=1
                if freq!=0:
                    queue.append((total_time+n+1,freq,task))
            # main thing is to now pop
            #if ready to pop then pop and repush in heap
            total_time+=1
        return total_time
        