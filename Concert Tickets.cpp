#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    vector<int> customers(m);

    // Read ticket prices and insert them into the multiset
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        tickets.insert(price);
    }

    // Read customer's maximum prices
    for (int i = 0; i < m; i++) {
        cin >> customers[i];
    }

    // Process each customer
    for (int i = 0; i < m; i++) {
        // Find the ticket that is closest to the customer's max price
        auto it = tickets.upper_bound(customers[i]);
        if (it == tickets.begin()) {
            cout << "-1\n";
        } else {
            // Previous element is the largest element <= customer's max price
            it--;
            cout << *it << "\n";
            tickets.erase(it); // Remove the used ticket
        }
    }

    return 0;
}
