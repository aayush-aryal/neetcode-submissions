from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #group anagrams into sublist 
        #an anagram consists of same characters in different order
        # have a key value pair freq map that has characters in a fixed order (asc or des): words that match this

        f=defaultdict(list)
        for s in strs:
            #order the words in ascending
            k=tuple(sorted(s))
            f[k].append(s)
        
        final=[]
        for _,v in f.items():
            final.append(v)
        
        return final







        