#include <algorithm>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // we need to know maximum bananas that is in the pile
        int total=0;
        int maximum=0;
        for (int pile:piles){
            total+=pile;
            maximum=max(maximum,pile);
        }
        int l=1;
        int r=maximum;
        int rate=maximum;
        int hours=0;
        while (l<=r){
            int mid=(l+r)/2;
            int currHours=0;
            for (int pile:piles){
                currHours+=ceil((double)pile/mid);
            }
            if (currHours<=h){
                // decrease speed
                r=mid-1;
                rate=min(rate,mid);
                
            }else{
                l=mid+1;
            }
        }
        return rate;

        
    }
};
