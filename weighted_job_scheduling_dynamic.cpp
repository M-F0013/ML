#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int start, finish, profit;
};

bool compare(Job a, Job b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];  
    for(int i = 0; i < n; i++) {
        cout << "Enter start, finish and profit: ";
        cin >> jobs[i].start >> jobs[i].finish >> jobs[i].profit;
    }

    sort(jobs, jobs + n, compare);

    int dp[n];
    dp[0] = jobs[0].profit;

    for(int i = 1; i < n; i++) {
        int incl = jobs[i].profit;

        for(int j = i - 1; j >= 0; j--) {
            if(jobs[j].finish <= jobs[i].start) {
                incl += dp[j];
                break;
            }
        }

        dp[i] = max(incl, dp[i - 1]);
    }

    cout << "Maximum profit: " << dp[n - 1];   
    return 0;
}