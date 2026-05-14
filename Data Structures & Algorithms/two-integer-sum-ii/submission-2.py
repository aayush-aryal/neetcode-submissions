class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # intuition is do the same thing as 2 sum but then while returning returning both+1
        #O(1) additional space requirement

        #since they are sorted 
        #can adjust pointers based on if its larger or smaller than target

        l=0
        r=len(numbers)-1

        while l<r:
            total=numbers[l]+numbers[r]
            if total>target:
                r-=1
            if total<target:
                l+=1
            if total==target:
                return [l+1,r+1]
        

        