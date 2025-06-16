class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> visited(adj.size(),0);
        queue<int> q;
        vector<int> ans;
        
        q.push(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //i had forgot to add this...think why am i adding this??? if i am onlly pushing nodes whch are not visited in the queue then why to check again??
            if(visited[node]){
                continue;
            }
            ans.push_back(node);
            visited[node] = 1;
            
            for(int i=0 ;i<adj[node].size();i++){
                if(visited[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
        
        return ans;
    }
};