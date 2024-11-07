//https://www.geeksforgeeks.org/problems/wave-array-1587115621/1?page=1&category=Arrays&company=Microsoft&sortBy=difficulty
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// #include <algorithm>


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr) {
        // code here
        vector<int> res(arr.size(),0);
        int resi=0;
        for (int i=1; i<arr.size(); i+=2)
        {
            res[resi++]=arr[i];
            res[resi++]=arr[i-1];
        }
        
        if(arr.size()%2)
            res[resi] = arr[arr.size()-1];
        
        for(int i=0;i<arr.size();i++)
            arr[i]=res[i];
    }
};

//{ Driver Code Starts.

int main() {

    int t, n;
    cin >> t; // Input testcases
    cin.ignore();
    while (t--) // While testcases exist
    {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        sort(a.begin(), a.end());
        Solution ob;
        ob.convertToWave(a);

        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";

        cout << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends