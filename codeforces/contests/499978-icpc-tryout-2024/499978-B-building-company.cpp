#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

// typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int G;
    cin >> G;

    int t, u;
    unordered_map<int, long long int> employees;

    for (int g = 0; g < G; ++g) {
        cin >> t >> u;
        employees[t] = u;
    }

    // for (auto &[occupation, occupation_count] : employees) {
    //     cout << occupation << ' ' << occupation_count << " : ";
    // } cout << '\n';

    int N, M, K, a, b, c, d;
    cin >> N;
    unordered_map<int, long long int> jobs[N];
    unordered_map<int, long long int> adds[N];
    set<int> completed_jobs;

    int completed_job_count = 0;

    for (int n = 0; n < N; ++n) {
        cin >> M;
        bool complete = true;
        for (int m = 0; m < M; ++m) {
            cin >> a >> b;
            jobs[n][a] = b;
            if (employees[b] < jobs[n][a]) complete = false;
        }

        cin >> K;
        for (int k = 0; k < K; ++k) {
            cin >> c >> d;
            adds[n][c] = d;
            if (complete) employees[c] += adds[n][c];
        }
        if (complete) {
            // cout << n << '\n';
            ++completed_job_count;
            completed_jobs.insert(n);
        }
    }

    // for (auto &[occupation, occupation_count] : employees) {
    //     cout << occupation << ' ' << occupation_count << " : ";
    // } cout << '\n';

    bool done = false;
    while (!done) {
        done = true;
        for (int n = 0; n < N; ++n) {
            if (completed_jobs.find(n) != completed_jobs.end()) continue;
            bool complete = true;

            for (auto &[occupation, occupation_count] : jobs[n]) {
                // cout << occupation << ' ' << occupation_count << '\n';
                // cout << employees[occupation] << '\n';
                if (employees.find(occupation) == employees.end()) employees[occupation] = 0;
                if (employees[occupation] < occupation_count) {
                    complete = false;
                    break;
                }
            }

            if (complete) {
                // cout << "B\n";
                done = false;
                for (auto &[occupation, occupation_count] : adds[n]) {
                    if (employees.find(occupation) == employees.end()) employees[occupation] = occupation_count;
                    else employees[occupation] += occupation_count;
                }
                ++completed_job_count;
                completed_jobs.insert(n);
            }
        }
        if (done) break;
        done = true;
        for (int n = N - 1; n >= 0; --n) {
            if (completed_jobs.find(n) != completed_jobs.end()) continue;
            bool complete = true;

            for (auto &[occupation, occupation_count] : jobs[n]) {
                // cout << occupation << ' ' << occupation_count << '\n';
                // cout << employees[occupation] << '\n';
                if (employees.find(occupation) == employees.end()) employees[occupation] = 0;
                if (employees[occupation] < occupation_count) {
                    complete = false;
                    break;
                }
            }

            if (complete) {
                // cout << "B\n";
                done = false;
                for (auto &[occupation, occupation_count] : adds[n]) {
                    if (employees.find(occupation) == employees.end()) employees[occupation] = occupation_count;
                    else employees[occupation] += occupation_count;
                }
                ++completed_job_count;
                completed_jobs.insert(n);
            }
        }
    }

    cout << completed_job_count << '\n';
}

/*
2 2 1 1 2
5
1 3 1
0

2 1 1 2 1
2 3 2 2 1

3 1 5 2 3 3 4
1 2 5

3 2 1 1 1 3 4
1 1 3

0
1 3 2

*/