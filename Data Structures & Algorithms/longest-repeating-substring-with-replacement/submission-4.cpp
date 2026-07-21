class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        unordered_map<char,int> f;
        int maximum=0;
        int max_char=0;
        while (r<s.size()){
            f[s[r]]++;
            max_char=std::max(max_char,f[s[r]]);
            // this can be the new highest repeating character now
            while (r-l+1-max_char>k){
                f[s[l]]--;
                if (f[s[l]]<=0){
                    f.erase(s[l]);
                }
                l++;
            }
            maximum=max(maximum,r-l+1);
            r+=1;
        }
        return maximum;
        
    }
};
