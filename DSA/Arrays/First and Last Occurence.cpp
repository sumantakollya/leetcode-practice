//https://www.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x0849/1?page=1&category=Arrays&company=Microsoft&sortBy=difficulty
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        pair<long,long> index(-1,-1);
        bool flag=true;
        
        for (int it=0; it<v.size(); it++)
        {
            if (v[it] == x)
            {
                if (flag)
                {
                    index.first = it;
                    flag = false;
                }
                index.second = it;
            }
        }
        
        return index;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends