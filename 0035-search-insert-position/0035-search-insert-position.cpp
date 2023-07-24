class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //to find the given position
        int n=nums.size();
        int key;
        for(int i=0;i<n;i++){
            if(nums[i]==target || nums[i]>target){
                key=i;
                break;
                // return key;
            }
        }
        // int i=0;
        // while(key==-1 && i<n){
        //     if(nums[i]<target){
        //         i++;
        //     }
        //     key=i;
        // }
        // if(i==n){
        //     key==n;
        // }
        return key;
    }
};