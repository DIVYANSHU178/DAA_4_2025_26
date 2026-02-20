class Solution {
  public:
    bool canPaint(vector<int>& arr, int k, long long limit) {
        long long curr = 0;
        int painters = 1;
        
        for (int len : arr) {
            if (len > limit) return false;
            if (curr + len <= limit) {
                curr += len;
            } else {
                painters++;
                curr = len;
            }
        }
        return painters <= k;
    }
    
    int minTime(vector<int>& arr, int k) {
        long long low = 0, high = 0;
        for (int len : arr) {
            low = max(low, (long long)len);
            high += len;
        }
        
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};
