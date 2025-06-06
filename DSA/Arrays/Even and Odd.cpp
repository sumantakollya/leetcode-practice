//https://www.geeksforgeeks.org/problems/even-and-odd/1?page=1&category=Arrays&company=Microsoft&sortBy=difficulty
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void reArrange(int arr[], int N) {
        // code here
        int *res;
        int evenidx=0;
        int oddidx=1;
        res = new int[N];
        
        
        for (int i=0;i<N;i++)
        {
            if(arr[i]%2==0)
            {
                res[evenidx]=arr[i];
                evenidx+=2;
            }
            else
            {
                res[oddidx]=arr[i];
                oddidx+=2;
            }
        }
        
        //copy back
        for(int i=0;i<N;i++)
        {
            arr[i]=res[i];
        }
            
    }
};

//{ Driver Code Starts.

int check(int arr[], int n)
{
    int flag = 1;
    int c=0, d=0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            if(arr[i]%2)
            {
                flag = 0;
                break;
            }
            else
                c++;
        }
        else
        {
            if(arr[i]%2==0)
            {
                flag = 0;
                break;
            }
            else
                d++;
        }
    }
    if(c!=d)
        flag = 0;
        
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        ob.reArrange(arr,N);
        
        cout<<check(arr,N)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends