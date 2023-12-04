class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> keys;
        keys.push(0);
        vector<bool> visited(rooms.size());
        while(!keys.empty()){
            int room = keys.front();
            visited[room] = true;
            keys.pop();
            for(int i=0; i<rooms[room].size(); ++i){
                int newKey = rooms[room][i];
                if(!visited[newKey])    keys.push(newKey);
            }
        }
        for(bool b : visited){
            if(!b)  return false;
        }
        return true;
    }
};