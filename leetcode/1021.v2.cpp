class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count = 0;

        for(char c: s) {
            if(c == '(') {
                count++;
            }else{
                count--;
            }

            if(count == 1 && c == '(') continue;
            if(count == 0 && c == ')') continue;

            ans += c;
        }

        return ans;
    }
};