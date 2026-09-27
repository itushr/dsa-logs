class Solution {
public:
    void reverse(string &s, int start, int end) {
        if(start >= end) return;
        swap(s[start], s[end]);
        reverse(s, ++start, --end);
    }

    string reverseParentheses(string s) {
        stack<int> st;
        string ans = "";

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                st.push(i+1);
            }else if(s[i] == ')') {
                reverse(s, st.top(), i-1);
                st.pop();
            }
        }

        for(char c: s) {
            if(c != '(' && c!= ')') {
                ans += c;
            }
        }

        return ans;
    }
};