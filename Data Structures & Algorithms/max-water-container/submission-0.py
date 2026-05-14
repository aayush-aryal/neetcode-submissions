class Solution:
    def maxArea(self, heights: List[int]) -> int:
        ma=0
        l=0
        r=len(heights)-1
        while l<r:
            height=min(heights[l],heights[r])
            width=r-l
            area=height*width
            ma=max(ma,area)
            if heights[l]>heights[r]:
                r-=1
            elif heights[r]>heights[l]:
                l+=1
            else:
                l+=1
                r-=1
        return ma
                
            
        