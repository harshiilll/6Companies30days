// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull dp[n];
	    int p2=1;
	    int p3=1;
	    int p5=1;
	    dp[1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        ull f2=dp[p2]*2;
	        ull f3=dp[p3]*3;
	        ull f5=dp[p5]*5;
	        
	        ull mini=min(f2,min(f3,f5));
	        dp[i]=mini;
	        if(mini==f2)
	            p2++;
	            
	        if(mini==f3)
	            p3++;
	            
	        if(mini==f5)
	            p5++;
	    }
	    return dp[n];
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends