class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long sum = 0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        if (i >= s.size()) {
            return 0;
        }

        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }

        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            sum = sum * 10 + digit;

            if (sign * sum > INT_MAX) {
                return INT_MAX;
            }

            if (sign * sum < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * sum;
    }
};