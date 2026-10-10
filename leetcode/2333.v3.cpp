class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL*k1 + 1LL*k2;

        vector<int> diff(n);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        vector<long long> freq(mx + 1, 0);

        for (int x : diff) {
            freq[x]++;
        }

        for (int d = mx; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;

            long long allowed = min(k, freq[d]);

            freq[d] -= allowed;
            freq[d - 1] += allowed;

            k -= allowed;
        }

        while (k > 0) {
            int d = 0;

            while (d < mx && freq[d] == 0)
                d++;

            if (d == 0)
                break;

            long long use = min(k, freq[d]);

            freq[d] -= use;
            freq[d - 1] += use;
            k -= use;
        }

        long long ans = 0;

        for (long long d = 1; d <= mx; d++) {
            ans += d * d * freq[d];
        }

        return ans;
    }
};