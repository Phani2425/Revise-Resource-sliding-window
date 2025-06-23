// User function Template for C++

class Solution {
    void checkSorrounding(int i, int j, vector<vector<int>> & hospital, vector<vector<int>> & adj){
        int col = hospital[0].size(); 
        int row = hospital.size();      
        int index = i * col + j;            // current node's linear index
    
        // Top
        if (i > 0 && hospital[i - 1][j] != 0) {
            adj[index].push_back((i - 1) * col + j);
        }
    
        // Bottom
        if (i + 1 < row && hospital[i + 1][j] != 0) {
            adj[index].push_back((i + 1) * col + j);
        }
    
        // Left
        if (j > 0 && hospital[i][j - 1] != 0) {
            adj[index].push_back(i * col + (j - 1));
        }
    
        // Right
        if (j + 1 < col && hospital[i][j + 1] != 0) {
            adj[index].push_back(i * col + (j + 1));
        }
    }
    
  public:
    int helpaterp(vector<vector<int>> hospital) {
        int row = hospital.size();
        int col = hospital[0].size();
        
       vector<vector<int>> adj(row*col);
       queue<int> recentlyInfected;
       vector<bool> infectedTracker(row*col,0);
       
       //building adjecency list
       for(int i = 0;i<row;i++){
           for(int j = 0;j<col;j++){
               if(hospital[i][j]){
                   checkSorrounding(i,j,hospital,adj);
               }else{
                   infectedTracker[i*col+j] = -1;
               }
               if(hospital[i][j] == 2){
                   recentlyInfected.push(i*col+j);
               }
           }
       }
       
       int unitsOfTime = 0;
       
       while(!recentlyInfected.empty()){
           int size = recentlyInfected.size();
           while(size--){
               int room = recentlyInfected.front();
               if(!infectedTracker[room]){
                   infectedTracker[room] = 1;
                   
                   for(int v : adj[room]){
                       if(!infectedTracker[v]){
                           recentlyInfected.push(v);
                       }
                   }
                   
               }
               recentlyInfected.pop();
           }
           if(!recentlyInfected.empty()){
               unitsOfTime++;
           }
       }
       
       for(int room : infectedTracker){
           if(room == 0){
               return -1;
           }
       }
       
       return unitsOfTime;
       
    }
};
