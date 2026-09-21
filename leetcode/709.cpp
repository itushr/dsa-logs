class Solution {
public:
    string toLowerCase(string s) {
        int diff = (int)'a'-(int)'A';

        for(int i=0; i<s.size(); i++) {
            if(isupper(s[i])) {
                s[i] = s[i]+diff;
            }
        }

        return s;
    }
};