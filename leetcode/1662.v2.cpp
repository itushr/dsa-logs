class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1 = 0;
        int i2 = 0;
        int j1 = 0;
        int j2 = 0;

        while(i1 < word1.size() && i2 < word2.size()) {
            if(word1[i1][j1] != word2[i2][j2]) {
                return false;
            }

            if(j1 < word1[i1].size()-1) {
                j1++;
            }else {
                i1++;
                j1 = 0;
            }

            if(j2 < word2[i2].size()-1) {
                j2++;
            }else {
                i2++;
                j2 = 0;
            }
        }

        if(i1 < word1.size() || i2 < word2.size()) {
            return false;
        }

        return true;
    }
};