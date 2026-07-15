class Solution {
public:
    int appendCharacters(string s, string t) {
        int p1=0;
        int p2=0;
        // see how many characters match
        while (p1!=s.size() && p2!=t.size()){
            if (s[p1]==t[p2]){
                p2+=1;
            }
            p1+=1;
        }

        return t.size()-p2;
        
    }
};