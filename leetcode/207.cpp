class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        for(auto pre: prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int finished = 0;

        while(!q.empty()) {
            int course = q.front();
            q.pop();

            finished++;

            for(int x: adj[course]) {
                indegree[x]--;
                if(indegree[x] <= 0) {
                    q.push(x);
                } 
            }
        }

        if(finished == numCourses) return true;
        else return false;
    }
};