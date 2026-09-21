class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size();
        int l2 = needle.size();

        for(int i=0; i<=l1-l2; i++) {
            for(int j=0; j<l2; j++) {
                if(haystack[i+j] != needle[j]) {
                    break;
                }

                if(j == l2-1) {
                    return i;
                }
            }
        }

        return -1;
    }
};