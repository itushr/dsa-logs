class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> opening = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for(char c: s) {
            if(c == ')' || c == ']' || c == '}') {
                if(opening[c] == st.top()) {
                    st.pop();
                }else {
                    return false;
                }
            }else {
                st.push(c);
            }
        }

        if(!st.empty()) return false;
        return true;
    }
};