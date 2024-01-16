#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> applicant_sizes(n);
    vector<int> apartment_sizes(m);
    
    for (int i = 0; i < n; i++) {
        cin >> applicant_sizes[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> apartment_sizes[i];
    }
    
    sort(applicant_sizes.begin(), applicant_sizes.end());
    sort(apartment_sizes.begin(), apartment_sizes.end());
    
    int i = 0, j = 0, count = 0;
    
    while (i < n && j < m) {
        if (abs(applicant_sizes[i] - apartment_sizes[j]) <= k) {
            count++;
            i++;
            j++;
        } else if (applicant_sizes[i] < apartment_sizes[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
