class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>ans;
    sort(nums.begin() , nums.end());
    for(int i= 0 ; i<nums.size()-2; i++){
         
        if(i == 0 || (i>0 && nums[i]!= nums[i-1])){
            
  //kyuki agar i = 0 ha to hum i-1 nhi lga skte h na boss isleye hmne kya kai hmne condition dal di ha agar i = 0 ha to sidhe chle jao nhi h to check krlo kya i or i-1 eleent same to nhi h kyuki agar vo same h to koi faida nhi h same ke lia bar bar check krne se 
            
            int low = i+1;
            int high = nums.size()-1;
            int sum = 0 - nums[i];
            while(low < high){
                 
                if(nums[low] + nums[high] == sum){
                      vector<int>x;
                    x.push_back(nums[i]);
                    x.push_back(nums[low]);
                    x.push_back(nums[high]);
                    ans.push_back(x);
                    
                    while(low<high && nums[low] == nums[low+1])
                        low++; 
                    while(low<high && nums[high] == nums[high-1])
                        high--;
                        
                    low++; high--;
                }
                
                else if (nums[low] + nums[high] < sum){
                       low++;
                }
                else
                    high--;
            }
            
        }
    }
    return ans;
}
};