class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq; //max heap

        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }

        
        
        while(k!=0){
            int max=pq.top();
            pq.pop();

            if(sqrt(max)){
                pq.push(floor(sqrt(max)));
            }

            k--;
        }

       long long sum=0;
        while(!pq.empty()){
            long long top= pq.top();
            sum+=top;
            pq.pop();
        }

        return sum;
    }
};