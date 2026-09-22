class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();

        if(l1 > l2) return false;

        int freq[26] = {0};

        for(char c: s1) {
            freq[c-'a']++;
        }

        int wl = 0;
        int wr = 0;

        while(wr < s2.size()) {
            if(freq[s2[wr]-'a'] > 0) {
                freq[s2[wr]-'a']--;

                if(wr-wl+1 >= l1) {
                    return true;
                }
                
                wr++;
                continue;
            }

            while(freq[s2[wr]-'a'] <= 0) {
                freq[s2[wl]-'a']++;
                wl++;
            }
        }

        return false;
    }
};