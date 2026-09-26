class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> ump;
        string ans;

        for(int i=0; i<knowledge.size(); i++) {
            ump[knowledge[i][0]] = knowledge[i][1];
        }

        int x=0;

        while(x < s.size()) {
            if(s[x] != '(') {
                ans += s[x];
                x++;
                continue;
            }

            x++;

            string key = "";

            while(s[x] != ')') {
                key += s[x];
                x++;
            }

            if(ump.find(key) != ump.end()) {
                ans += ump[key];
            } else {
                ans += '?';
            }

            x++;
        }

        return ans;
    }
};