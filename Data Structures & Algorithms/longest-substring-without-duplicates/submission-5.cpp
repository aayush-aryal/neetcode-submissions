class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        unordered_set<char> curr;
        int maximum=0;
        while (r<s.size()){
            while (curr.find(s[r])!=curr.end()){
                curr.erase(s[l]);
                l+=1;
            }
            // now the window is valid 
            maximum=std::max(maximum,r-l+1);
            curr.insert(s[r]);
            r+=1;
        }
        return maximum;
        
    }
};
