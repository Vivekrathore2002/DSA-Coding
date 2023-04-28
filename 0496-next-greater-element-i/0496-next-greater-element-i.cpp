class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        for(auto i:nums1)
        {
            int k=0;
            for(int j=(find(nums2.begin(),nums2.end(),i)-nums2.begin());j<nums2.size();j++)
                if(i<nums2[j])
                {
                    a.push_back(nums2[j]);
                    k=1;
                    break;
                }
            if(k==0)
                a.push_back(-1);
        }
        return a;
    }
};