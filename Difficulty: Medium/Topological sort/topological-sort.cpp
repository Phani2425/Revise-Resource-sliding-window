class Solution {
    void dfs(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st){
        visited[node] = 1;
        for(int v: adj[node]){
            if(!visited[v]){
                dfs(v,adj,visited,st);
            }
        }
        st.push(node);
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> ans;
        stack<int> st;
        vector<bool> visited(V,0);
        
        // creating adjecency list
        vector<int> adj[V];
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};