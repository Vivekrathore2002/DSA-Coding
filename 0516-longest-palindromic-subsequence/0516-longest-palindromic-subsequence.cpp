//Striver and love babbar approach
class Solution {
public:
int solve(string& a, string& b){
        int n1 = a.length();
        int n2 = b.length();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        vector<int> currRow(n2+1, 0);
        vector<int> nextRow(n2+1, 0);

        for(int i = n1-1; i>=0; i--){
            for(int j = n2-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j])
                    ans = 1 + nextRow[j+1];
                else
                {
                    ans = max(nextRow[j], currRow[j+1]);
                }
                currRow[j] = ans;
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int longestPalindromeSubseq(string s1) {
        string revStr = s1;
        reverse(revStr.begin(),revStr.end());
        int ans = solve(s1,revStr);
        return ans;
    }
};