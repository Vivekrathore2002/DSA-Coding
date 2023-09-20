// https://www.youtube.com/watch?v=REFsN16JpBo
// for 1 1 4 2 3 total sum is 11 and we have to make 0 of x = 5
//if we are getting a contigous sub array which have the sum as target-x means 6
//then we would simply maximise the length of sub array to minimise the length of rest of array
//here as we know the sub array with highest length and sum equal to 6 would be 1 1 4
//start with two pointers at start names start and end
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int start =0;
        int end =0;
        int totalsum = accumulate(nums.begin(),nums.end(),0); 
        int sum_to_make = totalsum - x; 
        if(totalsum==x)return nums.size();
        int ans = 0;
        int sum =0;
        
        while(end<nums.size())
        {  sum+=nums[end];   
         while(start<end && sum>sum_to_make) 
         {
             sum-=nums[start++]; 
         }
         if(sum==sum_to_make) 
         {
             ans = max(ans,end-start+1); 
         }
           end++;   
        }
        return ans==0 ? -1 : nums.size()-ans;
    }
};
