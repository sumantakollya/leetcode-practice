#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin>>T;
    for (int t=0;t<T;t++)
    {
        int N;
        cin>>N;
        
        int *arr = new int[N];
        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        
        int maxsum = arr[0];
        int maxres = maxsum;
        for(int i=1;i<N;i++)
        {
            maxsum += arr[i];
            
            if (maxsum >= 0)
            {
                if (maxsum > maxres)
                    maxres = maxsum;
            }
            else
            {
                maxsum = 0;
            }
        }
        
        cout<<maxres<<endl;
    }
}