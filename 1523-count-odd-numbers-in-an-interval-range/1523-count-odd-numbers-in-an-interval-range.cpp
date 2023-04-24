class Solution {
public:
    int countOdds(int low, int high) {
        int i=low;
        int n=high;
        int count=0;
        for(i;i<=n;i++){
            if(i%2!=0){
                count++;
            }
        }
        return count;
    }
};