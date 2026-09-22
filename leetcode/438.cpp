class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int freq[26] = {0};

        vector<int> ans;

        for(char c: p) {
            freq[c-'a']++;
        }

        int wl = 0;
        int wr = 0;

        while(wr < s.size()) {
            if(freq[s[wr]-'a'] > 0) {
                freq[s[wr]-'a']--;
                
                if(wr-wl+1 == p.size()) {
                    ans.push_back(wl);
                }

                wr++;
                continue;
            }

            while(freq[s[wr]-'a'] <= 0) {
                freq[s[wl]-'a']++;
                wl++;
            }
        }

        return ans;
    }
};