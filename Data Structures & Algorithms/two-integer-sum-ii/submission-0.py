class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # intuition is do the same thing as 2 sum but then while returning returning both+1
        f={}

        for i in range(len(numbers)):
            diff=target-numbers[i]

            if diff in f:
                return [f[diff]+1,i+1]
            
            f[numbers[i]]=i
            
        