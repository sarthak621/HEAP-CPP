class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //given the 2D array of the nums 

        
        //creating the min heap
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        int minimum;
        int maximum=INT_MIN;

        //priority queue me sabhi list ke first element ko dal do
        for(int i=0;i<nums.size();i++){
            pq.push(make_pair(nums[i][0],make_pair(i,0)));
            maximum=max(maximum,nums[i][0]);
        }

        minimum=pq.top().first;

        //we have got the min and max between all the first element of all lists

        vector<int>ans(2); //creating the ans of size 2 

        ans[0]=minimum;
        ans[1]=maximum;


        pair<int,pair<int,int>>temp;
        int row, col,elem;
       
        while(pq.size()==nums.size()){  //jab tak pq ki size or nums ki size barabar ho tab tak

        temp=pq.top();
        pq.pop();
        elem=temp.first;
        row=temp.second.first;
        col=temp.second.second;

        if(col+1<nums[row].size()){
              col++;
              pq.push(make_pair(nums[row][col],make_pair(row,col)));
              maximum=max(maximum,nums[row][col]);
              minimum=pq.top().first;

              if(maximum-minimum<ans[1]-ans[0]){
                ans[0]=minimum;
                ans[1]=maximum;
              }
        }

        }

        return ans;
    }
};