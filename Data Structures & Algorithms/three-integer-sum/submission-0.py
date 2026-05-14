from collections import defaultdict
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        #i think first step is to sort the list
        nums=sorted(nums)
        l=0
        r=len(nums)-1
        triplets=[]
        for i in range(len(nums)):
            l=i+1
            r=len(nums)-1
            while l<r:
                if nums[l]+nums[r]+nums[i]>0:
                    r-=1
                elif nums[l]+nums[r]+nums[i]<0:
                    l+=1
                else:
                    if nums[l]+nums[r]+nums[i]==0:
                        if [nums[i],nums[l],nums[r]] not in triplets:
                            triplets.append([nums[i],nums[l],nums[r]])
                        l+=1
                        r-=1
        return triplets

       


        
     

                
                

              

                
            

        

        

        