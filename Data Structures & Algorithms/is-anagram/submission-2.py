class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # naive approach using set and len does not work
        #using a frequency map to store freq and letter for each string 

        if len(s)!=len(t):
            return False
        f1={}
        for st in s:
            if st not in f1:
                f1[st]=1
            else:
                f1[st]+=1
        

        f2={}
        for st in t:
            if st not in f2:
                f2[st]=1
            else:
                f2[st]+=1
        
        # now enumerate through f1 and check f2
        for k,v in f1.items():
            print (k,v)
            if k not in f2 or f2[k]!=v:
                return False 
        return True 
        
        