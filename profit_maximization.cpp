// Profit Maximisation


//  Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.
// Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.




int Solution::solve(vector<int> &A, int B) {
    
    priority_queue<int>pq; //max heap
    
    int sum=0;
    
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    
    while(B && !pq.empty()){
        int top=pq.top();
        
        sum+=top;
        
        
        if(pq.top()-1){
            pq.push(pq.top()-1);
        }
        
        pq.pop();
        
        B--;
    }
    
    return sum;
}
