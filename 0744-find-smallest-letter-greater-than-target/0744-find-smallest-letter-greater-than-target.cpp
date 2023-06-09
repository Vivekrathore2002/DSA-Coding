class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int s = 0;
        int e = n-1;
        int count =0;
        int mid;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(target == letters[n-1]) return letters[0];
            if(letters[mid]>target){
                e=mid-1;
            }
            else if(letters[mid]==target){
                s=mid+1;
                // count++;
            }
            else{
                s=mid+1;
            }
        }
        if(s==n){
            return letters[0];
        }
        else{
            return letters[s];
        }
        // return 0;
    }
};