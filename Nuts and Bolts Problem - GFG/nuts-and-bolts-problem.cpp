// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    map<char,int>m;
	    m['!']=0;
	    m['#']=0;
	    m['$']=0;
	    m['%']=0;
	    m['&']=0;
	    m['*']=0;
	    m['@']=0;
	    m['^']=0;
	    m['~']=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        m[nuts[i]]++;
	        m[bolts[i]]++;
	    }
	    
	    int i=0;
	    for(auto x:m)
	    {
	        if(x.second>1)
	        {
	            nuts[i]=x.first;
	            bolts[i]=x.first;
	            i++;
	        }
	    }
	    
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends