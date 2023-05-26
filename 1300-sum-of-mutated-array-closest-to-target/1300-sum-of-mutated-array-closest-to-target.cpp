class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n=arr.size(), i;
        // # Prefix Sum
        vector<int> presum;
        presum.push_back(arr[0]);
        for(i=1; i<n; ++i){
            presum.push_back(presum[i-1]+arr[i]);
        }
        int low=0, high=target;
        // # ans and diff initialized to max value.
        int ans=target+1, diff=target+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            auto ubound=upper_bound(arr.begin(), arr.end(), mid);
            if(ubound==arr.end()){
                int sum=presum[n-1];
                if(abs(target-sum)<diff){
                    diff=abs(target-sum);
                    ans=mid;
                }
                if(abs(target-sum)==diff){
                    ans=min(ans, mid);
                }
                // # As upper bound is at end, no need to increase value of mid
                high=mid-1;
            }
            else{
                int sum;
                if(ubound==arr.begin()){
                    // # Replace all elements of arr with mid.
                    sum=n*mid;
                }
                else{
                    int ind=ubound-arr.begin();
                    ind--;
                    sum=presum[ind]+((n-1-ind)*mid);
                }
                if(target-sum==0){
                    return mid;
                }
                if(target-sum>0){
                    if(target-sum<diff){
                        diff=target-sum;
                        ans=mid;
                    }
                    if(target-sum==diff){
                        ans=min(ans, mid);
                    }
                    // # As target>sum, we move ahead.
                    low=mid+1;
                }
                else{
                    if(sum-target<diff){
                        diff=sum-target;
                        ans=mid;
                    }
                    if(sum-target==diff){
                        ans=min(ans, mid);
                    }
                    // # As sum>target, we move backwards.
                    high=mid-1;
                }
            }
        }
        return ans;
    }   
};