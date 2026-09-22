class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();

        if(l1 > l2) {
            return false;
        }

        int freq[26] = {0};
        
        for(char c: s1) {
            freq[c-'a']++;
        }

        int pl = 0;
        
        vector<int> changes;

        for(char c: s2) {
            if(freq[c-'a'] <= 0) {
                pl = 0;
                for(int change: changes) {
                    freq[change]++;
                }
                continue;
            }

            pl++;
            freq[c-'a']--;
            changes.push_back(c-'a');

            if(pl >= l1) {
                return true;
            }
        }

        return false;
    }
};