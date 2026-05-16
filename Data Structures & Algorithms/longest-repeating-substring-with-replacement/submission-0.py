from collections import defaultdict
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l=0
        r=0
        #we need a way to know which character occured the most frequently 
        f=defaultdict(int)
        maxFreq=0
        m=0
        while r<len(s):
            f[s[r]]+=1
            maxFreq = max(maxFreq, f[s[r]])
            while (r-l+1)>maxFreq+k:
                f[s[l]]-=1
                l+=1

            m=max(m,r-l+1)
            r+=1
        return m
            

            


            
            


        



            
        