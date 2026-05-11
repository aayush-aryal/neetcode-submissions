class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # freq map to keep track of what we have seen 
        f={}

        for i in range(len(nums)):
            #if we alr have the second number we require in f
            diff=target-nums[i]
            if diff in f:
                return [f[diff],i]
            else:
                f[nums[i]]=i
        return []