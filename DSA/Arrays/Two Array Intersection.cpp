//https://www.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1?page=1&category=Arrays&company=Microsoft&sortBy=difficulty
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++

// Function to return the count of the number of elements in
// the intersection of two arrays.

class Solution {
  public:
    int numberofElementsInIntersection(vector<int> &a, vector<int> &b) {
        // Your code goes here
        unordered_map<int,int> hashmap;
        int count=0;
        
        for (auto it=a.begin(); it!=a.end(); it++)
        {
            hashmap[*it] = 1;
        }
        
        for (auto it=b.begin(); it!=b.end(); it++)
        {
            if (hashmap[*it])
                count += 1;
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        int res = ob.numberofElementsInIntersection(arr1, arr2);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends