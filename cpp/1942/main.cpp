#include <queue>
#include <tuple>
#include <vector>
#include <iomanip>
#include <iostream>

class Solution {
public:
    struct Event {
        int     time;
        int     friendID;
        bool    isArrival;
        bool operator<(const Event& other) const {
            if (time == other.time) {
                return isArrival > other.isArrival;
            }
            return time > other.time;
        }
    };

    int addFriend(std::vector<int>& chairs, const int friendID) {
        for (int i = 0; i < chairs.size(); i++) {
            if (chairs[i] == -1) {
                chairs[i] = friendID;
                return i;
            }
        }
        return -1;
    }

    void removeFriend(std::vector<int>& chairs, const int friendID) {
        for (int i = 0; i < chairs.size(); i++) {
            if (chairs[i] == friendID) {
                chairs[i] = -1;
                return;
            }
        }
    }

    int smallestChair(std::vector<std::vector<int>>& times, const int targetFriend) {
        std::priority_queue<Event> events;
        for (int i = 0; i < times.size(); i++) {
            events.push({times[i][0], i, true});
            events.push({times[i][1], i, false});
        }

        std::vector<int> chairs(times.size(), -1);

        while (!events.empty()) {

            Event current = events.top();
            events.pop();
            
            if (current.isArrival) {
                int chair = addFriend(chairs, current.friendID);
                if (current.friendID == targetFriend) {
                    return chair;
                }
            }
            else {
                removeFriend(chairs, current.friendID);
            }
        }

        return -1;
    }
};


// Testing
int main() {
    Solution solution;

    std::vector<std::pair<std::vector<std::vector<int>>, int>> testCases = {
        {{{1, 4}, {2, 3}, {4, 6}}, 1},
        {{{1, 2}, {2, 3}, {3, 4}}, 0},

    };
    std::vector<int> expectedResults = {
        1,
        0
    };

    for (size_t i = 0; i < testCases.size(); i++) {
        auto& testCase = testCases[i];
        int result = solution.smallestChair(testCase.first, testCase.second);
        int expected = expectedResults[i];

        std::cout << "Test case " << i + 1 << ": ";
        std::cout << "Expected chair = " << expected << ", Got = " << result;
        std::cout << (result == expected ? " --> Passed" : " --> Failed") << std::endl;
    }

    return 0;
}