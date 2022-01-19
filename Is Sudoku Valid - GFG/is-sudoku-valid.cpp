// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        
        unordered_map<int,unordered_set<int>>row,col,grid;
        
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]!=0)
                {
                    int val=mat[i][j];
                
                    if(row[i].count(val))
                        return 0;
                        
                    if(col[j].count(val))
                        return 0;
                        
                    int box=((i/3)+(j/3)*3);
                    if(grid[box].count(val))
                        return 0;
                    
                    row[i].insert(val);
                    col[j].insert(val);
                    grid[box].insert(val);
                
                }
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends