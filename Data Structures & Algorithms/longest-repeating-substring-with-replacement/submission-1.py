from collections import defaultdict
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l=0
        r=0
        #we need a way to know which character occured the most frequently 
        f=defaultdict(int)
        longest_char=0
        longest=0
        while r<len(s):
            f[s[r]]+=1
            longest_char=max(longest_char,f[s[r]])
            #if the window is bigger than repeat+longest character
            while (r-l+1)>k+longest_char:
                #update freq map since it isnt included in our window
                f[s[l]]-=1
                #shrink window
                l+=1
            longest=max(longest,r-l+1)
            r+=1
        return longest
            

        

            


            
            


        



            
        