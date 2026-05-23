"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:

        #intuition a meeting is overlapping if start time of one meeting is less than the end time of another meeting
        
        events=[]


        for i in intervals:
            events.append((i.start,1))
            events.append((i.end,-1))
        
        events.sort()
        curr_rooms=0
        max_rooms=0
        for time,room in events:
            curr_rooms+=room
            max_rooms=max(max_rooms,curr_rooms)
        
        return max_rooms
        


        

        