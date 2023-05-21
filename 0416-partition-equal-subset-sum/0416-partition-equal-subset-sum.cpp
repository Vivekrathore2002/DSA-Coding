class Solution {
    
    /*
        Time Complexity : O(n*target) + O(n)
        Space Complexity : O(target)
    */
    
private:
    int n;
    
    bool checkSubsetSum(vector<int>& nums, int sum){
        vector<bool> prev(sum+1, false);
        prev[0] = true;
        
        if(nums[0]<=sum) prev[nums[0]] = true;
        
        for(int idx=1; idx<n; idx++){
            vector<bool> curr(sum+1, false);
            
            for(int target=1; target<=sum; target++){
                bool notTake = prev[target];
                bool take = false;
                if(nums[idx]<=target){
                    take = prev[target-nums[idx]];
                }
                
                curr[target] = take or notTake;
            }   
            prev = curr;
        }
        
        return prev[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);
        
        if(totalSum%2) return false;
        
        return checkSubsetSum(nums, totalSum/2);
    }
};