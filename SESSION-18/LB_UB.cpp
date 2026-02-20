#include <iostream>
#include <vector>
using namespace std;

int findLower(int f, int l, int x, const vector<int>& arr) {
    int ans = -1;
    if(x==arr[l]) return l;
    while (f <= l) {
        int mid = f + (l - f) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            l = mid - 1;
        } else {
            f = mid + 1;
        }
    }
    return ans;
}

int findUpper(int f, int l, int x, const vector<int>& arr) {
    int ans = -1;
    if(x==arr[l]) return l+1;
    while (f <= l) {
        int mid = f + (l - f) / 2;
        if (arr[mid] > x) {
            ans = mid;
            l = mid - 1;
        } else {
            f = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int x;
    cout << "Enter the element to find its occurrence: ";
    cin >> x;

    int first = findLower(0, n - 1, x, arr);
    int last = findUpper(0, n - 1, x, arr) - 1;
    int count = (last-first)+1;
    cout << "Occurrence of " << x << " is " << count << endl;
    return 0;
}
