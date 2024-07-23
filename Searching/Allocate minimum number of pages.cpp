class Solution {
  public:
    // Helper function to check if it is possible to allocate books
    // such that the maximum number of pages allocated is <= curr_min
    bool isPossible(int arr[], int n, int m, long long curr_min) {
        int studentsRequired = 1;
        long long curr_sum = 0;

        for (int i = 0; i < n; i++) {
            // If a single book has more pages than curr_min, return false
            if (arr[i] > curr_min) return false;

            // If adding this book to current student's allocation exceeds curr_min
            // allocate to next student
            if (curr_sum + arr[i] > curr_min) {
                studentsRequired++;
                curr_sum = arr[i];

                // If number of students required exceeds the given students, return false
                if (studentsRequired > m) return false;
            } else {
                curr_sum += arr[i];
            }
        }
        return true;
    }

    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if (m > n) return -1;

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        long long start = 0, end = sum, result = LLONG_MAX;

        while (start <= end) {
            long long mid = (start + end) / 2;

            if (isPossible(arr, n, m, mid)) {
                result = min(result, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return result;
    }
};
int findPages(int arr[], int n, int m)
{
    long long sum = 0;
 
    if (n < m)
        return -1;
    int mx = INT_MIN;
 
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        mx = max(mx, arr[i]);
    }
 
    int start = mx, end = sum;
    int result = INT_MAX;
 
    while (start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid)) {
            result = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
 
    return result;
}
};
