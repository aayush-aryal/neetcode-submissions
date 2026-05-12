class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # intuition is using prefix and postfix sum
        #[1,2,4,6] for this calculate its prefix ie multiple of every number before it 
        res=[1]*len(nums)
        prefix=1
        for i in range(len(nums)):
            res[i]=prefix
            prefix*=nums[i]
        
        # update postfix now
        postfix=1

        for i in range(len(nums)-1,-1,-1):
            res[i]*=postfix
            postfix*=nums[i]
        
        return res

            
            

