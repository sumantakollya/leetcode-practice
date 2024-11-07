//https://www.geeksforgeeks.org/problems/third-largest-element/1?page=1&category=Arrays&company=Microsoft&sortBy=difficulty
//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // Your code here
        int max = -1;
        vector<int>::iterator max_ptr;
        
        if (arr.size() < 3)
            return -1;

        for (auto it=arr.begin(); it!=arr.end(); it++)
        {
            if (*it > max)
            {
                max = *it;
                max_ptr = it;
            }
        }
        
        *max_ptr = -1;
        max = -1;
        for (auto it=arr.begin(); it!=arr.end(); it++)
        {
            if (*it > max)
            {
                max = *it;
                max_ptr = it;
            }
        }
        
        *max_ptr = -1;
        max = -1;
        for (auto it=arr.begin(); it!=arr.end(); it++)
        {
            if (*it > max)
            {
                max = *it;
                max_ptr = it;
            }
        }
        
        return max;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.thirdLargest(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends