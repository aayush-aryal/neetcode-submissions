class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #bucket sort seems about right
        #[[most frequent],["second most frequent"]...]
        #since it says o(n) space compelxity im not going to create a f map

        bucket=[[]for _ in range(len(nums)+1)]
        f={}
        for n in nums:
            if n not in f:
                f[n]=1
            else:
                f[n]+=1
        
        for key,v in f.items():
            bucket[v].append(key)
        res=[]
        for i in range(len(bucket)-1,0,-1):
            for n in bucket[i]:
                res.append(n)
                if len(res)==k:
                    return res
        

            





