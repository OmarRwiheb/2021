/* job sequence with deadlines problem:
 * you are given a set of jobs, each job has defined and some profit associated with
 * its deadline.
 * only one person available to process al the jobs and this person take one unit of
 * time to complete a job.
 *
 * solution:
 * we will use greedy algorithm to solve this problem.
 * a feasible solution would be a subset of jobs where each job of the
 * subset gets completed within its deadline.
 * value of feasible solution would be the sum of profit of all the jobs contained
 * in the subset, and the optimal solution of the problem would be a feasible solution
 * which gives the maximum profit.
 *
 * step 1:
 * sort all the given jobs in decreasing order according to the profit
 *
 * step 2:
 * pick the jobs one by one and check if there is a free time to do
 * this job before its deadline if so then we put do this job as near as
 * its deadline.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// a struct to represent each job
struct JOB{
    char id;
    int profit;
    int deadline;
};

// this function is used for sorting the jobs by the profit
bool compare(JOB a, JOB b){
    return (a.profit > b.profit);
}

int main() {

    // creat an array of JOB to store the information of each job
    JOB arr[] = {{'a', 10,1}, {'b',1,3}, {'b',20,2},
            {'c',15,2}, {'d',5,3}};

    // get the number of element in the array be divide
    // the size of the whole array by the size of one of its element
    int n = sizeof(arr) / sizeof(arr[0]);

    // sort the array by the profit of each job
    sort(arr, arr + n, compare);

    // we creat two vector first one to store the result
    // and the second to keep trach of free time
    vector<int> result(n);
    vector<bool> slot(n, false);

    // we will use the greedy approch to select to jobs that
    // gives us the maximum profit
    for(int i = 0; i < n; i++){
        // this loop is used to find free slot
        // that available before the deadline of the current job
        for(int j = arr[i].deadline - 1; j >= 0; j--){
            if(!slot[j]){
                // if we find a free slot we add this job to result
                // and give the slot true value to indicate that this slot not empty
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    // we print the result
    for(int i = 0; i < n; i++){
        if(slot[i])
            cout << arr[result[i]].id << " ";
    }

    return 0;
}
