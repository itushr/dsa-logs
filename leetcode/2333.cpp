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

        for(int i=0; i<k1; i++) {
            auto [absdiff, idx] = q.top();
            q.pop();
            
            if(absdiff == 0) break;

            diff[idx] -= 1;
            q.push({diff[idx], idx});
        }

        for(int i=0; i<k2; i++) {
            auto [absdiff, idx] = q.top();
            q.pop();
            
            if(absdiff == 0) break;

            diff[idx] -= 1;
            q.push({diff[idx], idx});
        }

        long long ans = 0;

        for(int dif: diff) {
            ans += 1LL*dif*dif;
        }

        return ans;
    }
};