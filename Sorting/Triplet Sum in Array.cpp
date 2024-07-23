int diff = 0;

// Function to compare values while sorting.
bool mycomparator(int a, int b) {

    // storing the difference of first number with diff.
    int a_diff = abs(a - diff);

    // storing the difference of second number with diff.
    int b_diff = abs(b - diff);

    // if a_diff is smaller than b_diff, it means we need to put a_diff
    // so we return true.
    if (a_diff < b_diff)
        return 1;

    // else we return false.
    return 0;
}

class Solution {
  public:
    // Function to sort the array according to difference with given number.
    void sortABS(int k, vector<int> &arr) {
        diff = k;
        // using stable sort function over the array.
        stable_sort(arr.begin(), arr.end(), mycomparator);
    }
};
