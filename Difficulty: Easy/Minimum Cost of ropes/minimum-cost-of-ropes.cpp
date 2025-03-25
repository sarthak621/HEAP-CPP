//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        
        //build mean heap
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        
        //now we have to select two smallest element until our size is grater than 1
        
        long long cost=0;
        
        while(pq.size()>1){
            long long rope1=pq.top();
            pq.pop();
            
            long long rope2=pq.top();
            pq.pop();
            
            long long sum=rope1+rope2;
            
            cost+=sum;
            
        
            pq.push(sum);
        }
        
        return cost;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends