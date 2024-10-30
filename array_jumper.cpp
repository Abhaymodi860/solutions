#include <iostream>
#include <vector>
using namespace std;

int minJumps(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0; // Already at the last index

    int jumps = 0, current_end = 0, farthest = 0;

    for (int i = 0; i < n - 1; ++i) {
        // Finding maximum reachable index
        if (i + nums[i] > farthest) {
            farthest = i + nums[i];
        }
        
        // When reaching the end of the current jump range
        if (i == current_end) {
            jumps++;
            current_end = farthest;
            if (current_end >= n - 1) break; // Reached the last index
        }
    }
    
    return jumps;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int result = minJumps(nums);
    cout << "Minimum number of jumps: " << result << endl;
    
    return 0;
}
