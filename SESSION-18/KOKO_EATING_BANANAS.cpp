class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int result = right;
        
        while (left <= right) {
            int speed = left + (right - left) / 2;
            long long total_hours = 0;
            
            for (int pile : piles) {
                total_hours += (pile + speed - 1) / speed;
            }
            
            if (total_hours <= h) {
                result = speed;
                right = speed - 1;
            } else {
                left = speed + 1;
            }
        }
        return result;
    }
};
