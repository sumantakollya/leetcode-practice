//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    static bool comp(pair<int,int> A,pair<int,int> B) {
        if (A.second > B.second)
            return true;
        else if (A.second < B.second)
            return false;
        else
        {
            if (A.first > B.first)
                return true;
            else
                return false;
        }
    }
    vector<int> topKFrequent(vector<int>& arr, int k) {
        // Code here
        
        unordered_map<int,int> hmap;
        vector<int> result(k);

        for (int i=0; i< arr.size(); i++)
        {
            hmap[arr[i]]++;
        }
        
        vector<pair<int,int>> temp(hmap.size());
        int t=0;
        for(auto it=hmap.begin();it!=hmap.end();it++)
        {
            temp[t].first = it->first;
            temp[t].second = it->second;
            t++;
        }
        
        sort(temp.begin(),temp.end(),comp);
        
        for (int i=0;i<k;i++)
            result[i]=temp[i].first;
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.topKFrequent(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends