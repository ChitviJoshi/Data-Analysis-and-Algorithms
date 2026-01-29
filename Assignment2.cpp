//Q1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct act {
    int s, f, id;
};

bool compare(act a, act b) {
    return a.f < b.f;
}

int main() {
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    vector<act> v(n);
    for (int i = 0; i < n; i++) {
        v[i].s = start[i];
        v[i].f = finish[i];
        v[i].id = i;
    }

    sort(v.begin(), v.end(), compare);

    int count = 1;
    int last_f = v[0].f;
    
    cout << "Selected Activity Indices: " << v[0].id;

    for (int i = 1; i < n; i++) {
        if (v[i].s >= last_f) {
            cout << ", " << v[i].id;
            last_f = v[i].f;
            count++;
        }
    }

    cout << "\nTotal activities: " << count << endl;

    return 0;
}