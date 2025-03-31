class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long>pq;

        long long sum=0;

        for(int i=0;i<target.size();i++){
            pq.push(target[i]);
            sum+=target[i];
        }

        long long maxElement , remainingSum , element;

        while(pq.top()!=1){
            maxElement=pq.top();
            pq.pop();
            remainingSum=sum-maxElement;

            //maxElement=element+remainingSum

            if(remainingSum<=0 || remainingSum>=maxElement){
                return 0;
            }

            //update the values of the sum and all the stuffs
            
            // element=maxElement-remainingSum;
            element=maxElement%remainingSum;
            if(element==0){
                if(remainingSum==1) return 1;
                else return 0;
            }

            pq.push(element);
            sum=remainingSum+element;


        }

        return 1;

    }
};