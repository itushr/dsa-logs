class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        priority_queue<pair<int, int>> q;
        vector<int> diff(n, 0);

        for(int i=0; i<n; i++) {
            diff[i] = abs(nums1[i]-nums2[i]);
            q.push({diff[i], i});
        }

        while(k1 > 0) {
            auto [absdiff, idx] = q.top();
            q.pop();
            
            if(absdiff == 0) break;

            int jump = absdiff-q.top().first;

            if(jump > 0) {
                diff[idx] -= min(k1, jump);
                k1 -= jump;
            }else {
                diff[idx] -= 1;
                k1 -= 1;
            }

            q.push({diff[idx], idx});
        }

        while(k2 > 0) {
            auto [absdiff, idx] = q.top();
            q.pop();
            
            if(absdiff == 0) break;

            int jump = absdiff-q.top().first;

            if(jump > 0) {
                diff[idx] -= min(k2, jump);
                k2 -= jump;
            }else {
                diff[idx] -= 1;
                k2 -= 1;
            }

            q.push({diff[idx], idx});
        }

        long long ans = 0;

        for(int dif: diff) {
            ans += 1LL*dif*dif;
        }

        return ans;
    }
};