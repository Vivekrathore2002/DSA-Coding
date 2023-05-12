// //Chatgpt
// class Solution {
// public:
//     int chalkReplacer(vector<int>& chalk, int k) {
//         int n = chalk.size();
//         long long sum = accumulate(chalk.begin(), chalk.end(), 0LL); // use accumulate to get the sum of all elements in chalk array
//         k %= sum; // reduce k to the range of one cycle of chalk distribution
//         int j = 0;
//         while (k >= chalk[j]) { // check if k is greater than or equal to the current element in chalk
//             k -= chalk[j];
//             j++;
//             if (j == n) j = 0; // if j goes beyond n, start again from 0
//         }
//         return j;
//     }
// };


//mine
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += chalk[i];
        }
        k %= sum;
        int j = 0;
        while(k >= 0){
            k -= chalk[j];
            if(k < 0){
                break;
            }
            j++;
            if(j == n){
                j = 0;
            }
        }
        return j;
    }
};

