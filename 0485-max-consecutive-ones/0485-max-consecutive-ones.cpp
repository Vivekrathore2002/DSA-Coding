class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int count=1;
        int maxi=1;
        // if(n=1 && nums[n-1]==0){
        //     maxi=0;
        // }
        // else if(n=1 && nums[n-1]==1){
        //     maxi=1;
        // }
        if(n==1 && nums[i]==1){
                maxi=1;
            }
            else if(n==1 && nums[i]==0){
                maxi=0;
            }
            else if(n==2 && nums[i]==0 && nums[i+1]==0){
                maxi=0;
            }


        while(i<n-1){
            // if(n=1 && nums[i]==1){
            //     maxi=1;
            // }
            // else if(n=1 && nums[i]==0){
            //     maxi=0;
            // }
            if(nums[i]==1 && nums[i+1]==1){
                // int count=1;
                count=count+1;
                maxi=max(count,maxi);
                i++;
            }
            else{
                count=1;
                i++;
            }
        }
        return maxi;
    }
};