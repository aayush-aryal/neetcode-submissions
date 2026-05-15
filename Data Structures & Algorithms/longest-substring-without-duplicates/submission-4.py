class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l=0
        r=0
        if len(s)==1:
            return 1
        seen=set()
        m=0
        while r<len(s):
            if s[r] not in seen:
                m=max(m,r-l+1)
                seen.add(s[r])
                r+=1
            else:
                #shrink window
                while s[r] in seen:
                    seen.remove(s[l])
                    l+=1
        return m


            


        
        