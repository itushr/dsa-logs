class Solution {
public:
    vector<string> ans;

    void duck(string yet, int n, int nopen, int nclose) {
        if(nclose > nopen) return;
        if(nopen > n) return;

        if(nopen == n && nclose == n) {
            ans.push_back(yet);
            return;
        }

        duck(yet+'(', n, nopen+1, nclose);
        duck(yet+')', n, nopen, nclose+1);
    }

    vector<string> generateParenthesis(int n) {
        duck("", n, 0, 0);
        return ans;
    }
};