class Solution:
    def findMin(self, nums: List[int]) -> int:
        l=0
        r=len(nums)-1
        while l<r:
            #what are the conditions for minimum
            #if its rotated zero time ie leftmost smaller than middle
            mid=(l+r)//2
            if nums[l]<=nums[r]:
                return nums[l]
            #if the rightmost element has a element smaller than the mid look right
            elif nums[mid]>nums[r]:
                l=mid+1
            else:
                r=mid
        return nums[l]
        
