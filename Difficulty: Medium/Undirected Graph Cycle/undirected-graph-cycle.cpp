class Solution {
  public:
  
    bool dfsUsingRecursion(int vertex, int parent, vector<vector<int>> & adj, vector<bool> & visited){
        
            visited[vertex] = 1;
        
        for(int v : adj[vertex]){
          if(v != parent && visited[v]){
              return true;
          }
          if(!visited[v]){
              if(dfsUsingRecursion(v,vertex,adj,visited)){
                  return true;
              };
          }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<bool> visited(V,0);
        
        //creating adjecency list
        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        // return dfsUsingRecursion(0,-1,adj,visited); [this can work only of graph is connected and for disconnected graph it will not work...so to make it work we need to check if all the vertices are visited or not before returning the answer...if not then try to visit all first then return ans]
        
        for(int i = 0; i< visited.size(); i++){
            if(!visited[i] && dfsUsingRecursion(i,-1,adj,visited) ){
                return true ;
            }
        }
        
        return false;
    }
};

//int arr[5] = {0}; // Creates an array of 5 integers, all initialized to 0