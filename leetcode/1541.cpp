class Solution {
public:
    int minInsertions(string s) {
        int bal = 0;
        int ans = 0;
        bool close = false;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                bal += 1;
            }else { 
                if(i+1 < s.size() && s[i+1] == ')') {
                    bal -= 1;
                    i++;
                }else {
                    ans++;
                    bal -= 1;
                }

                if(bal < 0) {
                    ans++;
                    bal = 0;
                }
            }
        }

        ans += bal*2;

        return ans;
    }
};
