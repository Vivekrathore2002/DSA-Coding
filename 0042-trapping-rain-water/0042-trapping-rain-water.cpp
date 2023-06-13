// https://www.youtube.com/watch?v=Lrp9v-NQPXw&t=40s&ab_channel=CodewithAlisha
// same que is also there in gfg

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans =0;
        int left = 0;
        int right = n-1;
        int leftbar=height[0];
        int rightbar=height[n-1];
        while(left<right)
        {
            //which bar is limiting bar?
            //left,right?
            if(leftbar<rightbar)
            {
                if(height[left]>leftbar)
                leftbar=height[left];
                else
                {
                    ans+=leftbar-height[left];
                    left++;
                }
            }
            else
            {
                if(height[right]>rightbar)
                rightbar=height[right];
                else
                {
                    ans+=rightbar-height[right];
                    right--;
                }
            }
        }
        return ans;
    }
};