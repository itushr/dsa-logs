class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        vector<int> ans;

        for(auto pre: prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int course = q.front();
            q.pop();

            ans.push_back(course);

            for(int x: adj[course]) {
                indegree[x]--;
                if(indegree[x] <= 0) {
                    q.push(x);
                } 
            }
        }

        if(ans.size() < numCourses) return {};
        else return ans;   
    }
};