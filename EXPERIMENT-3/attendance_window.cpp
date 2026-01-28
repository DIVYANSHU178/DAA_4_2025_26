#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<int, int> mp;
    mp[0] = -1;
    
    int sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        sum += (c == 'P' ? 1 : -1);
        
        auto it = mp.find(sum);
        if(it != mp.end()) {
            ans = max(ans, i - it->second);
        } else {
            mp[sum] = i;
        }
    }
    
    cout << ans << endl;
    return 0;
}
