class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<int> st;
        vector<int> ans;

        for(char c: seq) {
            if(c == '(') {
                if(!st.empty() && st.top() == 0) {
                    ans.push_back(1);
                    st.push(1);
                }else {
                    ans.push_back(0);
                    st.push(0);
                }
            }else {
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};