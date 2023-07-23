class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i=0;
        int n=nums.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[(i+k)%n] = nums[i];
        }
        nums=temp;
    }
};