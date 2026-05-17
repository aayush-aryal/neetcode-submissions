class Solution {
public:
    int characterReplacement(string s, int k) {
        // need a frequency map 
        // can be a 26 sized array 
        int fMap[26]={0};
        //sliding window problem
        int l=0;
        int r=0;

        int max_freq=0;

        int longest=0;
        while (r<s.size()){
            fMap[s[r]-'A']+=1;
            max_freq = max(max_freq,fMap[s[r]-'A']);
            while (r-l+1>k+max_freq){
                fMap[s[l]-'A']-=1;
                l+=1;
            }
            // now we have a valid
            longest=max(longest,r-l+1);
            r+=1;
        }

        return longest;
    }
};
