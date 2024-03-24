#include <bits/stdc++.h> 
using namespace std; 
  
int findMin(vector<int>& arr, int low, int high) 
{ 
    // If the array is not rotated 
    if (arr[low] < arr[high]) { 
        return arr[low]; 
    } 
    int ans = 1e9; 
    // Binary search 
    while (low <= high) { 
        int mid = (low + high) / 2; 
        // if left most element is equal with right most and 
        // middle element then we can reduce the search 
        // space only by increasing the lower limit and 
        // decreasing the upper limit 
        if (arr[mid] == arr[low] 
            and arr[mid] == arr[high]) { 
            ans = min(ans,arr[mid]); 
            low++; 
            high--; 
        } 
        // If the left half is sorted, the minimum element 
        // must be in the right half 
        else if (arr[mid] > arr[high]) { 
            low = mid + 1; 
        } 
  
        // If the right half is sorted, the minimum element 
        // must be in the left half 
        else { 
            ans = min(ans,arr[mid]); 
            high = mid - 1; 
        } 
    } 
  
    // If no minimum element is found, return -1 
    return ans; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6}; 
    int N = arr.size(); 
    cout << "The minimum element is "
         << findMin(arr, 0, N - 1) << endl; 
    return 0; 
}