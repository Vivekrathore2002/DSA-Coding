// https://www.youtube.com/watch?v=2I9XO8jwZCA
class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int i = 0;
        int sign = 1;

        // Handle leading spaces
        while (s[i] == ' ') {
            i++;
        }

        // Check the sign of the string
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        // Traverse the string and convert it into an integer
        while (s[i] >= '0' && s[i] <= '9') {
            // Check for integer overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (s[i] - '0');
            i++;
        }

        return result * sign;
    }
};
