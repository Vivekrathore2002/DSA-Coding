// https://www.youtube.com/watch?v=anuarmFjTGU&ab_channel=CodewithAlisha
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++)//Fixating the first element
        {
            int first = nums[i]; //first element
            //now start and end points 
            int start = i+1;
            int end=nums.size()-1;
            while(start<end){
                if(first+nums[start]+nums[end]==target) return target;
                else if(abs(first+nums[start]+nums[end]-target)<diff)
                {
                    diff=abs(first+nums[start]+nums[end]-target);
                    ans=first+nums[start]+nums[end];
                }
                if(first+nums[start]+nums[end]>target) end--; //After sorting the end element will have more value so we can decrease that
                else{
                    start++; //Start have less values,since target is big  so we will increase small small elements as from start in the sorted array
                }
            }
        }
        return ans;
    }
};