class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        #permutation in string means a string s2 contains all strings in s1 in a s1 l block in any order
        # for this we need to know occurence of strings from s1 and compare it to s2
        #since we want o(1) lookups with o(1) space we need fixed sizze arrays
        s1l=len(s1)
        s2l=len(s2)
        fs1=[0 for i in range(26)]
        fs2=[0 for i in range(26)]
        for s in s1:
            fs1[ord(s)-ord('a')]+=1
        l=0
        r=0
        while r<s2l:
            fs2[ord(s2[r])-ord('a')]+=1
            if r-l+1==s1l:
                if fs2==fs1:
                    return True 
                else:
                    fs2[ord(s2[l])-ord('a')]-=1
                    l+=1
            r+=1
        return False
        




        

        