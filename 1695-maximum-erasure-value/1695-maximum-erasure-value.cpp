// https://www.youtube.com/watch?v=WG6Kok6tIyg&ab_channel=CodewithAlisha

// for example there was an array [4,2,4,5,6]
// first start and end will start from  0 index means 4
//     they will check whether the element is present in the set or not;
//     if not than direct insert(not go to 2nd while loop)
//     else the loop will be executed since the element was found before coming to the end
//     if loop executed once than we go to 1st loop further,
//     for example 4 will repeat than simply loop will minus the 4 from sum 
//     and new 4 will be added to the sum after end of 2nd while loop
// if by chance the sum gets lower from the last iteration such as given in the video than the max value will be taken to return
    
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start,end,ans,sum=0;
        set<int>s;
        while(end<nums.size())
        {
            while(start<end && s.find(nums[end])!=s.end())
            {
                s.erase(nums[start]);
                sum-=nums[start];
                start++;
            }
            s.insert(nums[end]);
            sum+=nums[end];
            end++;
            ans=max(ans,sum);
        }
        return ans;
    }
};




    