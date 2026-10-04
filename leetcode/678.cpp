class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int ltr_no = 0;
        int ltr_nc = 0;
        int ltr_ns = 0;

        int rtl_no = 0;
        int rtl_nc = 0;
        int rtl_ns = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') ltr_no++;
            else if(s[i] == ')') ltr_nc++;
            else ltr_ns++;

            if(s[n-i-1] == '(') rtl_no++;
            else if(s[n-i-1] == ')') rtl_nc++;
            else rtl_ns++;

            if(ltr_nc > ltr_no+ltr_ns) return false;
            if(rtl_no > rtl_nc+rtl_ns) return false;
        }

        return true;
    }
};