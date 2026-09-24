class Solution {
public:
    int numDecodings(string s) {
        int a;
        int b;

        string x;

        if(s.size() == 1){
            if(s[0] == '0') {
                return 0;
            }else{
                return 1;
            }
        }

        if(s[0] == '0') {
            a = 0;
            b = 0;
        }else{
            a = 1;
            x = {s[0], s[1]};
            if(s[1] == '0') {
                b = 1;
            }else if(stoi(x) > 26) {
                b = 1;
            }else {
                b = 2;
            }
        }

        for(int i=2; i<s.size(); i++) {
            int tmp = a;
            a = b;
                x = {s[i-1], s[i]};
            if(s[i] == '0') {
                if(s[i-1] == '0') {
                    b = 0;
                }else if(stoi(x) <= 26) {
                    b = tmp;
                } else {
                    b = 0;
                }
            }else{
                if(s[i-1] != '0' && stoi(x) <= 26) {
                    b += tmp;
                }
            }
        }

        return b;
    }
};