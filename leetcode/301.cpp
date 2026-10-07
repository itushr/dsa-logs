class Solution {
public:
    unordered_set<string> ans;

    void duck(string &s, string cur, int i, int excess_opens, int excess_closes, int bal, int accept_length) {
        if(bal < 0) return;

        if(bal == 0 && cur.size() == accept_length) {
            ans.insert(cur);
            return;
        }

        if(i >= s.size()) return;

        if(s[i] == '(') {
            duck(s, cur+'(', i+1, excess_opens, excess_closes, bal+1, accept_length);
            if(excess_opens > 0) {
                duck(s, cur, i+1, excess_opens-1, excess_closes, bal, accept_length);
            }
        }else if(s[i] == ')') {
            duck(s, cur+')', i+1, excess_opens, excess_closes, bal-1, accept_length);
            if(excess_closes > 0) {
                duck(s, cur, i+1, excess_opens, excess_closes-1, bal, accept_length);
            }
        }else {
            duck(s, cur+s[i], i+1, excess_opens, excess_closes, bal, accept_length);
        }    
    }

    vector<string> removeInvalidParentheses(string s) {
        int excess_opens = 0;
        int excess_closes = 0;

        for(char c: s) {
            if(c == '(') {
                excess_opens++;
            } else if(c == ')') {
                if(excess_opens > 0) {
                    excess_opens--;
                } else {
                    excess_closes++;
                }
            }
        }

        int accept_length = s.size()-excess_opens-excess_closes;

        duck(s, "", 0, excess_opens, excess_closes, 0, accept_length);

        return vector<string>(ans.begin(), ans.end());
    }
};