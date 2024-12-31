//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int inver;
    void merge(vector<int> &arr, int left, int mid, int right) {
        
        cout<<"left "<<left<<" mid "<<mid<<" right "<<right<<endl;
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        //create temp arrays
        vector<int> L(n1);
        vector<int> R(n2);
        
        //store into L and R
        for (int i=0;i<n1;i++)
            L[i] = arr[left+i];
            
        for (int i=0;i<n2;i++)
            R[i] = arr[mid+i+1];
        
        //merge and enter
        int li = 0,ri = 0,ii = left;
        while (li < n1 && ri < n2) {
            if (L[li] <= R[ri])
                arr[ii++] = L[li++];
            else {
                inver += n1-li;
                arr[ii++] = R[ri++];   
            }
        }
        
        //insert remaining
        while (li < n1)
            arr[ii++] = L[li++];

        while (ri < n2)
            arr[ii++] = R[ri++];
        cout<<"merging"<<endl;
        
        for (int i=0;i<n1;i++)
            cout<<L[i]<<" ";
        cout<<endl;
        for (int i=0;i<n2;i++)
            cout<<R[i]<<" ";
        cout<<endl;
        cout<<"after merge"<<endl;
        for (int i=left;i<=right;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        
    }
    void mergesort(vector<int> &arr,int left,int right) {
        
        if (left >= right)
            return;
        
        int mid = (right+left)/2;
        
        //divide
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        
        //merge
        merge(arr, left, mid, right);
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int count=0;
        inver = 0;
        
        mergesort(arr,0,arr.size()-1);
        count = inver;
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends