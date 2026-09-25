class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int minsum = triangle[0][0];
        vector<int> minis = {0};

        for(int i=1; i<triangle.size(); i++) {
            int curri = minis[0];
            vector<int> currminis = {curri};

            for(int mini: minis) {
                if(mini > curri) {
                    if(triangle[i][mini] < triangle[i][curri]) {
                        curri = mini;
                        currminis.clear();
                        currminis.push_back(mini);
                    }else if(triangle[i][mini] == triangle[i][curri]) {
                        curri = mini;
                        currminis.push_back(mini);
                    }
                }

                if(mini+1 > curri) {
                    if(triangle[i][mini+1] < triangle[i][curri]) {
                        curri = mini+1;
                        currminis.clear();
                        currminis.push_back(mini+1);
                    }else if(triangle[i][mini+1] == triangle[i][curri]) {
                        curri = mini+1;
                        currminis.push_back(mini+1);
                    }
                }
            }

            minis = currminis;
            minsum += triangle[i][curri];
        }

        return minsum;
    }
};