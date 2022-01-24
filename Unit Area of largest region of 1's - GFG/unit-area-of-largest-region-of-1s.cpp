// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int func(vector<vector<int>>& g,int i,int j)
    {
        if(i<0 || j<0 || j>=g[0].size() || i>=g.size() || g[i][j]==0)
            return 0;
       
        g[i][j]=0;
        return 1+ func(g,i+1,j)
                + func(g,i,j+1)
                + func(g,i-1,j)
                + func(g,i,j-1)
                + func(g,i-1,j-1)
                + func(g,i+1,j+1)
                + func(g,i-1,j+1)
                + func(g,i+1,j-1);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j])
                {
                    ans=max(ans,func(grid,i,j));
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends