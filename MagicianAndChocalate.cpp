//interview bit
//Magician and Chocalates
// Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.

// Find the maximum number of chocolates that kid can eat in A units of time.

// NOTE: 

// floor() function returns the largest integer less than or equal to a given number.
// Return your answer modulo 109+7



int Solution::nchoc(int A, vector<int> &B) {
    
    //build max heap
    priority_queue<int>pq;
    
    for(int i=0;i<B.size();i++){
        pq.push(B[i]);
    }
    
    long long max=0;
    while(A&&(!pq.empty())){
        int topEl=pq.top();
        pq.pop();
        
        max+=topEl;
        
        if(topEl/2){
            pq.push(topEl/2);
        }
        
        A--;
    }
    
    return max%1000000007;
}
