#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    string at[] = {"09:00", "09:10", "09:20", "11:00", "11:20"};
    string dt[] = {"09:40", "12:00", "09:50", "11:30", "11:40"};
    int n = 5;

    vector<int> arr(n), dep(n);

    for (int i = 0; i < n; i++) {
        arr[i] = stoi(at[i].substr(0, 2)) * 60 + stoi(at[i].substr(3, 2));
        dep[i] = stoi(dt[i].substr(0, 2)) * 60 + stoi(dt[i].substr(3, 2));
    }

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int plat = 1, res = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat++;
            i++;
        } else {
            plat--;
            j++;
        }
        res = max(res, plat);
    }

    cout << "Minimum number of platforms required = " << res << endl;

    return 0;
}