using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int numTasks = tasks.size();
        int numServers = servers.size();

        // for idleServers(not working servers) compare
        auto cmpServer = [](const vector<int>& server1, const vector<int>& server2) {
            if (server1[0] == server2[0]) {
                return server1[1] > server2[1];
            }
            return server1[0] > server2[0];
        };

        // for busyServers(working servers) compare
        auto cmpBusyServer = [](const vector<int>& server1, const vector<int>& server2) {
            if (server1[0] == server2[0]) {
                if (server1[1] == server2[1]) {
                    return server1[2] > server2[2];
                }
                return server1[1] > server2[1];
            }
            return server1[0] > server2[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmpServer)> idleServers(cmpServer);

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmpBusyServer)> busyServers(cmpBusyServer);

        for (int i=0;i<numServers;i++) {
            idleServers.push({servers[i], i});
        }

        vector<int> assignedServers(numTasks, 0);
        int assignedTasksCount = 0;

        for (int currentTime=0;currentTime<numTasks;currentTime++) {
            int taskDuration = tasks[currentTime];

            // if busyServer has over servers
            while (!busyServers.empty() && busyServers.top()[0] <= currentTime) {
                vector<int> server = busyServers.top();
                busyServers.pop();
                idleServers.push({server[1], server[2]});
            }
            // if there is idleServer
            if (!idleServers.empty()) {
                vector<int> server = idleServers.top();
                idleServers.pop();
                assignedServers[assignedTasksCount++] = server[1];
                busyServers.push({currentTime + taskDuration, server[0], server[1]});
            }
            //if there is no idleServer
            else {
                vector<int> server = busyServers.top();
                busyServers.pop();
                assignedServers[assignedTasksCount++] = server[2];
                busyServers.push({server[0] + taskDuration, server[1], server[2]});
            }
        }

        return assignedServers;
    }
};