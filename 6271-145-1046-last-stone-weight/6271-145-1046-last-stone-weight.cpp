class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int maxWt1= pq.top();
            pq.pop();

            int maxWt2=pq.top();
            pq.pop();

            int weight=maxWt1-maxWt2;
            if(weight){
                pq.push(weight);    
            }
            
        }

        return pq.empty()?0:pq.top();
    }
};