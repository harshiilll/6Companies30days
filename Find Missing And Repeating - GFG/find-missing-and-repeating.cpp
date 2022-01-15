// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        
        
        sort(arr,arr+n);
        int *a= new int[2];
        
        int arr_sum=0,original_sum=0;
       
        
        for(int i=0;i<n;i++)
        {
            int original_element=abs(arr[i]);
            int index=original_element-1;
            
            if(arr[index]<0)
            {
                a[0]=original_element;
            }
            arr[index]=-arr[index];
            original_sum+=i+1;
            arr_sum+=original_element;
        }
        
        
        a[1]=original_sum-(arr_sum-a[0]);
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends