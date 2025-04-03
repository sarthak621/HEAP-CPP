//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int frogJumpSolve(vector<int>& height,vector<int>&dp,int index ){
        if(index==0) return 0;
        if(dp[index]!=-1) return dp[index];
        int left;
        int right=INT_MAX;
        
        left=frogJumpSolve(height,dp,index-1)+abs(height[index]-height[index-1]);
        if(index>1){
            right=frogJumpSolve(height,dp,index-2)+abs(height[index]-height[index-2]);
        }
        return dp[index]=min(left,right);
        
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n+1,-1);
        return frogJumpSolve(height,dp,n-1);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends