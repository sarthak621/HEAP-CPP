//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        
        //max heap
        priority_queue<long long>pq1;
        priority_queue<long long>pq2;
        
        //for K1
        for(long long i=0;i<K1;i++){
            pq1.push(A[i]);
        }
        
        //for K2
        for(long long i=0;i<K2-1;i++){
            pq2.push(A[i]);
        }
        
        //now we have to compare the values in heap with further values in array
        
        //for K1
        for(int i=K1;i<N;i++){
            long long top=pq1.top();
            if(A[i]<top){
                pq1.pop();
                pq1.push(A[i]);
            }
        }
        
        //for K2
        for(int i=K2-1;i<N;i++){
            long long top=pq2.top();
            if(A[i]<top){
                pq2.pop();
                pq2.push(A[i]);
            }
        }
        
        //sum of the elements in K1 and K2
        long long sum1=0 , sum2=0;
        while(!pq1.empty()){
            long long top=pq1.top();
            pq1.pop();
            sum1+=top;
        }
        
        while(!pq2.empty()){
            long long top=pq2.top();
            pq2.pop();
            sum2+=top;
        }
        
        return sum2-sum1;
    }
};


//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends