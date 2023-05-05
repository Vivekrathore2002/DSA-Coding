class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr.push_back(nums[0]);
        for(int i=1 ; i<nums.size() ; i++)
        {
            arr.push_back(nums[i]+arr[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return arr[right];
        else
            return arr[right]-arr[left-1];
    }
};