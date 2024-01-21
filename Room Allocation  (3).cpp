#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 2e5;

int N;
int ans[MAX_N];
vector<pair<pair<int, int>, int>> v(MAX_N);

int main() {
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;  // Store the original index
    }
    sort(v.begin(), v.end());  // Sort by arrival date

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // Min heap for room availability
    int roomCount = 0;

    for (int i = 0; i < N; i++) {
        int arrival = v[i].first.first, departure = v[i].first.second;

        // Check if any room is available before the arrival of the current customer
        if (!pq.empty() && pq.top().first < arrival) {
            ans[v[i].second] = pq.top().second; // Assign an available room
            pq.pop();
        } else {
            ans[v[i].second] = ++roomCount; // Assign a new room
        }

        // Push the departure time of the current customer along with the assigned room number
        pq.push({departure, ans[v[i].second]});
    }

    cout << roomCount << "\n";
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
