class Solution {
public:
    int numDecodings(string s) {
        if(s.size() < 2) {
            if(s[0] == '0') {
                return 0;
            }else {
                return 1;
            }
        }

        int a, b;

        int num;
        string str;

        if(s[0] == '0') {
            a = 0;
            b = 0;
        }else {
            a = 1;
            str = {s[0], s[1]};
            num = stoi(str);
            if(s[1] == '0') {
                if(num > 26) {
                    b = 0;
                }else {
                    b = 1;
                }
            }else if(num > 26) {
                b = 1;
            }else {
                b = 2;
            }
        }

        for(int i=2; i<s.size(); i++) {
            int tmp = a;
            a = b;
            str = {s[i-1], s[i]};
            num = stoi(str);

            if(s[i] == '0') {
                if(num < 10 || num > 26) {
                    b = 0;
                }else {
                    b = tmp;
                }
            }else {
                if(num > 10 && num <= 26) {
                    b += tmp;
                }
            }
        }

        return b;
    }
};