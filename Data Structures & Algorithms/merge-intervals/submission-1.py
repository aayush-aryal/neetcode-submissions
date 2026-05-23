class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        #intuition --> sort the list 
        # then see if the end of one interval is the start of the other 
        # if so merge them if not add to the end of the list
        intervals=sorted(intervals)
        if len(intervals)==1:
            return intervals
        i=1
        res=[intervals[0]]
        for start,end in intervals:
            prev_start,prev_end=res[-1]
            if start<=prev_end:
                #merge the interval
                res[-1][1]=max(prev_end,end)
            else:
                res.append([start,end])
        
        return res
