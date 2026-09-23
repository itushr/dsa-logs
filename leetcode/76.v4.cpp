class Solution {
public:
    string minWindow(string s, string t) {
        int tfreq[255] = {0};
        int sfreq[255] = {0};

        for (char c : t) {
            tfreq[c]++;
        }

        int wl = 0;
        int wr = 0;
        int wmin = INT_MAX;
        int wminl = 0;
        int wminr = 0;
        int ntnodes = 0;

        while (wr < s.size()) {
            sfreq[s[wr]]++;

            if(ntnodes < t.size() && tfreq[s[wr]] > 0 && sfreq[s[wr]] <= tfreq[s[wr]]) {
                ntnodes++;
            }

            while (wl<wr && sfreq[s[wl]] > tfreq[s[wl]]) {
                sfreq[s[wl]]--;
                wl++;
            }


            if(ntnodes >= t.size() && wr-wl+1 < wmin) {
                wmin = wr-wl+1;
                wminl = wl;
                wminr = wr;
            }

            wr++;
        }

        if(ntnodes < t.size()) {
            return "";
        }

        return s.substr(wminl, wmin);
    }
};