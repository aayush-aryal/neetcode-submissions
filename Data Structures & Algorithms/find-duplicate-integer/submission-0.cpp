class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // [1,-2,3,2,2]
        int index= 0;
        bool duplicate= false;
        // treat each entry as index
        while (!duplicate){
            std::cout<<index;
            if (nums[index]<=0){
                // this means this is visited 
                return  index;
            }
            // save index
            int temp = nums[index];
            // curr index is visited so -1
            nums[index]= -1*nums[index];
            // next index to check
            index=temp;
             
        } 
        return 0;       
    }
};
