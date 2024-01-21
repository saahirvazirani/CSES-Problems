#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    vector<int> traffic_lights(n);
    for (int i = 0; i < n; i++) {
        cin >> traffic_lights[i];
    }

    // Initialize sets
    set<int> lights{0, x}; // Include start and end of the road
    multiset<int> sections{x}; // Initially, the whole road is one section

    for (int i = 0; i < n; i++) {
        int light = traffic_lights[i];
        // Find the section in which this light is placed
        auto it = lights.upper_bound(light);
        int right = *it;
        int left = *prev(it);

        // Remove the old section length and add new section lengths
        sections.erase(sections.find(right - left));
        sections.insert(light - left);
        sections.insert(right - light);

        // Add the new light
        lights.insert(light);

        // The largest section is the last element in the multiset
        cout << *sections.rbegin() << "\n";
    }

    return 0;
}
