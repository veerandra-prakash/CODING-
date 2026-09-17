547. Number of Provinces


There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 
Link :https://leetcode.com/problems/number-of-provinces/description/

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output:3


CODE:


class Solution {
public:

    void bfs(int start, vector<vector<int>>&adj , vector<int>&visited){
        visited[start]=1;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(visited[it]==-1){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int>visited(V+1,-1);
        vector<vector<int>>adj(V+1);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count=0;
        for(int i=1;i<=V;i++){
            if(visited[i]==-1){
                bfs(i,adj,visited);
                count++;
            }
        }
      return count;
    }
};
