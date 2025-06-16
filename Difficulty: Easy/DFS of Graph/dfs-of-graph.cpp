class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool> visited(adj.size(),0);
        stack<int>st;
        vector<int> ans;
        
        st.push(0);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            //i had forgot to add this...think why am i adding this??? if i am onlly pushing nodes whch are not visited in the stack then why to check again??
            if(visited[node]){
                continue;
            }
            
            visited[node] = 1;
            ans.push_back(node);
            
            for(int i = adj[node].size()-1; i>=0 ;i--){
                int v = adj[node][i];
                if(!visited[v]){
                    st.push(v);
                    }
            }
        }
        
        return ans;
    }
};