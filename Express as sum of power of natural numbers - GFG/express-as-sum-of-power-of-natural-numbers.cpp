// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int t[1001][1001];
   long long int mod=1e9+7;
   long long int solve(int n,int x,int i){
       if(n==0){
           return 1;
       }
       if(i>n){
           return 0;
       }
       if(t[n][i]!=-1){
           return t[n][i];
       }
       int pa=pow(i,x);
       if(pa<=n){
           return t[n][i]=(solve(n-pa,x,i+1)+solve(n,x,i+1))%mod;
           
       }
       else{
           return t[n][i]=0;
           
       }
   }
   int numOfWays(int n, int x)
   {
       memset(t,-1,sizeof(t));
       return solve(n,x,1);
       
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends