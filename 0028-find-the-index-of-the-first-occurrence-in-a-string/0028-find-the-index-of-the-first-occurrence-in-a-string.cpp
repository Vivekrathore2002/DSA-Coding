class Solution {
public:
    int strStr(string haystack, string needle) {
        //my code
        int n=haystack.size();
        int m=needle.size();
        int i=0;
        int j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                if(j==(m-1)){
                    return i-m+1;
                }
                else{
                    i++;
                    j++;
                }              
            }
            else{ 
                // i++;
                i = i - j + 1;
                j=0;              
            }
        }
        return -1;
    }
};