class Solution {
public:
    string largestOddNumber(string num) {
        string maxi="";
        for(int i=num.length()-1;i>=0;i--){
            int number=num[i]-'0';
            if(number%2!=0){
                maxi=num.substr(0,i+1);
                break;
            }
        }
        return maxi;
        }
};