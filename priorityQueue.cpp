#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){ 
    // priority_queue<int>pq; //max heap

    // pq.push(10);
    // pq.push(20);
    // pq.push(30);
    // pq.push(40);
    // pq.push(50);

    // cout<<pq.top()<<endl;

    // pq.pop();
    // cout<<pq.top()<<endl;
    
    // //size
    // cout<<pq.size()<<endl;


    // while(!pq.empty()){
    //    cout<<pq.top()<<" ";
    //    pq.pop();

    // }



    //priority queue --->>> MIN HEAP

    priority_queue<int,vector<int>,greater<int>>pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout<<pq.top()<<endl;

    pq.pop();
    cout<<pq.top()<<endl;
    
    //size
    cout<<pq.size()<<endl;

}
