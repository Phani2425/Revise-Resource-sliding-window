class Solution {
    
    bool dfs(int vertex, vector<int> adj[],vector<bool>& visited,vector<bool>& currentPath){
        visited[vertex] = 1;
        currentPath[vertex] = 1;
        
        for(int v : adj[vertex]){
            if(visited[v] && currentPath[v]){
                return true;
            }
            if(!visited[v]){
                if(dfs(v,adj,visited,currentPath)){
                    return true;
                }
            }
        }
        currentPath[vertex] = 0;
        
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool> visited(V,0);
        vector<bool> currentPath(V,0);
        vector<int> adj[V];
        
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        //as graph can be discooncted graph
        for(int i = 0; i< visited.size();i++){
            if(!visited[i] && dfs(i,adj,visited,currentPath)){
                return true;
            }
        }
        
        return false;
    }
};