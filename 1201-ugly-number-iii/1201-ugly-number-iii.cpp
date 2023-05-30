// just for the concept - https://www.youtube.com/watch?v=Rl4PznQDz3o&ab_channel=KelvinChandra
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // Calculate the least common multiple (LCM) of a, b, and c
        long long lcm_ab = lcm(a, b);
        long long lcm_ac = lcm(a, c);
        long long lcm_bc = lcm(b, c);
        long long lcm_abc = lcm(lcm_ab, c);

        // Binary search on the range [1, 2 * 10^9] to find the nth ugly number
        long long left = 1;
        long long right = 2e9;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long count = mid / a + mid / b + mid / c - mid / lcm_ab - mid / lcm_ac - mid / lcm_bc + mid / lcm_abc;

            if (count < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

private:
    // Function to calculate the least common multiple (LCM) of two numbers
    long long lcm(long long a, long long b) {
        return (a * b) / gcd(a, b);
    }

    // Function to calculate the greatest common divisor (GCD) of two numbers
    long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};
