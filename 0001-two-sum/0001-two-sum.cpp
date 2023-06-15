class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res,store;
    	store = nums;

    	sort(store.begin(), store.end());

    	int left=0,right=nums.size()-1;
    	int n1,n2;

    	while(left<right){
        	if(store[left]+store[right]==target){

            	n1 = store[left];
            	n2 = store[right];

            	break;

        	}
        	else if(store[left]+store[right]>target)
            	    right--;
        	else
            	    left++;
    	}

    	for(int i=0;i<nums.size();++i){

        	if(nums[i]==n1)
            	    res.push_back(i);
        	else if(nums[i]==n2)
            	    res.push_back(i);
    	}

    	    return res;
    }
    
    
};