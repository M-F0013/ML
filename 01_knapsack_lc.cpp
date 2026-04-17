#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int level, profit, weight;
    float bound;

    bool operator<(const Node& other) const {
        return bound < other.bound;
    }
};

int n, W;
int wt[10], val[10];
float bound(Node u) {
    if (u.weight >= W) return 0;
    float profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while (j < n && totweight + wt[j] <= W) {
        totweight += wt[j];
        profit_bound += val[j];
        j++;
    }
    if (j < n)
        profit_bound += (W - totweight) * ((float)val[j] / wt[j]);
    return profit_bound;
}

// LC Branch and Bound
int knapsackLC() {
    priority_queue<pair<float, Node>> pq;
    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = bound(u);
    pq.push({u.bound, u});
    int maxProfit = 0;
    while (!pq.empty()) {
        u = pq.top().second;
        pq.pop();
        if (u.bound > maxProfit) {
            v.level = u.level + 1;
            // Include item
            v.weight = u.weight + wt[v.level];
            v.profit = u.profit + val[v.level];
            if (v.weight <= W && v.profit > maxProfit)
                maxProfit = v.profit;
            v.bound = bound(v);
            if (v.bound > maxProfit)
                pq.push({v.bound, v});
            // Exclude item
            v.weight = u.weight;
            v.profit = u.profit;
            v.bound = bound(v);
            if (v.bound > maxProfit)
                pq.push({v.bound, v});
        }
    }
    return maxProfit;
}

int main() {
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter weights and profits:\n";
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];
    cout << "Enter knapsack capacity: ";
    cin >> W;
    cout << "Maximum Profit (LC Branch & Bound): "
         << knapsackLC();
    return 0;
}
