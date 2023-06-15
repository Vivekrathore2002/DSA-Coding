//This code is correct but idk why it is giving runtime error also it is giving runtime error to  other ppl solved answers given in solutions here also. May be a glitch
// But it is getting submitted but when we run it,it gives runtime error
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
				int count = 0;
				int i =0;
				int j=nums.size()-1;
				while(i<j){
					if(nums[i]+nums[j]==k){
						count++;
						i++;
						j--;
					}
					else if(nums[i]+nums[j]<k){
						i++;
					}
					else{
						j--;
					}
				}
				return count;
    }
};

// other approach by : 
// https://www.youtube.com/watch?v=ro-8bPE-ozk&ab_channel=TechAdorabyNivedita

// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//       unordered_map<int,int>mp;
//         int count=0;
//     for(auto x:nums)
//     {
//         if(mp[k-x])
//         {
//             mp[(k-x)]--;
//             mp[x]--;
//             count++;
//         }
//         mp[x]++;
//     }
//         return count;
//     }
// };
