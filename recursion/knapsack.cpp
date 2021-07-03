#include<bits/stdc++.h>

using namespace std;


vector<pair<int, int>> items;

int knapsack(int idx, int curCap){
    // base case
    if(idx == items.size()){
        return 0;
    }

    // transition
    int leave = knapsack(idx + 1, curCap);
    if(curCap >= items[idx].second)
        return max (
            items[idx].first + knapsack(idx + 1, curCap - items[idx].second),
            leave
        );
    else return leave;

}

int main() {
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    for(int i = 0; i < n; i++){
        items.push_back(make_pair(val[i], wt[i]));
    }
    printf("%d", knapsack(0, W));


    return 0;
}
