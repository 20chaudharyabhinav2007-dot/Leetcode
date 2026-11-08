class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> visited(n, 0);
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        int count = 1;

        while(!q.empty()) {
            int room = q.front();
            q.pop();

            for(int key : rooms[room]) {
                if(visited[key] == 0) {
                    visited[key] = 1;
                    count++;
                    q.push(key);
                }
            }
        }

        return count == n;
    }
};