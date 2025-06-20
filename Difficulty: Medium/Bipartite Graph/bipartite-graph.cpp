
// USING BFS

class Solution {
    
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
      vector<int> adj[V];
      vector<int> color(V,-1);
      queue<int> q;
      
      //creating adjecency list
      for(vector<int> edge :  edges){
          adj[edge[0]].push_back(edge[1]);
          adj[edge[1]].push_back(edge[0]);
      }
      
      q.push(0);
      color[0] = 0;
      
      while(!q.empty()){
          int node = q.front();
          q.pop();
          
          for(int v : adj[node]){
              //if neighbour is not yet colored
              if(color[v] == -1){
                  color[v] = (color[node]+1)%2;
                  q.push(v);
              }
              //if neighbour is already colored
              else{
                  if(color[v] == color[node]){
                      return false;
                  }
              }
          }
      }
      
      return true;
       
    }
};



// THIS BELOW SOLUTION IS CORRECT BUT TAKES LITTLE MORE TIME AND FAILS IN 1111TH TEST CASE

// class Solution {
    
//     bool bfs(int vertex, vector<int> adj[],vector<bool>& visited, queue<int>& q, vector<bool>& window){
//         q.push(vertex);
        
//         while(!q.empty()){
//             int windowSize = q.size();
//             //here we are just storing info about all the elements currently present in the queue so that later we can check that if there is any edge bw these currently present vertices
//             //if we found any edge bw currently present element in window then that graph can not be separated into two sets
//             for(int i=windowSize;i>0;i--){
//                 window[q.front()] = 1;
//                 q.push(q.front());
//                 q.pop();
//             }
            
//             for(int i=windowSize;i>0;i--){
//                 int node = q.front();
//                 q.pop();
//                 if(visited[node]) continue;
                
//                 visited[node] = 1;
                
//                 for(int v : adj[node]){
//                     if(window[v]){
//                         return false;
//                     }
//                     if(!visited[v]){
//                         q.push(v);
//                     }
//                 }
//             }
            
//             //emptying the window for new elements in queue
//             fill(window.begin(), window.end(),0);
//         }
        
//         return true;
//     }
    
//   public:
//     bool isBipartite(int V, vector<vector<int>> &edges) {
//       vector<int> adj[V];
//       vector<bool> visited(V,0);
//       queue<int> q;
//       //vector for tracking the vertices currently present in our window in queue
//       vector<bool> window(V,0);
      
//       //creating adjecency list
//       for(vector<int> edge :  edges){
//           adj[edge[0]].push_back(edge[1]);
//           adj[edge[1]].push_back(edge[0]);
//       }
      
//       for(int i = 0; i< visited.size(); i++){
//           if(!visited[i] && !bfs(i,adj,visited,q,window)){
//              return false;
//           }
//       }
      
//       return true;
//     }
// };

