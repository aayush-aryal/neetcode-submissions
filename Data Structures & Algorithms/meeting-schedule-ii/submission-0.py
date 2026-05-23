"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        starts=[]
        ends=[]

        for interval in intervals:
            starts.append(interval.start)
            ends.append(interval.end)
        
        p1=0
        p2=0
        starts.sort()
        ends.sort()
        total=len(intervals)
        counts=0
        curr=0
        while p1<total:
            if starts[p1]<ends[p2]:
                curr+=1
                p1+=1

            else:
                curr-=1
                p2+=1
            counts=max(curr,counts)

        return counts

        

        