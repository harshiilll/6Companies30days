// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
   vector<string>ans;
    void combinations(int a[],map<int,string>m,int ind,string s,int n)
    {
        if(ind==n)
        {
            ans.push_back(s);
            return;
        }
        string val=m[a[ind]];
        for(int j=0;j<val.length();j++)
        {
            combinations(a,m,ind+1,s+val[j],n);
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        if(N==0)
            return ans;
            
        map<int,string>m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        
        combinations(a,m,0,"",N);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends