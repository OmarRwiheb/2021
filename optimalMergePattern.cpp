/* optimal merge pattern:
 * this technique is used when we want to merge more that two arrays with minimum steps required.
 * we make a min heap and push to it our arrays sizes and begin to merge
 * the smallest two elements in the heap so the total steps reqired to merge
 * is small as possiple.
*/
#include <bits/stdc++.h>

using namespace std;


int main() {

    // creat the min heap
    priority_queue<int, vector<int>, greater<int>> p;

    //creat an array and store the our arrays sizes
    int arrays[] = {6, 5, 2, 3};

    // calculate the size of the array
    int n = sizeof(arrays)/sizeof(arrays[0]);

    // push our elements into the heap
    for(int i = 0; i < n; i++)
        p.push(arrays[i]);

    // creat steps variable to count the number of comparisons we made through the merge process
    int steps = 0;

    while(p.size() > 1){
        // take the smallest two elements from the heap
        int small1 = p.top();
        p.pop();
        int small2 = p.top();
        p.pop();

        // calculate the number of steps required to merge this two arrays
        int temp = small1 + small2;

        steps += temp;

        // put the result of this process to the heap
        p.push(temp);
    }

    cout << "the number of comparisons = " <<steps << endl;

    return 0;
}
