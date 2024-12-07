#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Record {
    string location;
    string time;
};

bool compareByTime(const Record& a, const Record& b) {
    return a.time < b.time;
}

bool compareByLocation(const Record& a, const Record& b) {
    return a.location < b.location;
}

int main() {
    vector<Record> records = {
        {"Chicago", "09:00:00"}, {"Phoenix", "09:00:03"}, {"Houston", "09:00:13"},
        {"Houston", "09:01:10"}, {"Chicago", "09:00:59"}, {"Seattle", "09:03:13"},
        {"Seattle", "09:10:25"}, {"Phoenix", "09:14:25"}, {"Chicago", "09:19:32"},
        {"Chicago", "09:19:46"}, {"Seattle", "09:22:54"}, {"Chicago", "09:21:05"},
        {"Chicago", "09:25:52"}, {"Seattle", "09:36:14"}, {"Phoenix", "09:37:44"}
    };

    // Sort by time first
    stable_sort(records.begin(), records.end(), compareByTime);

    // Sort by location while maintaining the order of time
    stable_sort(records.begin(), records.end(), compareByLocation);

    // Print the result
    for (const auto& record : records) {
        cout << record.location << " " << record.time << endl;
    }

    return 0;
}