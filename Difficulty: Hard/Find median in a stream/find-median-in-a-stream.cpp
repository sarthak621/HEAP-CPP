//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
          //left max heap
        priority_queue<int>LeftSideHeap;
        
        //right min heap
        priority_queue<int,vector<int>,greater<int>>RightSideHeap;
  
    void insertHeap(int &num ){

        
            if(LeftSideHeap.empty()){
                LeftSideHeap.push(num);
                return;
            }
            
            if(num>LeftSideHeap.top()){
                RightSideHeap.push(num);
            }
            
            else{
                LeftSideHeap.push(num);
            }
            
            
        balanceHeap();
    }
    
    void balanceHeap(){
        
        if(RightSideHeap.size()>LeftSideHeap.size()){
            LeftSideHeap.push(RightSideHeap.top());
            RightSideHeap.pop();
        }
        
        else if(LeftSideHeap.size()-1>RightSideHeap.size()){
            RightSideHeap.push(LeftSideHeap.top());
            LeftSideHeap.pop();
        }
        
    }
  
    vector<double> getMedian(vector<int> &arr) {
        // code here
        
        //inserting the elements in the heap
        vector<double>medians;
        
        for(int i=0;i<arr.size();i++){
            insertHeap(arr[i]);  
            
            //finding median 
            if(LeftSideHeap.size()>RightSideHeap.size()){
                medians.push_back((double)LeftSideHeap.top());
            }
        
            else if(LeftSideHeap.size()==RightSideHeap.size()){
            double ans= (LeftSideHeap.top()+RightSideHeap.top())/2.0;
             medians.push_back(ans);
            }
        }
        
        return medians;
        
        
        
        
        
        
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends