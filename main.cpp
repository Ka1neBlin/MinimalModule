#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int minAbs(const vector<int> &A, const vector<int> &B){
    int min_diff = numeric_limits<int>::max();

    vector<int> sortA = A;
    vector<int> sortB = B;

    sort(sortA.begin(), sortA.end());
    sort(sortB.begin(), sortB.end());

    int i = 0, j = 0;

    while(i < sortA.size() && j < sortB.size()){
        int result = abs(sortA[i] - sortB[j]);

        if(sortA[i] == sortB[j]){
            return 0;
        }

        min_diff = (min_diff > result) ? result : min_diff;

        sortA[i] < sortB[j] ? i++ : j++;
    }

    return min_diff;
}

int main()
{
    vector<int> list1 = {1, 10, -16, 20};
    vector<int> list2 = {3, 5, 8, 10};

    cout << minAbs(list1, list2) << '\n';
}
