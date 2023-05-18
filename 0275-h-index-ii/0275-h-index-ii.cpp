// class Solution {
// public:
// bool isH(int h,vector<int>& citations){
//     int count=citations.size();
//     for(auto citation : citations){
//         if(count>h){
//             count=count-1;
//         }
//         if(count<h){
//             return false;
//         }
//         return true;
//     }
// }
//     int hIndex(vector<int>& citations) {
        
//         int s=0;
//         int e=citations.size();
//         int i=0;
//         while(s<=e){
//             int mid=s=(e-s)/2;
//             if(isH(mid,citations)){
                
//             }
//         }        
//     }
// };


class Solution {
public:
    int hIndex(vector<int>& citations) {
        // ios::sync_with_stdio(0);
        // cin.tie(NULL);
        
        int n = citations.size();
        int low=0,high=n-1,mid;
        
        while(low<=high)
        {
            mid = low+(high-low)/2;
            if(citations[mid]==(n-mid))
                return citations[mid];
            else if(citations[mid]>(n-mid))
                high = mid-1;
            else
                low = mid+1;
        }
        return n-low;
    }
};