class Solution {
public:
    int maxDepth(string s) {
        int curr = 0;
        int maxi = 0;

        for(char c: s) {
            if(c == '(') {
                curr++;
                maxi = max(maxi, curr);
            }else if(c == ')') {
                curr--;
            }
        }

        return maxi;
    }
};