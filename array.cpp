#include <bits/stdc++.h>

using namespace std;

long long int MODULO = 1000000007;

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printVect(vector<int> vt) {
    for (int i = 0; i < vt.size(); i++) {
        cout << vt[i] << " ";
    }
    cout << endl;
}

void print2dVect(vector<vector<int>> vt) {
    for (int i = 0; i < vt.size(); i++) {
        for (int j = 0; j < vt[i].size(); j++) {
            cout << vt[i][j] << " ";
        }
        cout << endl;
    }
}

long int factorial(int n) {
    // single line to find factorial
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

vector<int> unionOfSortedArrays(int arr1[], int arr2[], int size1, int size2) {
    int i = 0;
    int j = 0;
    cout << "im in" << size1 << " " << size2 << endl;
    vector<int> res;
    while (i < size1 && j < size2) {

        if (arr1[i] == arr1[i - 1]) {
            i++;
        } else if (arr2[j] == arr2[j - 1]) {
            j++;
        } else if (arr1[i] == arr2[j]) {
            j++;
        } else if (arr1[i] < arr2[j]) {
            res.push_back(arr1[i]);
            i++;
        } else if (arr1[i] > arr2[j]) {
            res.push_back(arr2[j]);
            j++;
        }

        cout << i << " " << j << endl;
    }

    if (i == size1) {
        while (j < size2) {
            if (arr2[j] == arr2[j - 1]) {
                j++;
            } else {
                res.push_back(arr2[j]);
                j++;
            }
        }
    }
    if (j == size2) {
        while (i < size1) {
            if (arr1[i] == arr1[i - 1]) {
                i++;
            } else {
                res.push_back(arr1[i]);
                i++;
            }
        }
    }

    // for(int k = 0; k < res.size(); k++) {
    //     cout << res[k] << " ";
    // }

    return res;
}

vector<int> intersectionOfSortedArrays(int arr1[], int arr2[], int size1,
                                       int size2) {
    int i = 0, j = 0;
    vector<int> res;

    // int arr[size] = {2, 5, 5, 7, 7, 12, 14, 20, 25, 25, 26, 26, 30, 40, 45,
    // 46, 46, 46, 47, 49}; int arr2[size2] = {4, 7, 9, 9, 9, 12, 20, 22, 22,
    // 30, 33, 40, 42, 42, 45, 48, 50};

    while (i < size1 && j < size2) {
        if (arr1[i] == arr2[j]) {
            res.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        }
    }

    for (int k = 0; k < res.size(); k++) {
        cout << res[k] << " ";
    }

    return res;
}

int findTheMissingNumber(int arr[], int size) {
    // given a array from 1 to size no duplicates find the missing one;

    long int sum = (size * (size + 1)) / 2;
    long int tempSum = 0;
    for (int i = 0; i < size - 1; i++) {
        sum -= arr[i];
    }

    return sum;
}

int findMissingUsingXOR(int arr[], int size) {
    int x1 = arr[0];
    int x2 = 0;
    for (int i = 1; i < size - 1; i++) {
        x1 = x1 ^ arr[i];
    }
    for (int i = 1; i <= size; i++) {
        x2 = x2 ^ i;
    }

    return (x1 ^ x2);
}

int minDistanceBetwTwoNum(int arr[], int size, int x, int y) {
    // given unsorted array return min distance between various pairs of x and y

    int temp = -1;
    int minDis = INT_MAX;
    for (int i = 0; i < size; i++) {
        if ((arr[i] == x || arr[i] == y) && temp == -1) {
            temp = i;
        } else if (arr[i] == x && arr[temp] == x) {
            temp = i;
        } else if (arr[i] == x && arr[temp] == y) {
            int num = i - temp;
            temp = i;
            if (num < minDis) {
                minDis = num;
            }
        } else if (arr[i] == y && arr[temp] == y) {
            temp = i;
        } else if (arr[i] == y && arr[temp] == x) {
            int num = i - temp;
            temp = i;
            if (num < minDis) {
                minDis = num;
            }
        }
    }
    return minDis;
}

void printLeaders(int arr[], int size) {
    // leaders are the elements which are greater then all the elements to its
    // right
    int min = INT_MIN;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] > min) {
            cout << arr[i] << " ";
            min = arr[i];
        }
    }
    cout << endl;
}

int majorityElement(int arr[], int size) {
    int idx = 0;
    int count = 1;

    for (int i = 0; i < size; i++) {
        if (arr[idx] == arr[i]) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            idx = i;
            count = 1;
        }
    }
    cout << arr[idx] << endl;

    int mj = arr[idx];
    int mjCount = 0;

    for (int i = 0; i < size; i++) {

        if (arr[i] == mj) {
            mjCount++;
        }
    }

    if (mjCount > size / 2) {
        return mj;
    }

    cout << "None";
    exit(EXIT_FAILURE);
}

int numOccuringOddTimes(int arr[], int size) {
    // given a arr of integers all occuring even times except one
    int xr = arr[0];

    for (int i = 1; i < size; i++) {
        xr = xr ^ arr[i];
    }

    return xr;
}

void replacWithGreatestonRight(int arr[], int size) {
    // replace each element with greatest element on its right
    int max = -1;
    for (int i = size - 1; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = max;
        if (temp > max) {
            max = temp;
        }
    }
}

int fixedPoint(int arr[], int size, int start, int end) {
    // fixedPoint a element for which arr[i] == i arr is sorted elements are
    // distinct
    // linear search would work but binary search

    if (arr[start] == start) {
        return start;
    } else if (start == end) {
        cout << "NO FIXED POINT" << endl;
        exit(EXIT_FAILURE);
    }

    int mid = (start + end) / 2;
    if (arr[mid] == mid) {
        return mid;
    } else if (arr[mid] < mid) {
        return fixedPoint(arr, size, mid + 1, end);
    } else if (arr[mid] > mid) {
        return fixedPoint(arr, size, start, mid);
    }

    return 0;
}

int peakElement(int arr[], int size, int start, int end) {

    int mid = (start + end) / 2;

    if (mid == 0 && arr[0] >= arr[1]) {
        return arr[0];
    } else if (mid == size - 1 && arr[mid] >= arr[mid - 1]) {
        return arr[size - 1];
    } else if (arr[mid] < arr[mid - 1]) {
        return peakElement(arr, size, start, mid);
    } else if (arr[mid] < arr[mid + 1]) {
        return peakElement(arr, size, mid + 1, end);
    } else {
        return arr[mid];
    }
}

int peakIndexInMountainArray(vector<int> &arr, int start, int end) {
    int size = arr.size();

    int mid = (start + end) / 2;

    if (mid == 0 && arr[0] > arr[1]) {
        return mid;
    } else if (mid == size - 1 && arr[mid] > arr[mid - 1]) {
        return mid;
    } else if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
        return mid;
    } else if (arr[mid] > arr[mid + 1]) {
        return peakIndexInMountainArray(arr, start, mid);
    } else if (arr[mid] < arr[mid + 1]) {
        return peakIndexInMountainArray(arr, mid + 1, end);
    }

    return 0;
}

int countIncreasingSubarrs(int arr[], int size) {
    int count = 0;
    int maxlen = 0;
    int maxel = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > maxel) {
            maxel = arr[i];
            maxlen++;
        } else {
            maxlen--;
            count += (maxlen * (maxlen + 1)) / 2;
            cout << count << endl;
            maxel = arr[i];
            maxlen = 1;
        }
    }
    maxlen--;
    count += (maxlen * (maxlen + 1)) / 2;

    return count;
}

bool pythagoresTriplet(int arr[], int size) {
    // a2 = b2 + c2   n2 + nlogn instead n3
    for (int i = 0; i < size; i++) {
        arr[i] = pow(arr[i], 2);
    }

    sort(arr, arr + size);

    // a = b + c;
    int a, b, c;
    for (int i = size - 1; i >= 0; i--) {
        a = arr[i];
        int bi = 0;
        int ci = i - 1;
        while (bi < ci) {
            b = arr[bi];
            c = arr[ci];

            if (a < b + c) {
                ci--;
            } else if (a > b + c) {
                bi++;
            } else if (a == (b + c)) {
                return true;
            }
        }
    }
    return false;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void segregateZeroAndOne(int arr[], int size) {

    int i = 0;
    int j = 0;
    while (i < size && j < size) {

        swap(arr, i, j);

        while (arr[i] != 1 && i < size) {
            i++;
        }

        while (arr[j] != 0 && j < size) {
            j++;
        }
    }
}

void printRepitingEl(int arr[], int size) {
    // arr of size n elements from 1 to n-1

    for (int i = 0; i < size; i++) {
        if (arr[abs(arr[i])] < 0) {
            cout << abs(arr[i]) << " ";
        } else {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        }
    }
}

int bitonicSubarray(int arr[], int size) {
    // maxlen of increasing then decreasing subarray
    int inclr[size] = {1};
    int incrl[size] = {1};
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] <= arr[i]) {
            incrl[i] = incrl[i - 1] + 1;
        } else {
            incrl[i] = 1;
        }
    }
    for (int i = size - 2; i >= 0; i--) {
        if (arr[i] >= arr[i + 1]) {
            inclr[i] = inclr[i + 1] + 1;
        } else {
            inclr[i] = 1;
        }
    }
    int maxlen = 0;
    for (int i = 0; i < size; i++) {
        int temp = (inclr[i] + incrl[i] - 1);
        if (temp > maxlen) {
            maxlen = temp;
        }
    }
    return maxlen;
}

int mergeOperation(int arr[], int size) {
    // given a arr return number of merge operations required to make a
    // palindrome

    int i = 0;
    int j = size - 1;
    int operations = 0;
    while (i <= j) {
        cout << arr[i] << " " << arr[j] << endl;
        if (arr[i] == arr[j]) {
            i++;
            j--;
        } else if (arr[i] < arr[j]) {
            operations++;
            i++;
            arr[i] += arr[i - 1];
        } else if (arr[i] > arr[j]) {
            operations++;
            j--;
            arr[j] += arr[j + 1];
        }
    }

    return operations;
}

int maxDiffBetwTwoEl(int arr[], int size) {
    // return max difference between arr[i] - arr[j] such that j > 1;

    int minEl = arr[0];
    int maxDiff = INT_MIN;
    for (int i = 0; i < size; i++) {
        int temp = arr[i] - minEl;

        if (arr[i] < minEl) {
            minEl = arr[i];
        }
        if (temp > maxDiff) {
            maxDiff = temp;
        }
    }

    return maxDiff;
}

void reverseArray(int arr[], int start, int end) {
    if (start == end || start > end) {
        return;
    }
    swap(arr, start, end);
    reverseArray(arr, start + 1, end - 1);
    return;
}

int countOfBSTS(int arr[], int start, int end, int head) {

    if (start + 1 == end || start > end) {
        return 1;
    }

    int lt = 0;
    int rt = 0;

    for (int i = start; i < head; i++) {
        int temp = countOfBSTS(arr, start, head - 1, i);
        cout << start << " " << head - 1 << " " << i << " " << temp << endl;
        lt += temp;
    }
    for (int i = head + 1; i <= end; i++) {
        rt += countOfBSTS(arr, head + 1, end, i);
    }

    // lt = lt == 0 ? 1 : lt;
    // rt = rt == 0 ? 1 : rt;
    return lt * rt;
}

float medianOfTwoSortedArr(vector<int> arr, vector<int> arr2) {
    int size = arr.size();
    int size2 = arr2.size();

    if (size == 0) {
        return size2 % 2 == 1 ? arr2[size2 / 2]
                              : (arr2[size2 / 2] + arr2[size2 / 2 - 1]) / 2.0;
    } else if (size2 == 0) {
        return size % 2 == 1 ? arr[size / 2]
                             : (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
    }

    int totalLength = size + size2;
    int low = 0;
    int high = size;
    bool check = false;
    while (low <= high) {
        int i = (low + high) / 2;
        int j = (size + size2 + 1) / 2 - i;

        int maxLeftX = i == 0 ? INT32_MIN : arr[i - 1];
        int minRightX = i == size ? INT32_MAX : arr[i];

        int maxLeftY = j <= 0 ? INT32_MIN : arr2[j - 1];
        int minRightY = j == size2 ? INT32_MAX : arr2[j];

        cout << "Im in " << maxLeftX << " " << minRightX << " " << maxLeftY
             << " " << minRightY << endl;
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((size + size2) % 2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) /
                       2.0;
            } else {
                return max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftY > minRightX) {
            low = i + 1;
        } else if (maxLeftX > minRightY) {
            high = i - 1;
        }
    }

    return 0;
}

double mediantt(vector<int> &arr1, vector<int> &arr2) {
    int s1 = arr1.size();
    int s2 = arr2.size();
    int i = 0, j = 0;

    vector<int> result;
    while (i < s1 && j < s2) {
        if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        }

        else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    while (i < s1) {
        result.push_back(arr1[i]);
        i++;
    }
    while (j < s2) {
        result.push_back(arr2[j]);
        j++;
    }
    int temp = result.size();
    printVect(result);
    cout << result[temp / 2] << "  " << result[temp / 2 - 1] << endl;
    return temp % 2 == 0 ? (result[temp / 2] + result[temp / 2 - 1]) / 2.0
                         : result[temp / 2];
}

vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int a, b, c;
    int size = nums.size();
    set<vector<int>> res;
    for (int i = 0; i < size - 2; i++) {

        int j = i + 1;
        int k = size - 1;
        while (j < k) {

            if (nums[k] < 0) {
                break;
            }

            if (nums[k] == 0 && nums[j] == 0 && nums[i] == 0) {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                res.insert(temp);
                break;
            }

            if (nums[i] + nums[j] + nums[k] == 0) {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                res.insert(temp);
                j++;
                k--;
            }

            else if (nums[i] + nums[j] + nums[k] > 0) {
                k--;
            } else if (nums[i] + nums[j] + nums[k] < 0) {
                j++;
            }
        }
    }
    vector<vector<int>> ans;

    for (auto it = res.begin(); it != res.end(); ++it) {
        ans.push_back(*it);
    }

    // for(int i = 0; i < ans.size(); i++) {
    //     for(int j= 0; j < ans[i].size(); j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "im out";
    return ans;
}

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int a, b, c;
    int size = nums.size();
    set<vector<int>> res;
    for (int i = 0; i < size - 3; i++) {

        for (int l = i + 1; l < size - 2; l++) {

            int j = l + 1;
            int k = size - 1;
            while (j < k) {

                int tempSum = nums[i] + nums[j] + nums[k] + nums[l];

                if (tempSum == target) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.insert(temp);
                    j++;
                    k--;
                }

                else if (tempSum > target) {
                    k--;
                } else if (tempSum < target) {
                    j++;
                }
            }
        }
    }
    vector<vector<int>> ans;

    for (auto it = res.begin(); it != res.end(); ++it) {
        ans.push_back(*it);
    }

    // for(int i = 0; i < ans.size(); i++) {
    //     for(int j= 0; j < ans[i].size(); j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "im out";
    return ans;
}

int threeSumClosest(vector<int> &nums, int target) {

    sort(nums.begin(), nums.end());

    int a, b, c;
    int size = nums.size();
    set<vector<int>> res;
    int sum = 0;
    int minDiff = INT_MAX;
    for (int i = 0; i < size - 2; i++) {

        int j = i + 1;
        int k = size - 1;
        while (j < k) {

            int tempSum = nums[i] + nums[j] + nums[k];
            int tempDiff = tempSum - target;

            if (abs(tempDiff) < minDiff) {
                minDiff = abs(tempDiff);
                sum = tempSum;
            }

            if (tempDiff == 0) {
                return tempSum;
            } else if (tempDiff > 0) {
                k--;
            } else if (tempDiff < 0) {
                j++;
            }

            cout << k << " " << j << endl;
        }
    }

    return sum;
}

int removeDuplicates(vector<int> &nums) {
    // returns final length after romoval of duplicates
    int size = nums.size();
    if (size == 0) {
        return 0;
    }

    int curr = 0;
    int prev = 1;
    int nxt = 1;

    while (nxt < size) {

        if (nums[nxt] <= nums[curr]) {
            nxt++;
        } else {
            swap(nums, prev, nxt);
            prev++;
            curr++;
            nxt++;
        }
    }
    printVect(nums);
    return prev;
}

int removeElement(vector<int> &nums, int val) {
    // removes all the instances of val and returns len

    int size = nums.size();

    if (size == 0 || (size == 1 && nums[0] == val)) {
        return 0;
    }

    int curr = 0;
    int nxt = 0;

    while (nxt < nums.size()) {
        if (nums[nxt] != val) {
            swap(nums, nxt, curr);
            curr++;
            nxt++;
        } else {
            nxt++;
        }
    }
    // printVect(nums);
    // cout << curr << " " << nums[curr-1] << endl;
    return curr;
}

int binarySearch(vector<int> arr, int l, int r, int x) {
    if (r >= l) {
        int mid = (r + l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int binarySearch2(vector<int> arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] < x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int searchElinRotatedArr(vector<int> &nums, int target) {

    int size = nums.size();
    int pivot = size;
    for (int i = 1; i < size; i++) {
        if (nums[i - 1] > nums[i]) {
            pivot = i;
        }
    }

    cout << pivot << endl;

    int index = -1;

    if (target >= nums[0] && target <= nums[pivot - 1]) {
        index = binarySearch(nums, 0, pivot, target);
    } else {
        index = binarySearch(nums, pivot, size, target);
    }

    return index;
}

int firstOccurenceBS(vector<int> &arr, int start, int end, int target) {
    if (start <= end) {

        int mid = (start + end) / 2;

        if (mid == 0 && arr[mid] == target) {
            return mid;
        } else if (arr[mid] == target && arr[mid - 1] < target) {
            return mid;
        } else if (target > arr[mid]) {
            return firstOccurenceBS(arr, mid + 1, end, target);
        } else {
            return firstOccurenceBS(arr, start, mid - 1, target);
        }
    }
    return -1;
}

int lastOccurenceBS(vector<int> &arr, int start, int end, int target) {

    if (start <= end) {
        int mid = (start + end) / 2;

        if (mid == arr.size() - 1 && arr[mid] == target) {
            return mid;
        } else if (arr[mid] == target && arr[mid + 1] > target) {
            return mid;
        } else if (arr[mid] > target) {
            return lastOccurenceBS(arr, start, mid - 1, target);
        } else {
            return lastOccurenceBS(arr, mid + 1, end, target);
        }
    } else {
        return -1;
    }
}

int maxSumSubarray(vector<int> arr) {
    // kadane's algo return the maximum sum of possible subarray
    int size = arr.size();
    long int maxSum = INT_MIN;
    long int tempSum = arr[0] < 0 ? arr[0] : INT_MIN;

    for (int i = 0; i < size; i++) {
        tempSum += arr[i];

        if (arr[i] > tempSum) {
            tempSum = arr[i];
        }

        if (tempSum > maxSum) {
            maxSum = tempSum;
        }
    }
    return maxSum;
}

int **dp;

void printComb(vector<int> arr, vector<int> &res, int target, int i,
               set<vector<int>> &st) {
    cout << "target: " << target << " "
         << "idx " << i << endl;
    if (i == 0 && target != 0 && dp[i][target]) {
        cout << "first if \n";
        res.push_back(arr[i]);
        sort(res.begin(), res.end());
        st.insert(res);
        printVect(res);
        return;
    }
    if (target >= 0 && dp[i][target] == 0) {
        cout << "second \n";
        if (!res.empty()) {
            res.pop_back();
        }
        return;
    }

    if (dp[i][target] && target == 0) {
        cout << "3 rd if \n";
        sort(res.begin(), res.end());
        st.insert(res);
        printVect(res);
        return;
    }

    if (dp[i - 1][target]) {
        cout << " im in" << endl;
        vector<int> b = res;
        printComb(arr, b, target, i - 1, st);
    }

    if (target >= arr[i] && i != 0 && dp[i][target]) {
        cout << "going in \n";
        target -= arr[i];
        res.push_back(arr[i]);
        printComb(arr, res, target, i - 1, st);
    }
}

int uniquePaths(int m, int n) {

    int **arr = new int *[m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }
    arr[0][0] = 1;
    for (int i = 1; i < m; i++) {
        arr[i][0] = 1;
    }
    for (int j = 1; j < n; j++) {
        arr[0][j] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }

    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return arr[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>> &arr) {

    if (arr[0][0] == 1) {
        return 0;
    }
    int m = arr.size();
    int n = arr[0].size();
    int rtBlocked = false;
    bool downBlocked = false;
    for (int i = 0; i < m; i++) {
        if (arr[i][0] == 0 && !downBlocked) {
            arr[i][0] = 1;
        } else if (arr[i][0] == 1) {
            arr[i][0] = 0;
            downBlocked = true;
        }
    }
    for (int j = 1; j < n; j++) {
        if (arr[0][j] == 0 && !rtBlocked) {
            arr[0][j] = 1;
        } else if (arr[0][j] == 1) {
            arr[0][j] = 0;
            rtBlocked = true;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            arr[i][j] = arr[i][j] == 1 ? 0 : arr[i - 1][j] + arr[i][j - 1];
        }
    }

    return arr[m - 1][n - 1];
}

int minPathSum(vector<vector<int>> &arr) {
    // given a 2d matrix return the minimum sum possible top-left to
    // bottom-right
    int m = arr.size();
    int n = arr[0].size();

    for (int i = 1; i < m; i++) {
        arr[i][0] += arr[i - 1][0];
    }
    for (int j = 1; j < n; j++) {
        arr[0][j] += arr[0][j - 1];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            arr[i][j] += min(arr[i - 1][j], arr[i][j - 1]);
        }
    }

    return arr[m - 1][n - 1];
}

int dpStairs[100000] = {0};

int climbStairs(int n) {
    // given n number of stairs you can take 1 step or 2 return in how many ways
    // you can get to the top

    if (n == 1 || n == 0) {
        return 1;
    }

    if (dpStairs[n] != 0) {
        return dpStairs[n];
    }

    int temp = climbStairs(n - 1) + climbStairs(n - 2);
    dpStairs[n] = temp;

    return temp;
}

int maxRectAreaHistogram(vector<int> &hist) {
    stack<int> st;
    stack<int> idx;
    int size = hist.size();
    int maxArea = 0;
    int i = 0;
    while (i < size) {

        if (st.empty() || hist[st.top()] <= hist[i]) {
            st.push(i++);
        } else {
            int tp = st.top();
            st.pop();
            int area = hist[tp] * (st.empty() ? i : (i - st.top() - 1));

            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    while (st.empty() == false) {
        int tp = st.top();
        st.pop();
        int area = hist[tp] * (st.empty() ? i : i - st.top() - 1);

        if (maxArea < area)
            maxArea = area;
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix) {
    // returns max possible area of rect of 1's

    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> arr(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i].push_back(int(matrix[i][j]) - 48);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            cout << arr[i][j] << " ";
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = arr[i][j] == 0 ? arr[i][j] : arr[i][j] + arr[i - 1][j];
        }
    }

    int maxArea = 0;
    for (int i = 0; i < m; i++) {
        int area = maxRectAreaHistogram(arr[i]);
        if (area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
}

int numDecodings(string arr, vector<int> &dpVect, int i) {
    // given a array of numbers, reuturn count of ways the arrat can be
    // decoded back to alphabets acc to mapping A - 1, Z - 26
    // i = 0;
    if (i == arr.size() - 1 || i == arr.size()) {
        return 1;
    }

    if (dpVect[i] != 0) {
        return dpVect[i];
    }

    int n1 = arr[i] - 48;
    int n2 = (arr[i] - 48) * 10 + (arr[i + 1] - 48);
    n1 = numDecodings(arr, dpVect, i + 1);
    n2 = ((n2 < 27) ? numDecodings(arr, dpVect, i + 2) : 0);
    dpVect[i + 1] = n1;
    dpVect[i + 2] = n2;
    return n1 + n2;
}

long int countUniqueBST(int n) {
    vector<long int> arr(n + 1, 0);
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] += (2 * arr[i - 1]);
        arr[i] += i % 2 == 0 ? 0 : arr[i / 2] * arr[i / 2];
        for (int j = 1; j < i / 2; j++) {
            arr[i] += 2 * arr[i - j - 1] * arr[j];
        }
    }
    for (int i = 0; i < n + 1; i++) {
        cout << arr[i] << ' ';
    }

    return arr[n];
}

vector<int> nextMin(vector<int> arr) {
    int size = arr.size();
    stack<int> s;
    s.push(0);

    vector<int> res(size, -1);

    for (int i = 1; i < size; i++) {

        if (s.empty()) {
            s.push(i);
            continue;
        }

        while (!s.empty() && arr[s.top()] > arr[i]) {
            int top = s.top();
            res[top] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return res;
}

int minimumTotal(vector<vector<int>> &triangle) {
    // given a traingle like bt shape find min path sum from top to bottom
    // you can go down and adjacent element down to it;

    int m = triangle.size();
    int n = triangle[m - 1].size();

    if (m == 0) {
        return 0;
    }

    vector<vector<int>> dp(m);

    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (i == m - 1) {
                dp[i].push_back(triangle[i][j]);
            } else {
                int tempMin = min(dp[i + 1][j], dp[i + 1][j + 1]);
                dp[i].push_back(tempMin + triangle[i][j]);
            }
        }
    }

    // print2dVect(dp);

    // int **dp = new int*[m];
    // for(int i = 0; i < m; i++) {
    //     dp[i] = new int[n];
    //     for(int j = 0; j < n; j++) {
    //         dp[i][j] = INT_MIN;
    //     }
    // }
    // int minSum = minimunTotalHelper(triangle, 0, 0, dp);
    // return minSum;
    return dp[0][0];
}

int maxProfit(vector<int> &prices) {
    // best time to buy and sell stock

    int size = prices.size();
    if (size == 0) {
        return 0;
    }

    int max = prices[size - 1];
    int dp[size];
    for (int i = size - 1; i >= 0; i--) {
        if (max < prices[i]) {
            max = prices[i];
        }
        dp[i] = max;
    }

    for (int i = 0; i < size; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    int maxprofit = 0;
    for (int i = 0; i < size; i++) {
        int temp = dp[i] - prices[i];
        if (temp > maxprofit) {
            maxprofit = temp;
        }
    }
    return maxprofit;
}

int maxProfit2Rec(vector<int> &arr, int s) {
    // buy and sell stock 1 transaction at one day
    int size = arr.size();

    if (s == size) {
        return 0;
    }

    int maxPr = 0;
    for (int i = s; i < size; i++) {
        int maxP = 0;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int p = arr[j] - arr[i];
                int temp = maxProfit2Rec(arr, j + 1) + p;
                if (temp > maxP) {
                    maxP = temp;
                }
            }
        }

        if (maxP > maxPr) {
            maxPr = maxP;
        }
    }

    return maxPr;
}

int maxProfit2(vector<int> &arr, int fee) {
    int size = arr.size();

    if (size == 1) {
        return 0;
    }

    int pt = 0;
    for (int i = 1; i < size; i++) {
        int temp = arr[i] - arr[i - 1] - fee;
        if (temp > 0) {
            cout << pt << "  " << arr[i] - arr[i - 1] << endl;
            pt += arr[i] - arr[i - 1];
        }
    }
    cout << pt << endl;
    return pt;
}

int maxProfit3(vector<int> &prices) {
    // buy and sell stock 3
    int size = prices.size();
    if (size == 0) {
        return 0;
    }
    int max = -1;
    int dp[size];
    for (int i = size - 1; i >= 0; i--) {
        dp[i] = max;
        if (max < prices[i]) {
            max = prices[i];
        }
    }
    // printVect(prices);
    // printArr(dp, size);

    vector<int> profitVT;
    int maxprofit = 0;
    for (int i = 0; i < size; i++) {
        if (prices[i] == dp[i - 1] && i != 0) {
            profitVT.push_back(maxprofit);
            maxprofit = 0;
            // cout << i << " " << prices[i] << " " <<  dp[i] << endl;
            continue;
        }
        int temp = dp[i] - prices[i];
        if (temp > maxprofit) {
            maxprofit = temp;
        }
    }
    printVect(profitVT);
    int mx1 = 0;
    int mx1Idx;
    int mx2 = 0;
    for (int i = 0; i < profitVT.size(); i++) {
        if (profitVT[i] > mx1) {
            mx1 = profitVT[i];
            mx1Idx = i;
        }
    }
    for (int i = 0; i < profitVT.size(); i++) {
        if (profitVT[i] > mx2 && i != mx1Idx) {
            mx2 = profitVT[i];
        }
    }
    cout << mx1 + mx2 << endl;
    return (mx1 + mx2);
}

int maxProductSubarray(vector<int> &arr) {
    int size = arr.size();
    if (size == 0) {
        return 0;
    }
    int maxP = 1;
    int minP = 1;
    int maximum = INT_MIN;
    for (int i = 0; i < size; i++) {
        int temp = maxP;
        maxP = max(max(maxP * arr[i], minP * arr[i]), arr[i]);
        minP = min(min(temp * arr[i], minP * arr[i]), arr[i]);

        if (maxP > maximum) {
            maximum = maxP;
        }

        if (arr[i] == 0) {
            maxP = 1;
            minP = 1;
            continue;
        }
    }
    return maximum;
}

int calculateMinimumHP(vector<vector<int>> &arr) {
    // given a 2d array return minimum energy required to get right bottom from
    // top left

    int m = arr.size();
    int n = arr[0].size();

    vector<vector<int>> arr2(m);

    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (m == 1 && n == 1) {
        if (arr[0][0] > 0) {
            return 1;
        } else {
            return 0 - arr[0][0] + 1;
        }
    }

    int **dp = new int *[m];
    for (int i = 0; i < m; i++) {
        dp[i] = new int[n];

        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = arr[0][0] > 0 ? 1 : 0 - arr[0][0] + 1;
    int tempEn = arr[0][0];
    for (int i = 1; i < m; i++) {
        tempEn += arr[i][0];
        dp[i][0] =
            tempEn > 0 ? dp[i - 1][0] : max(dp[i - 1][0], 0 - tempEn + 1);
        arr[i][0] += arr[i - 1][0];
    }
    tempEn = arr[0][0];
    for (int i = 1; i < n; i++) {
        tempEn += arr[0][i];
        dp[0][i] =
            tempEn > 0 ? dp[0][i - 1] : max(dp[0][i - 1], 0 - tempEn + 1);
        arr[0][i] += arr[0][i - 1];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr2[i].push_back(arr[i][j]);
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {

            if (arr[i - 1][j] < arr[i][j - 1]) {
                arr[i][j] += arr[i][j - 1];
                dp[i][j] = arr[i][j] > 0 ? dp[i][j - 1]
                                         : max(dp[i][j - 1], 0 - arr[i][j] + 1);
            } else if (arr[i - 1][j] > arr[i][j - 1]) {
                arr[i][j] += arr[i - 1][j];
                dp[i][j] = arr[i][j] > 0 ? dp[i - 1][j]
                                         : max(dp[i - 1][j], 0 - arr[i][j] + 1);
            } else {
                arr[i][j] += arr[i - 1][j];
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int res1 = dp[m - 1][n - 1];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {

            int t1 = arr2[i][j] + arr2[i - 1][j];
            int t2 = arr2[i][j] + arr2[i][j - 1];

            int d1 = t1 > 0 ? dp[i - 1][j] : max(dp[i - 1][j], 0 - t1 + 1);
            int d2 = t2 > 0 ? dp[i][j - 1] : max(dp[i][j - 1], 0 - t2 + 1);
            if (d1 < d2) {
                dp[i][j] = d1;
                arr2[i][j] += arr2[i - 1][j];
            } else {
                dp[i][j] = d2;
                arr2[i][j] += arr2[i][j - 1];
            }
        }
    }
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << res1 << " " << dp[m-1][n-1] << endl;
    return min(res1, dp[m - 1][n - 1]);
}

int findShortestSubArray(vector<int> &arr) {
    // findShortestSubarray having same degree(max freq of a num)
    int size = arr.size();
    int hashSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > hashSize) {
            hashSize = arr[i];
        }
    }
    vector<int> hash(hashSize + 1);
    vector<int> idx(hashSize + 1);
    int max = 0;
    for (int i = 0; i < size; i++) {
        hash[arr[i]]++;

        if (hash[arr[i]] > max) {
            max = hash[arr[i]];
        }
        idx[arr[i]] = i;
    }
    printVect(hash);
    printVect(idx);
    int minLength = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (hash[arr[i]] == max && idx[arr[i]] != -1) {
            int temp = idx[arr[i]] - i + 1;
            cout << arr[i] << " " << temp << endl;
            idx[arr[i]] = -1;
            if (temp < minLength) {
                minLength = temp;
            }
        }
    }
    return minLength;
}

int binarySearch3(vector<int> arr, int start, int end, int x) {
    // return mid if found else next el idx
    if (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            return binarySearch3(arr, mid + 1, end, x);
        }

        return binarySearch3(arr, start, mid - 1, x);
    }

    return start;
}

int triangleNumber(vector<int> &arr) {
    // return number of possible traigles can be made using arr el as edge

    int size = arr.size();
    sort(arr.begin(), arr.end());
    int count = 0;

    for (int i = 0; i < size - 2; i++) {
        if (arr[i] == 0) {
            continue;
        }
        for (int j = i + 1; j < size - 1 && arr[i] != 0; j++) {
            for (int k = j + 1; k < size; k++) {
                if (arr[i] + arr[j] > arr[k]) {
                    count++;
                } else {
                    break;
                }
            }
        }
    }
    return count;
}

vector<string> summaryRanges(vector<int> &arr) {
    int size = arr.size();

    int st = arr[0];
    vector<string> res;
    string tempSt;

    for (int i = 1; i < size; i++) {

        if (arr[i - 1] + 1 != arr[i]) {
            if (st == arr[i - 1]) {
                tempSt += to_string(st);
                res.push_back(tempSt);
                tempSt = "";
            } else {
                tempSt += to_string(st);
                tempSt += "->";
                tempSt += to_string(arr[i - 1]);
                res.push_back(tempSt);
                tempSt = "";
            }
            st = arr[i];
        }
    }
    if (st == arr[size - 1]) {
        tempSt += to_string(st);
        res.push_back(tempSt);
        tempSt = "";
    } else {
        tempSt += to_string(st);
        tempSt += "->";
        tempSt += to_string(arr[size - 1]);
        res.push_back(tempSt);
        tempSt = "";
    }

    return res;
}

vector<int> finalPrices(vector<int> &arr) {
    int size = arr.size();
    if (size == 0) {
        return arr;
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] >= arr[j]) {
                arr[i] -= arr[j];
                break;
            }
        }
    }
    printVect(arr);

    return arr;
}

int maxWidthRamp(vector<int> &arr) {
    int size = arr.size();

    if (size == 0) {
        return 0;
    }

    int mx = 0;
    vector<int> mxVect;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
            mxVect.push_back(i);
        }
    }
    mx = 0;
    for (int i = 0; i < size; i++) {

        int j = 0;
        while (arr[i] > arr[mxVect[j]]) {
            j++;
        }
        int temp = mxVect[j] - i;

        if (temp > mx) {
            mx = temp;
        }
    }
    return mx;
}

bool isPerfectCube(int N) {
    int cube_root;
    cube_root = round(cbrt(N));

    if (cube_root * cube_root * cube_root == N) {
        return true;
    } else {
        return false;
    }
}

bool isPerfectSquare(long double x) {

    long double sr = sqrt(x);

    return ((sr - floor(sr)) == 0);
}

bool isPrime(int n) {

    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int recc(vector<vector<int>> &dp, int i, int j, int ip, int jp) {

    if (i >= 10 || j >= 10 || i < 0 || j < 0) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int t1 = INT_MAX;
    int t2 = INT_MAX;
    int t3 = INT_MAX;
    int t4 = INT_MAX;
    int sum = i + j;
    int min = INT_MAX;
    int count = 0;

    if (isPrime(sum) && !(i + 1 == ip && j == jp)) {
        t1 = recc(dp, i + 1, j, i, j) + 1;
        if (t1 < min) {
            min = t1;
            dp[i][j] = min;
        }
    }

    if (!isPrime(sum) && !(i - 1 == ip && j == jp)) {
        t2 = recc(dp, i - 1, j, i, j) + 1;
        if (t2 < min) {
            min = t2;
            dp[i][j] = min;
        }
    }

    if (isPerfectCube(sum) ||
        isPerfectSquare(sum) && !(i == ip && j + 1 == jp)) {
        t3 = recc(dp, i, j + 1, i, j) + 1;
        if (t3 < min) {
            min = t3;
            dp[i][j] = min;
        }
    }

    if (t1 == INT_MAX && t2 == INT_MAX && t3 == INT_MAX) {
        t4 = recc(dp, i, j - 1, i, j) + 1;
        if (t4 < min) {
            min = t4;
            dp[i][j] = min;
        }
    }

    return min;
}

int inMaze(int x, int y) {

    vector<vector<int>> temp(10);
    vector<vector<int>> dp(10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i].push_back(-1);
        }
    }
    recc(dp, x, y, x, y);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[x][y];
}

vector<int> twoSum(vector<int> &nums, int target) {

    int size = nums.size();
    vector<pair<int, int>> pair;

    for (int i = 0; i < size; i++) {
        pair.push_back(make_pair(nums[i], i));
    }

    sort(pair.begin(), pair.end());
    int i = 0;
    int j = size - 1;
    while (true) {
        int temp = pair[i].first + pair[j].first;
        if (temp < target) {
            i++;
        } else if (temp > target) {
            j--;
        } else {
            vector<int> index;
            index.push_back(pair[i].second);
            index.push_back(pair[j].second);
            sort(index.begin(), index.end());
            return index;
        }
    }
}

int maxArea(vector<int> &arr) {
    int size = arr.size();

    int maxArea = 0;
    int tempArea = 0;
    int i = 0;
    int j = size - 1;

    while (i < j) {
        tempArea = min(arr[i], arr[j]) * (j - i);
        maxArea = tempArea > maxArea ? tempArea : maxArea;
        if (arr[i] > arr[j]) {
            j--;
        } else {
            i++;
        }
    }

    return maxArea;
}

void combinationSumUtil(vector<int> &arr, int target, int i, vector<int> &rs,
                        vector<vector<int>> &result) {
    if (target == 0) {
        result.push_back(rs);
    }

    for (int j = i; j < arr.size(); j++) {
        if (target - arr[j] >= 0) {
            rs.push_back(arr[j]);
            combinationSumUtil(arr, target - arr[j], j, rs, result);
        }
    }
    if (rs.size() > 0) {

        rs.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &arr, int target) {
    vector<vector<int>> result;
    vector<int> tempRs;
    combinationSumUtil(arr, target, 0, tempRs, result);
    return result;
}

vector<vector<int>> combinationSum2(vector<int> arr, int target) {
    // return subsets having sum equal to target;
    int size = arr.size();
    dp = new int *[size];

    for (int i = 0; i < size; i++) {
        dp[i] = new int[target + 1];
        dp[i][0] = 1;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 1; j < target + 1; j++) {
            dp[i][j] = 0;
        }
    }

    if (arr[0] <= target)
        dp[0][arr[0]] = true;

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < target + 1; j++) {
            dp[i][j] = (arr[i] <= j) ? dp[i - 1][j] || dp[i - 1][j - arr[i]]
                                     : dp[i - 1][j];
        }
    }
    vector<int> temp;
    set<vector<int>> st;
    printComb(arr, temp, target, arr.size() - 1, st);

    vector<vector<int>> res;
    for (auto it = st.begin(); it != st.end(); ++it) {
        res.push_back(*it);
    }
    return res;
}

void combinationSum3Util(int size, int target, int i, vector<int> &rs,
                         vector<vector<int>> &result) {
    // cout << "I: " << i << " T : " << target << "  " ;
    // printVect(rs);
    if (target == 0 && rs.size() == size) {
        result.push_back(rs);
        return;
    }
    if (rs.size() == size || i == 10) {
        return;
    }

    if (target - i >= 0) {
        rs.push_back(i);
        combinationSum3Util(size, target - i, i + 1, rs, result);
        if (rs.size() > 0) {
            rs.pop_back();
        }
    }

    combinationSum3Util(size, target, i + 1, rs, result);
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> rs;
    combinationSum3Util(k, n, 1, rs, result);
    return result;
}

long int findPermutations(vector<int> arr) {
    // Sort the given array
    sort(arr.begin(), arr.end());
    long int count = 0;
    do {
        count++;
    } while (next_permutation(arr.begin(), arr.end()));

    return count;
}

int combinationSum4Util(vector<int> &arr, int target, int count, vector<int> rs,
                        vector<vector<int>> &dp4) {
    // if(target > 0 && dp4[target][count] !=  0) {
    //     return dp4[target][count];
    // }
    // cout << "T: " << target << "  " << endl;
    if (target == 0) {
        printVect(rs);
        cout << findPermutations(rs) << endl;
        return findPermutations(rs);
    }
    if (target < 0 || count > arr.size()) {
        return 0;
    }

    int temp = 0;
    for (int i = count; i < arr.size(); i++) {
        rs.push_back(arr[i]);
        int tt = combinationSum4Util(arr, target - arr[i], i, rs, dp4);
        rs.pop_back();
        // if(target-arr[i] > 0) {
        //     dp4[target-arr[i]][i] = tt;
        // }
        temp += tt;
    }
    return temp;
}

int combinationSum4(vector<int> &arr, int target) {
    vector<vector<int>> dp4(target + 1);
    for (int i = 0; i < target + 1; i++) {
        for (int j = 0; j < arr.size() + 1; j++) {
            dp4[i].push_back(0);
        }
    }
    vector<int> rs;
    int temp = combinationSum4Util(arr, target, 0, rs, dp4);
    return temp;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int size = m + n;

    int idx = size - 1;
    int i = m - 1;
    int j = n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[idx] = nums1[i];
            i--;
            idx--;
        } else {
            nums1[idx] = nums2[j];
            j--;
            idx--;
        }
    }

    while (i >= 0) {
        nums1[idx] = nums1[i];
        i--;
        idx--;
    }

    while (j >= 0) {
        nums1[idx] = nums2[j];
        j--;
        idx--;
    }

    printVect(nums1);
}

vector<int> runningSum(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }
    printVect(nums);
    return nums;
}

int maximumWealth(vector<vector<int>> &accounts) {
    int maxWealth = 0;
    for (int i = 0; i < accounts.size(); i++) {
        int temp = 0;
        for (int j = 0; j < accounts[i].size(); j++) {
            temp += accounts[i][j];
        }
        maxWealth = temp > maxWealth ? temp : maxWealth;
    }

    return maxWealth;
}

bool compareIndex(pair<int, int> i1, pair<int, int> i2) {
    // if(i1.second == -1 || i2.second == -1) {
    //     return (i1.first < i2.first);
    // }
    return (i1.second < i2.second);
}

bool isEqual(pair<int, int> &element) { return true; }

void relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    vector<pair<int, int>> pair;
    vector<int> temp;
    // for(int i = 0; i < arr1.size(); i++) {
    //     auto itr = find(arr2.begin(), arr2.end(), arr1[i]);

    //     if(itr != arr2.end()) {
    //         auto it = find(pair.begin(), pair.end(), arr1[i]);
    //         if(it == pair.end()) {
    //             cout << "not found " << endl;
    //         }
    //         else {
    //             cout << " fkkdf ";
    //         }

    //     }
    //     else {
    //         temp.push_back(arr1[i]);
    //     }
    // }
    // sort(temp.begin(), temp.end());

    // for(auto x: pair) {
    //     cout << x.first << "  " << x.second << endl;
    // }

    // int i = 0;
    // map<int, int>::iterator itt;
    // vector<int> result;
    // itt = pair.begin();

    // while (itt != pair.end() && i < temp.size())
    // {
    //     if(itt->first < temp[i]) {
    //         for(int j = 0; j < itt->second; j++) {
    //             result.push_back(itt->first);
    //         }
    //         itt++;
    //     }
    //     else {
    //         result.push_back(temp[i]);
    //         i++;
    //     }
    // }

    // while(itt != pair.end()) {
    //     for(int j = 0; j < itt->second; j++) {
    //             result.push_back(itt->first);
    //         }
    //         itt++;
    // }

    // while(i < temp.size()) {
    //      result.push_back(temp[i]);
    //         i++;
    // }

    // printVect(result);
}

class SubrectangleQueries {
  public:
    vector<vector<int>> matrix;
    vector<vector<int>> index;
    SubrectangleQueries(vector<vector<int>> &rectangle) { matrix = rectangle; }

    void updateSubrectangle(int row1, int col1, int row2, int col2,
                            int newValue) {
        index.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {
        for (int i = index.size() - 1; i >= 0; i--) {
            if (index[i][0] <= row && index[i][2] >= row &&
                index[i][1] <= col && index[i][3] >= col) {
                return index[i][4];
            }
        }
        return matrix[row][col];
    }
};

int numTeams(vector<int> &arr) {
    int size = arr.size();
    int count = 0;
    vector<vector<int>> dpG(size);
    vector<vector<int>> dpS(size);
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[i]) {
                dpG[i].push_back(j);
            }
            if (arr[j] < arr[i]) {
                dpS[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < dpG.size() - 2; i++) {
        if (dpG[i].size() > 0) {
            for (int j = 0; j < dpG[i].size() - 1; j++) {
                count += dpG[dpG[i][j]].size();
            }
        }
    }
    for (int i = 0; i < dpS.size() - 2; i++) {
        if (dpS[i].size() > 0) {
            for (int j = 0; j < dpS[i].size() - 1; j++) {
                count += dpS[dpS[i][j]].size();
            }
        }
    }
    return count;
}

bool compare(int v1, int v2) { return (abs(v1) < abs(v2)); }

bool canReorderDoubled(vector<int> &arr) {
    int size = arr.size();
    sort(arr.begin(), arr.end(), compare);
    printVect(arr);
    unordered_map<int, int> mp(size);
    for (int i = 0; i < size; i++) {
        mp[arr[i]]++;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  " << mp[arr[i]] << endl;
        if (mp[arr[i]] == 0) {
            continue;
        }
        if (mp[2 * arr[i]] == 0) {
            return false;
        }

        mp[arr[i]]--;
        mp[2 * arr[i]]--;

        for (auto it : mp) {
            cout << it.first << " " << it.second << endl;
        }
        cout << "endl\n";
    }

    return true;
}

long int maxDistance(vector<int> &arr, int m) {
    int size = arr.size();
    sort(arr.begin(), arr.end());
    long int temp = 9;
    long int step = 1;
    long int max = INT32_MIN;
    while (temp--) {
        long int min = INT32_MAX;
        long int count = 1;
        for (long int i = step; i < size + step && count < m; i += step) {
            long int diff = count == m - 1 ? abs(arr[size - 1] - arr[i - step])
                                           : abs(arr[i] - arr[i - step]);
            min = diff < min ? diff : min;
            cout << min << endl;
            count++;
        }
        if (count != m) {
            break;
        }
        max = min > max ? min : max;
        step++;
    }

    return max;
}

void rotate(vector<int> &arr, int k) {
    int size = arr.size();
    k %= size;
    if (size == 0 || k == 0) {
        return;
    }
    int count = 0;
    int i = 0;
    int prev = arr[0];
    int next;
    int check = 0;
    while (count < size) {
        i += k;
        check += k;
        i = i < size ? i : i - size;
        next = arr[i];
        arr[i] = prev;
        prev = next;
        if (check % size == 0 && check % k == 0) {
            i++;
            check = 0;
            prev = arr[i];
        }
        printVect(arr);
        cout << endl;
        count++;
    }
}

void rotate(vector<int> &arr) {
    int n = arr.size();
    int carry = arr[n - 1];
    int current = arr[0];
    for (int i = 0; i < n; i++) {
        current = arr[i];
        arr[i] = carry;
        carry = current;
    }
}

bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp[nums[i]] > 0) {
            return false;
        }
        mp[nums[i]]++;
    }
    return true;
}

int singleNumber(vector<int> &arr) {
    int x = 0;
    for (int i = 0; i < arr.size(); i++) {
        x = x ^ arr[i];
        cout << x << " ";
    }
    return x;
}

vector<int> intersect(vector<int> &arr, vector<int> &arr2) {
    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;
    vector<int> result;
    while (i < arr.size() && j < arr2.size()) {
        if (arr[i] == arr2[j]) {
            result.push_back(arr[i]);
            i++;
            j++;
        } else if (arr[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    printVect(result);
    return result;
}

vector<int> plusOne(vector<int> &arr) {
    int size = arr.size();
    int carry = 0;
    arr[size - 1] += 1;
    if (arr[size - 1] == 10) {
        arr[size - 1] = 0;
        carry = 1;

        for (int i = size - 2; i >= 0; i--) {
            arr[i] += carry;
            if (arr[i] == 10) {
                arr[i] = 0;
                carry = 1;
            } else {
                return arr;
            }
        }

        if (arr[0] == 0) {
            arr[0] = 1;
            arr.push_back(0);
        }
    }

    return arr;
}

void moveZeroes(vector<int> &arr) {
    int size = arr.size();
    int i = 0, j = 0;
    while (i < size && j < size) {
        if (arr[i] != 0) {
            i++;
            j++;
        } else if (arr[i] == 0 && arr[j] != 0) {
            swap(arr, i, j);
            i++;
        } else {
            j++;
        }
    }

    printVect(arr);
}

bool isValid3X3(vector<vector<char>> &arr, int start, int end) {
    vector<int> hash = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = start; i < start + 3; i++) {
        for (int j = end; j < end + 3; j++) {
            int temp = arr[i][j] - 48;
            if (temp == -2) {
                continue;
            }
            hash[temp]++;
            if (hash[temp] > 1) {
                return false;
            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &arr) {

    for (int i = 0; i < arr.size(); i += 3) {
        for (int j = 0; j < arr[i].size(); j += 3) {
            bool temp = isValid3X3(arr, i, j);
            if (!temp) {
                return false;
            }
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        vector<int> hash = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vector<int> hash2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int j = 0; j < arr[i].size(); j++) {
            int temp = arr[i][j] - 48;
            int temp2 = arr[j][i] - 48;
            if (temp != -2) {
                hash[temp]++;
            }
            if (temp2 != -2) {
                hash2[temp2]++;
            }
            if (temp != -2 && hash[temp] > 1 ||
                temp2 != -2 && hash2[temp2] > 1) {
                return false;
            }
        }
    }
    return true;
}

int reverse(int x) {
    int result = 0;
    while (x) {
        result = (result * 10) + (x % 10);
        x /= 10;
    }
    return result;
}

void ambiguousCoordinates(string s) {
    int size = s.length();
    for (int i = 0; i < size - 1; i++) {
        cout << "(";
        for (int j = 0; j < size; j++) {
            if (j == i) {
                cout << s[i] << ", ";
            } else {
                cout << s[j];
            }
        }
        cout << ")" << endl;
    }
}

int distributeCandies(vector<int> &candyType) {
    sort(candyType.begin(), candyType.end());
    int k = candyType.size() / 2;
    int count = 1;
    k--;
    for (int i = 0; i < candyType.size() - 1; i++) {
        if (candyType[i] != candyType[i + 1] && k > 0) {
            count++;
            k--;
        }
    }

    return count;
}

vector<int> findErrorNums(vector<int> &nums) {
    vector<int> res;
    int sum = 0;
    int size = nums.size();
    int expectedSum = (size * (size + 1)) / 2;
    for (int i = 0; i < size; i++) {
        sum += abs(nums[i]);
        int num = abs(nums[i]) - 1;
        if (nums[num] < 0) {
            res.push_back(num + 1);
        } else {
            nums[num] = -nums[num];
        }
    }

    res.push_back(expectedSum - (sum - res[0]));
    return res;
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int findLHS(vector<int> &arr) {
    int size = arr.size();
    sort(arr.begin(), arr.end());
    map<long int, int> mp;
    for (int i = 0; i < size; i++) {
        mp[arr[i]]++;
    }

    int t1 = 0;
    int y1 = 0;

    int t2 = 0;
    int y2 = 0;
    int max = 0;
    for (auto i = mp.begin(); i != mp.end(); i++) {
        if (i == mp.begin()) {
            t1 = i->second;
            y1 = i->first;
        } else {
            t2 = i->second;
            y2 = i->first;

            if (abs(y1 - y2) == 1 && (t1 + t2) > max) {
                max = t1 + t2;
            }
            t1 = t2;
            y1 = y2;
        }
        cout << i->first << " " << i->second << endl;
    }

    return max;
}

int numberOfSteps(int num) {
    int count = 0;
    while (num) {
        num % 2 ? num-- : num / 2;
        count++;
    }
    return count;
}

int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int l = grid.size();
    int h = grid[0].size();

    if (grid[0][0] != 0 || grid[l - 1][h - 1] != 0) {
        return -1;
    }

    queue<vector<int>> q;
    q.push({0, 0, 1});
    grid[0][0] = 1;
    vector<vector<int>> step = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1},
    };
    int minSS = INT32_MAX;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            vector<int> temp = q.front();
            q.pop();
            int i = temp[0];
            int j = temp[1];

            if (i == l - 1 && j == h - 1) {
                return temp[2];
            }
            for (int tt = 0; tt < 8; tt++) {
                i = temp[0] + step[tt][0];
                j = temp[1] + step[tt][1];

                if (i >= 0 && i < l && j >= 0 && j < h && grid[i][j] == 0) {
                    q.push({i, j, temp[2] + 1});
                    grid[i][j] = 1;
                }
            }
        }
    }

    return -1;
}

void kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<pair<int, int>> mp;
    for (int i = 0; i < mat.size(); i++) {
        int count = 0;
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == 1) {
                count++;
            } else {
                break;
            }
        }
        mp.push_back(pair<int, int>(i, count));
    }

    sort(mp.begin(), mp.end(), cmp);
    vector<int> res;

    for (int i = 0; i < k; i++) {
        res.push_back(mp[i].first);
    }

    printVect(res);
}

int findMaxConsecutiveOnes(vector<int> &nums) {
    int count = 0;
    int max = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            count = 0;
        } else {
            count++;
        }

        if (count > max) {
            max = count;
        }
    }

    return max;
}

vector<int> sortedSquares(vector<int> &nums) {
    int size = nums.size();

    if (nums[0] >= 0) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        return nums;
    }

    if (nums[size - 1] <= 0) {
        for (int k = 0; k < size / 2; k++) {
            nums[k] *= nums[k];
            nums[size - 1 - k] *= nums[size - 1 - k];
            int tt = nums[k];
            nums[k] = nums[size - k - 1];
            nums[size - k - 1] = tt;
        }

        if (size % 2 == 1) {
            nums[size / 2] *= nums[size / 2];
        }

        return nums;
    }

    vector<int> res;

    int i = 0, j, dd = -1;

    for (int k = 0; k < nums.size(); k++) {
        if (nums[k] >= 0 && dd == -1) {
            j = k;
            i = k - 1;
            dd = k;
        }
        nums[k] *= nums[k];
    }

    printVect(nums);
    while (i >= 0 && j < nums.size()) {
        if (nums[i] < nums[j]) {
            res.push_back(nums[i]);
            i--;
        } else {
            res.push_back(nums[j]);
            j++;
        }
    }

    while (i >= 0) {
        res.push_back(nums[i]);
        i--;
    }

    while (j < nums.size()) {
        res.push_back(nums[j]);
        j++;
    }

    return res;
}

int countDigit(long long n, vector<int> &digit) {
    int count = 0;
    while (n != 0) {
        digit.push_back(n % 10);
        n = n / 10;
        ++count;
    }
    return count;
}

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    vector<int> digit;
    int size = countDigit(x, digit);
    for (int i = 0; i < size / 2; i++) {
        if (digit[i] != digit[size - 1 - i]) {
            return false;
        }
    }

    return true;
}

bool checkIfExist(vector<int> &arr) {
    vector<vector<int>> hash(2);
    hash[0] = vector<int>(1000 + 5);
    hash[1] = vector<int>(1000 + 5);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            hash[0][arr[i]] = -1;
        } else if (arr[i] < 0) {
            hash[1][abs(arr[i])] = -1;
        } else {
            hash[0][0]++;
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0 && 2 * arr[i] <= arr.size()) {
            if (hash[0][2 * arr[i]] == -1) {
                return true;
            }
        } else if (arr[i] < 0 && 2 * abs(arr[i]) <= arr.size()) {
            if (hash[1][2 * abs(arr[i])] == -1) {
                return true;
            }
        } else if (arr[i] == 0 && hash[0][0] > 1) {
            return true;
        }
    }
    return false;
}

bool validMountainArray(vector<int> &arr) {
    if (arr.size() < 3) {
        return false;
    }
    if (arr[1] < arr[0]) {
        return false;
    }

    bool inc = true;
    bool dec = false;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            return false;
        }
        if (inc) {
            if (arr[i] - arr[i - 1] < 0) {
                dec = true;
                inc = false;
            }
        } else {
            if (arr[i] - arr[i - 1] > 0) {
                return false;
            }
        }
    }

    return dec;
}

vector<int> sortArrayByParity(vector<int> &arr) {
    int size = arr.size();
    int even = size - 1, odd = 0;
    while (odd <= even) {
        if (arr[even] % 2 == 0 && arr[odd] % 2 == 1) {
            swap(arr, even, odd);
            even--;
            odd++;
        } else if (arr[odd] % 2 == 0) {
            odd++;
        } else if (arr[even] % 2 == 1) {
            even--;
        }
    }
    return arr;
}

int thirdMax(vector<int> &nums) {
    long int n1 = -1000000000000;
    long int n2 = -1000000000000;
    long int n3 = -1000000000000;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > n1) {
            n3 = n2;
            n2 = n1;
            n1 = nums[i];
        } else if (nums[i] > n2 && nums[i] < n1) {
            n3 = n2;
            n2 = nums[i];
        } else if (nums[i] > n3 && nums[i] < n2) {
            n3 = nums[i];
        }
    }

    if (n3 == -1000000000000) {
        return n1;
    }
    return n3;
}

vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            res.push_back(i + 1);
        }
    }
    return res;
}

string intToRoman(int num) {
    vector<int> ix = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> is = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                         "XL", "X",  "IX", "V",  "IV", "I"};

    string res = "";
    int i = 0;
    while (num != 0 && i <= 13) {
        int t = num / ix[i];
        if (t > 0) {
            while (t--) {
                res += is[i];
            }
            num = num % ix[i];
        }
        i++;
    }

    return res;
}

void rotate(vector<vector<int>> &mt) {
    int m = mt.size();
    for (int k = 0; k < m / 2; k++) {
        for (int i = k; i < m - k - 1; i++) {
            for (int j = 0; j < 3; j++) {
                int tt = mt[k][i];
                if (j == 0) {
                    mt[k][i] = mt[i][m - k - 1];
                    mt[i][m - k - 1] = tt;
                } else if (j == 1) {
                    mt[k][i] = mt[m - k - 1][m - i - 1];
                    mt[m - k - 1][m - i - 1] = tt;
                } else if (j == 2) {
                    mt[k][i] = mt[m - i - 1][k];
                    mt[m - i - 1][k] = tt;
                }
            }
        }
    }
}

long int coinChangeUtil(vector<int> &coins, int amount, int idx,
                        vector<vector<long int>> &dp) {
    // 2, 3, 4  = 17
    if (amount == 0) {
        return 0;
    }
    if (amount < 0 || idx >= coins.size()) {
        return INT32_MAX;
    }
    if (dp[idx][amount]) {
        return dp[idx][amount];
    }

    long int mt = min(1 + coinChangeUtil(coins, amount - coins[idx], idx, dp),
                      coinChangeUtil(coins, amount, idx + 1, dp));

    dp[idx][amount] = mt;

    return mt;
}

int coinChange(vector<int> &coins, int amount) {

    vector<vector<long int>> dp(coins.size() + 1);
    for (int i = 0; i < coins.size() + 1; i++) {
        dp[i] = vector<long int>(amount + 1);
    }
    long int res = coinChangeUtil(coins, amount, 0, dp);

    return res == INT32_MAX ? -1 : res;
}

int numFactoredBinaryTrees(vector<int> &arr) {
    map<long int, long int> mp;

    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]] = 1;
    }
    long int MODULO = 1000000007;
    long int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) {
            int div = arr[i] / arr[j];
            if (arr[i] % arr[j] == 0 && mp[div] != 0) {
                int t1 = mp[arr[j]];
                int t2 = mp[div];
                mp[arr[i]] += t1 * t2;
            }
        }
        count += mp[arr[i]];
        count = count % MODULO;
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << mp[arr[i]] << " ";
    }
    return count;
}

int firstBadVersionUtil(vector<int> arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        cout << mid << " ";
        cout << arr[mid] << endl;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return firstBadVersionUtil(arr, l, mid - 1, x);

        return firstBadVersionUtil(arr, mid + 1, r, x);
    }

    return -1;
}

int firstBadVersion() {
    vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    cout << firstBadVersionUtil(arr, 0, arr.size() - 1, 1) << endl;
    return 0;
}

int robUtil(vector<int> &nums, int i, vector<int> &dp) {

    if (i >= nums.size()) {
        return 0;
    }

    if (dp[i] != 0) {
        return dp[i];
    }

    int temp =
        max(robUtil(nums, i + 2, dp) + nums[i], robUtil(nums, i + 1, dp));
    dp[i] = temp;
    return temp;
}

int rob(vector<int> &nums) {
    vector<int> dp(nums.size());
    int sum = robUtil(nums, 0, dp);
    cout << sum << endl;
    return sum;
}

int maximumScore(vector<int> &nums, int k) {
    int maxLength = 0;
    int mxIdx = k;
    int minIdx = k;
    int min = k;
    int i = k, j = k - 1;
    while (i < nums.size() && j >= 0) {
        if (nums[i] >= min) {
            maxLength++;
            mxIdx = i;
            i++;
        }
        if (nums[j] >= min) {
            maxLength++;
            minIdx = j;
            j++;
        }

        if (nums[i] < min) {
        }
    }

    cout << minIdx << " " << maxLength << "  " << mxIdx << endl;
    return abs(mxIdx - minIdx + 1) * nums[k];
}

vector<vector<int>> subsetsUtil(vector<int> &nums, int i) {
    if (i >= nums.size()) {
        return {{}};
    }

    vector<vector<int>> temp = subsetsUtil(nums, i + 1);
    print2dVect(temp);
    vector<vector<int>> res;
    for (int j = 0; j < temp.size(); j++) {
        res.push_back(temp[j]);
        temp[j].push_back(nums[i]);
        res.push_back(temp[j]);
    }
    return res;
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    res = subsetsUtil(nums, 0);
    return res;
}

vector<vector<int>> subsetsBitMasking(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> res;

    for (int i = 0; i < pow(2, size); i++) {
        vector<int> temp;
        for (int j = 0; j < size; j++) {
            if ((i & (1 << j)) != 0) {
                temp.push_back(nums[j]);
            }
        }
        res.push_back(temp);
    }
    return res;
}

int singleNumber2(vector<int> &nums) {
    vector<int> bits(32);
    int positive = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < 32; j++) {
            if (nums[i] >= 0) {
                positive++;
            }
            if ((abs(nums[i]) & (1 << j)) != 0) {
                bits[j]++;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 32; i++) {
        if (bits[i] % 3 != 0) {
            res += pow(2, i);
        }
    }
    return positive % 3 == 0 ? -1 * res : res;
}

uint32_t reverseBits(uint32_t n, int k) {
    if (n <= 0) {
        return 0;
    }
    int res = reverseBits(n / 2, k + 1);
    cout << n % 2 << "";

    return (n % 2) * pow(2, k) + res;
}

int longestIncPathUtil(vector<vector<int>> &matrix, vector<vector<int>> &mtDp,
                       int i, int j) {

    if (i >= matrix.size() || j >= matrix[0].size()) {
        return 0;
    }

    if (mtDp[i][j] != -1) {
        return mtDp[i][j];
    }

    matrix[i][j] *= -1;
    int m = matrix.size();
    int n = matrix[0].size();

    int t1 = 0, t2 = 0, t3 = 0, t4 = 0;

    if (i + 1 < m) {
        if (matrix[i + 1][j] >= 0 && matrix[i + 1][j] > abs(matrix[i][j])) {
            t1 = longestIncPathUtil(matrix, mtDp, i + 1, j);
        }
    }
    if (i - 1 >= 0) {
        if (matrix[i - 1][j] >= 0 && matrix[i - 1][j] > abs(matrix[i][j])) {
            t2 = longestIncPathUtil(matrix, mtDp, i - 1, j);
        }
    }
    if (j + 1 < n) {
        if (matrix[i][j + 1] >= 0 && matrix[i][j + 1] > abs(matrix[i][j])) {
            t3 = longestIncPathUtil(matrix, mtDp, i, j + 1);
        }
    }
    if (j - 1 >= 0) {
        if (matrix[i][j - 1] >= 0 && matrix[i][j - 1] > abs(matrix[i][j])) {
            t4 = longestIncPathUtil(matrix, mtDp, i, j - 1);
        }
    }

    int res = max(max(t1, t2), max(t3, t4)) + 1;
    mtDp[i][j] = res;
    matrix[i][j] *= -1;
    return res;
}

int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> mtDp(m);
    for (int i = 0; i < m; i++) {
        mtDp[i] = vector<int>(n, -1);
    }

    int res = 0, max = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mtDp[i][j] == -1) {
                res = longestIncPathUtil(matrix, mtDp, i, j);
            } else {
                res = mtDp[i][j];
            }

            if (res > max) {
                max = res;
            }
        }
    }

    return max;
}

int removeDuplicates2(vector<int> &nums) {
    int size = nums.size();
    int i = 1, j = 1, c = 1;
    while (i < nums.size()) {
        if (nums[i] == nums[i - 1]) {
            c++;
            if (c <= 2) {
                nums[j] = nums[i];
                i++;
                j++;
            } else {
                i++;
            }
        } else {
            nums[j] = nums[i];
            c = 1;
            j++;
            i++;
        }
    }
    return j;
}

int minOperations(vector<int> &nums, int x) {
    int i, len = 0, sum1 = 0, sum2 = 0;
    for (i = 0; i < nums.size(); i++)
        sum2 += nums[i];

    sum2 -= x;

    if (sum2 == 0)
        return nums.size();

    int j;
    i = 0;
    for (j = 0; j < nums.size(); j++) {
        sum1 += nums[j];

        while (i < nums.size() && sum1 > sum2)
            sum1 -= nums[i++];

        if (sum1 == sum2)
            len = max(len, j - i + 1);
    }
    if (!len)
        return -1;
    return nums.size() - len;
}

int subarraySum(vector<int> &nums, int k) {
    int count = 0, size = nums.size();
    int tempSum = 0;
    map<int, int> mp;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
        int temp = sum - k;
        if (sum == k) {
            cout << i << " " << sum << endl;
            count++;
        }
        if (mp.find(temp) != mp.end()) {
            cout << i << " " << sum << " " << mp[temp] << endl;
            count += mp[temp];
        }

        if (mp.find(sum) == mp.end()) {
            mp[sum] = 1;
        } else {
            mp[sum]++;
        }
    }

    return count;
}

int spyDetected(vector<int> arr) {
    int size = arr.size();
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    if (a == b && b == c) {
        for (int i = 3; i < size; i++) {
            if (arr[i] != a) {
                return i + 1;
            }
        }
    } else if (a == b && b != c) {
        return 3;
    } else if (a == c && c != b) {
        return 2;
    } else {
        return 1;
    }

    return 0;
}

vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
    vector<long int> sum;
    vector<int> res;
    long int ss = 0;
    for (int i = 0; i < nums.size(); i++) {
        ss += nums[i];
        sum.push_back(ss);
    }

    int l = nums.size();
    res.push_back(ss - nums[0] * l);
    l--;

    for (int i = 1; i < nums.size(); i++) {
        long int temp = abs((nums[i] * i) - sum[i - 1]) +
                        abs((ss - sum[i - 1]) - (nums[i] * l));
        res.push_back(temp);
        l--;
    }

    return res;
}

int minFallingPathSumHelper(vector<vector<int>> &matrix, int i, int j,
                            vector<vector<int>> &dpt) {
    if (i == matrix.size() - 1 && j >= 0 && j <= matrix.size() - 1) {
        dpt[i][j] = matrix[i][j];
        return matrix[i][j];
    }
    if (j < 0 || j >= matrix.size()) {
        return INT32_MAX;
    }

    if (dpt[i][j] != -1) {
        return dpt[i][j];
    }

    int a = minFallingPathSumHelper(matrix, i + 1, j - 1, dpt) + matrix[i][j];
    int b = minFallingPathSumHelper(matrix, i + 1, j, dpt) + matrix[i][j];
    int c = minFallingPathSumHelper(matrix, i + 1, j + 1, dpt) + matrix[i][j];

    if (a <= b && a <= c) {
        dpt[i][j] = a;
        return a;
    } else if (b <= a && b <= c) {
        dpt[i][j] = b;
        return b;
    } else {
        dpt[i][j] = c;
        return c;
    }
}

int minFallingPathSum(vector<vector<int>> &matrix) {
    int size = matrix.size();
    vector<vector<int>> dpt(size, vector<int>(size, -1));
    int min = INT32_MAX;
    for (int i = 0; i < size; i++) {
        int temp = minFallingPathSumHelper(matrix, 0, i, dpt);
        if (temp < min) {
            min = temp;
        }
    }
    return min;
}

vector<int> mostCompetitive(vector<int> &nums, int k) {
    int size = nums.size();
    int len = size;
    stack<int> st;
    vector<int> res;

    for (int i = 0; i < size; i++) {
        while (!res.empty() && res.back() > nums[i] && res.size() + len > k) {
            res.pop_back();
        }
        res.push_back(nums[i]);
        len--;
    }

    while (res.size() > k) {
        res.pop_back();
    }

    return res;
}

int kthGrammar(int n, int k) {
    int i = n - 1;
    int count = 0;
    while (i > 0 && k != 1) {
        long long int size = pow(2, i);
        if (k > size / 2) {
            k = k - size / 2;
            count++;
        }
        i--;
    }
    return count % 2;
}

int nextBinarySearch(vector<int> &arr, int target, map<int, int> &mp) {
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;
    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] <= target)
            start = mid + 1;

        else {
            if (mp[mid] > 0) {
                ans = mid;
                mp[mid]--;
            }
            end = mid - 1;
        }
    }
    return ans;
}

bool cmpt(pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; }

vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
    int size = nums1.size();
    vector<pair<int, int>> res;
    vector<pair<int, int>> vp;
    map<int, int> mp;

    sort(nums1.begin(), nums1.end());

    for (int i = 0; i < size; ++i) {
        vp.push_back(make_pair(nums2[i], i));
    }

    sort(vp.begin(), vp.end());

    int j = size - 1;
    int k = 0;
    for (int i = size - 1; i >= 0 && j >= 0; i--) {
        if (nums1[j] > vp[i].first) {
            res.push_back(make_pair(nums1[j], vp[i].second));
            j--;
        } else {
            res.push_back(make_pair(nums1[k], vp[i].second));
            k++;
        }
    }

    sort(res.begin(), res.end(), cmpt);
    vector<int> tt;
    for (int i = size - 1; i >= 0; i--) {
        tt.push_back(res[i].first);
    }

    return tt;
}

int maxArea(int h, int w, vector<int> &hs, vector<int> &vs) {

    sort(hs.begin(), hs.end());
    sort(vs.begin(), vs.end());

    hs.push_back(h);
    vs.push_back(w);

    int hSize = hs.size();
    int vSize = vs.size();
    long long int maxH = hs[0];
    long long int maxV = vs[0];
    long long int temp;
    for (int i = 1; i < hSize; i++) {
        temp = hs[i] - hs[i - 1];
        if (temp > maxH) {
            maxH = temp;
        }
    }
    for (int i = 1; i < vSize; i++) {
        temp = vs[i] - vs[i - 1];
        if (temp > maxV) {
            maxV = temp;
        }
    }
    return ((maxH % MODULO) * (maxV % MODULO)) % MODULO;
}

string removeOuterParentheses(string s) {
    stack<char> st;

    int len = s.length();
    string res;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else {
            char c = st.top();
            st.pop();
            if (!st.empty()) {
                res += c;
                res += s[i];
            }
        }
    }

    return res;
}

vector<int> spiralOrder(vector<vector<int>> &mt) {

    int m = mt.size();
    int n = mt[0].size();
    int size = m * n;
    int check = 0;
    int a = 0, b = n, c = 0;
    int cnt = 0;
    vector<int> res;
    while (res.size() < size) {
        if (check == 0) {
            for (int j = a; j < b; j++) {
                res.push_back(mt[c][j]);
            }
            a = c + 1;
            c = b - 1;
            b = m - cnt;
            check = 1;
        } else if (check == 1) {
            for (int j = a; j < b; j++) {
                res.push_back(mt[j][c]);
            }
            a = c - 1;
            c = b - 1;
            check = 2;
            b = cnt;
        } else if (check == 2) {
            for (int j = a; j >= b; j--) {
                res.push_back(mt[c][j]);
            }
            a = c - 1;
            c = b;
            b = cnt + 1;
            check = 3;

        } else if (check == 3) {
            for (int j = a; j >= b; j--) {
                res.push_back(mt[j][c]);
            }
            a = c + 1;
            c = b;
            check = 0;
            cnt++;
            b = n - cnt;
        }
    }
    return res;
}

vector<vector<int>> generateMatrix(int n) {

    vector<vector<int>> mt(n, vector<int>(n));
    int size = n * n;
    int check = 0;
    int a = 0, b = n, c = 0;
    int cnt = 0;
    int count = 1;
    while (count <= n * n) {
        if (check == 0) {
            for (int j = a; j < b; j++) {
                // cout << mt[c][j] << " ";
                mt[c][j] = count++;
            }
            // cout << endl;
            a = c + 1;
            c = b - 1;
            b = n - cnt;
            check = 1;
        } else if (check == 1) {
            for (int j = a; j < b; j++) {
                // cout << mt[j][c] << " ";
                mt[j][c] = count++;
            }
            // cout << endl;
            a = c - 1;
            c = b - 1;
            check = 2;
            b = cnt;
        } else if (check == 2) {
            for (int j = a; j >= b; j--) {
                // cout << mt[c][j] << " ";
                mt[c][j] = count++;
            }
            // cout << endl;
            a = c - 1;
            c = b;
            b = cnt + 1;
            check = 3;

        } else if (check == 3) {

            for (int j = a; j >= b; j--) {
                // cout << mt[j][c] << " ";
                mt[j][c] = count++;
            }
            // cout << endl;
            a = c + 1;
            c = b;
            check = 0;
            cnt++;
            b = n - cnt;
        }
    }

    // print2dVect(mt);
    return mt;
}

int maxScore(vector<int> &arr, int k) {
    int size = arr.size();
    int req = size - k;

    int sum = 0;
    int totalSum = 0;
    for (int i = 0; i < req; i++) {
        sum += arr[i];
        totalSum += arr[i];
    }

    int j = 0;
    int minSum = sum;
    for (int i = req; i < size; i++) {
        sum = sum + arr[i] - arr[j];
        totalSum += arr[i];
        minSum = min(minSum, sum);
        j++;
    }

    return totalSum - minSum;
}

bool canJump(vector<int> &nums) {
    int dis = 0;
    for (int i = 0; i <= dis; i++) {
        dis = max(dis, i + nums[i]);
        if (dis >= nums.size() - 1) {
            return true;
        }
    }
    return false;
}

long int jumpUtil(vector<int> &nums, int i, vector<int> &dp) {
    int size = nums.size();

    if (i == size - 1) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    long int res = INT32_MAX;
    for (int j = 1; j <= nums[i]; j++) {
        if (i + j <= size - 1) {
            // cout << i << " i " << nums[i] << " j " << nums[i + j] << endl;
            long int chk = jumpUtil(nums, i + j, dp) + 1;
            // cout << res << " " << chk << endl;
            res = min(chk, res);
        }
    }

    dp[i] = res;
    return res;
}

int jump(vector<int> &nums) {
    int size = nums.size();
    vector<int> dp(size, -1);

    return jumpUtil(nums, 0, dp);
}

int minJumps(vector<int> &arr) {
    // { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 }
    // { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
    // {1, 2, 1, 1, 1, 0}
    // {0, 1, 2, 3, 4, 5}
    int n = arr.size();
    int count = 0;
    int far = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        far = max(far, i + arr[i]);
        if (i == end) {
            count++;
            end = far;
        }

        if (end >= n - 1) {
            break;
        }
    }

    if (end < n - 1) {
        return -1;
    }

    return count;
}

void merge(vector<int> &arr1, vector<int> &arr2) {
    int n = arr1.size();
    int m = arr2.size();

    int j = 0, k = 0;
    int count = 0;
    while (j < n && k < m) {
        if (arr1[j] <= arr2[k]) {
            j++;
            count++;
        } else {
            k++;
            count++;
        }

        if (count == n) {
            for (int i = j; i < n; i++) {
                int t = arr1[i];
                arr1[i] = arr2[k - 1];
                arr2[k - 1] = t;
                k--;
            }

            sort(arr1.begin(), arr1.end());
            sort(arr2.begin(), arr2.end());

            break;
        }
    }

    // code here
}

bool mergeCmp(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) {
        return a[0] < b[0];
    }
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> &tt) {

    int size = tt.size();
    vector<vector<int>> res;
    if (size == 0) {
        return res;
    }

    sort(tt.begin(), tt.end(), mergeCmp);

    int st = tt[0][0];
    int maxEnd = -1;
    for (int i = 0; i < size; i++) {
        if (st == -1) {
            st = tt[i][0];
        }

        maxEnd = max(maxEnd, tt[i][1]);

        if (maxEnd >= tt[i][0]) {
            continue;
        } else {
            vector<int> temp = {st, tt[i][1]};
            st = -1;
            res.push_back(temp);
        }
    }

    return res;
}

bool subArrayExists(vector<int> arr) {
    int n = arr.size();
    int size = arr.size();

    unordered_map<long int, long int> mp;

    long long int sum = 0;
    mp[0] = 1;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (mp[sum] != 0) {
            return true;
        }
        mp[sum] = 1;
    }

    return false;
}

void nextPermutation(vector<int> &nums) {

    int size = nums.size();
    vector<int> hash(101, 0);
    for (int i = size - 1; i >= 0; i--) {
        int mint = 1000;
        int idx = -1;
        for (int j = i + 1; j < size; j++) {
            if (nums[j] > nums[i]) {
                mint = min(mint, nums[j]);
                idx = j;
            }
        }

        if (idx != -1) {
            int temp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = temp;
            partial_sort(nums.begin() + i + 1, nums.end(), nums.end());
            return;
        }
    }

    sort(nums.begin(), nums.end());

    return;
}

int searchMatrixBinarySearch(vector<vector<int>> arr, int l, int r, int x) {
    int size = arr[0].size();

    cout << l << " " << r << endl;
    if (r >= l) {
        int mid = (r + l) / 2;
        int i = mid / size;
        int j = mid - size * i;

        cout << mid << "   " << i << " " << j << endl;
        if (arr[i][j] == x)
            return mid;

        if (arr[i][j] > x)
            return searchMatrixBinarySearch(arr, l, mid - 1, x);

        return searchMatrixBinarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int i = matrix.size();
    int j = matrix[0].size();
    int l = 0;
    int r = i * j - 1;

    int res = searchMatrixBinarySearch(matrix, l, r, target);
    cout << res;
    return true;
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m) {

    int idx = m - 1;
    int j = idx;
    int count = 0;
    int maxd = INT32_MIN;
    int resIdx = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && arr[i][j] == 1) {
            j--;
            count++;
        }

        if (count > maxd) {
            maxd = count;
            resIdx = i;
        }
    }

    return resIdx;
}

void printCommonElements(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();

    unordered_map<int, int> mp;
    for (int i = 0; i < m; i++) {
        unordered_map<int, int> hash;
        for (int j = 0; j < n; j++) {
            hash[arr[i][j]]++;
            if (hash[arr[i][j]] == 1) {
                mp[arr[i][j]]++;
            }

            if (hash[arr[i][j]] == 1 && i == m - 1 && mp[arr[i][j]] == m) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << "hr";
}

// int kthSmallest(vector<int> &arr, int k) {}

void maxHeapify(int i, vector<int> &arr) {
    int size = arr.size();
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if (left < size && arr[left] > arr[i]) {
        max = left;
    }
    if (right < size && arr[right] >= arr[max]) {
        max = right;
    }

    if (max != i) {
        swap(arr, max, i);
        maxHeapify(max, arr);
    }
}

void minHeapify(int i, vector<int> &arr, int k, int j) {
    int size = k;
    int left = 2 * (i - j) + 1 + j;
    int right = 2 * (i - j) + 2 + j;
    int max = i;
    if (left < size && arr[left] < arr[i]) {
        max = left;
    }
    if (right < size && arr[right] <= arr[max]) {
        max = right;
    }

    if (max != i) {
        swap(arr, max, i);
        minHeapify(max, arr, k, j);
    }
}

void createHeap(vector<int> &arr) {
    int size = arr.size();
    int k = 4;
    for (int j = 0; j <= size - k; j++) {
        int len = k / 2 - 1 + j;
        for (int i = len; i >= j; i--) {
            minHeapify(i, arr, j + k, j);
        }
    }

    printVect(arr);
}

int maxProfit3Util(vector<int> &arr, int i, int b, int state, int trans) {
    if (trans == 0 || i >= arr.size()) {
        return 0;
    }

    int res = INT32_MIN;
    if (state == 0) {
        res = max(maxProfit3Util(arr, i + 1, i, 1, trans--),
                  maxProfit3Util(arr, i + 1, -1, 0, trans));
    } else if (state == 1) {
        res = max(arr[i] - arr[b] + maxProfit3Util(arr, i + 1, -1, 0, trans),
                  maxProfit3Util(arr, i + 1, b, 1, trans));
    }

    return res;
}

int maxProfit4(vector<int> &arr) {
    int size = arr.size();
    int res = 0;
    vector<int> vt(size, 0);
    for (int i = 0; i < size; i++) {

        // cout << "i: " << i << "  " << max1 << " " << max2 << endl;
    }

    return res;
}

int maximumAmountUtil(vector<int> &arr, int start, int end, int sumArray[],
                      int **dp) {
    int sum = 0;
    if (start == end) {
        return arr[start];
    }
    // if (dp[start][end] != -1) {
    //     return dp[start][end];
    // }
    if (start == 0) {
        sum = sumArray[end];
    } else {
        sum = sumArray[end] - sumArray[start - 1];
    }
    int option1 = sum - maximumAmountUtil(arr, start + 1, end, sumArray, dp);
    int option2 = sum - maximumAmountUtil(arr, start, end - 1, sumArray, dp);
    // dp[start][end] = max(option1, option2);
    return dp[start][end];
}

long long int count(long long int n) {
    long long int table[n + 1];
    memset(table, 0, sizeof(table));
    table[0] = 1; // If 0 sum is required number of ways is 1.

    int count = 0;
    for (int i = 0; i <= n / 3; i++) {
        for (int j = 0; j <= n / 5; j++) {
            for (int k = 0; k <= n / 10; k++) {
                int sm = i * 3 + j * 5 + k * 10;
                if (sm == n) {
                    cout << i << " " << j << " " << k << endl;
                    count++;
                }
            }
        }
    }
    return count;
}

int maximumPathUtil(vector<vector<int>> &mt, int i, int j,
                    vector<vector<int>> &dp) {
    int n = mt.size();
    int m = mt[0].size();

    if (i >= n || j < 0 || j >= m) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int t1 = maximumPathUtil(mt, i + 1, j - 1, dp) + mt[i][j];
    int t2 = maximumPathUtil(mt, i + 1, j, dp) + mt[i][j];
    int t3 = maximumPathUtil(mt, i + 1, j + 1, dp) + mt[i][j];

    int maxt = max(max(t1, t2), t3);
    dp[i][j] = maxt;
    return maxt;
}

int maximumPath(int N, vector<vector<int>> m) {

    vector<vector<int>> dp(N, vector<int>(N, -1));
    int maxt = 0;
    for (int i = 0; i < N; i++) {
        int k = maximumPathUtil(m, 0, i, dp);
        maxt = max(maxt, k);
    }
    return maxt;
}

int maxSquare(int n, int m, vector<vector<int>> mt) {

    int ans = 0;
    for (int j = 0; j < m; j++) {
        if (mt[0][j]) {
            ans = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (mt[i][0]) {
            ans = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int maxt = 0;
            if (mt[i - 1][j - 1] && mt[i - 1][j] && mt[i][j - 1] && mt[i][j]) {
                maxt =
                    min(mt[i - 1][j - 1], min(mt[i - 1][j], mt[i][j - 1])) + 1;
                mt[i][j] = maxt;
                ans = max(maxt, ans);
            }
        }
    }
    return ans;
}

int maxSumPairWithDifferenceLessThanK(vector<int> arr, int N, int K) {
    if (N == 1) {
        return 0;
    }

    sort(arr.begin(), arr.end());
    printVect(arr);
    vector<int> hash(N + 1, 0);
    int i = N - 1, j = N - 2;
    while (i > 0 && j >= 0) {
        j = i - 1;
        while (arr[i] - arr[j] < K && j >= 0) {
            cout << arr[i] << " - " << arr[j] << endl;
            hash[i] = 1;
            hash[j] = 1;
            j--;
            break;
        }
        i = j;
    }

    int res = 0;
    for (int i = 0; i < N + 1; i++) {
        if (hash[i] == 1) {
            res += arr[i];
        }
    }

    return res;
}

vector<int> countBits(int n) {
    vector<int> res(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int temp = i;
        int count = 0;
        while (temp > 0) {
            count += temp % 2 == 1 ? 1 : 0;
            temp = temp / 2;

            if (res[temp] != 0) {
                count += res[temp];
                break;
            }
        }
        res[i] = count;
    }

    return res;
}

bool equalPartitionUtil(int vt[], int size, int sm, int i,
                        vector<vector<int>> &dp) {

    if (sm == 0) {
        dp[i][sm] = 1;
        return true;
    }
    if (i >= size || sm < 0) {
        return false;
    }

    if (dp[i][sm] != -1) {
        return dp[i][sm];
    }

    bool c1 = equalPartitionUtil(vt, size, sm - vt[i], i + 1, dp);
    bool c2 = equalPartitionUtil(vt, size, sm, i + 1, dp);
    dp[i][sm] = c1 || c2 ? 1 : 0;
    return c1 || c2;
}

int equalPartition(int N, int arr[]) {
    int sm = 0;
    for (int i = 0; i < N; i++) {
        sm += arr[i];
    }

    if (sm % 2 == 1) {
        return false;
    }

    sm /= 2;
    vector<vector<int>> dp(N + 1, vector<int>(sm + 1, -1));
    bool he = equalPartitionUtil(arr, N, sm, 0, dp);
    return he;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
    vector<int> dp(R, 0);

    int mx = 0;
    for (int i = 0; i < C; i++) {
        for (int j = i; j < C; j++) {
            for (int k = 0; k < R; k++) {
                dp[k] += M[k][j];
            }
            mx = max(mx, maxSumSubarray(dp));
        }

        for (int j = 0; j < R; j++) {
            dp[j] = 0;
        }
    }

    return mx;
}

long long getCount(int N) {

    int last[10];
    int next[10];
    long int dp[N + 1];

    dp[0] = 0;
    dp[1] = 10;

    for (int j = 0; j < 10; j++) {
        last[j] = 1;
        next[j] = 1;
    }

    for (int i = 0; i < N; i++) {
        dp[i] = 0;

        next[0] = last[0] + last[8];
        next[1] = last[1] + last[2] + last[4];
        next[2] = last[2] + last[1] + last[3] + last[5];
        next[3] = last[3] + last[2] + last[6];
        next[4] = last[4] + last[1] + last[5] + last[7];
        next[5] = last[5] + last[2] + last[4] + last[6] + last[8];
        next[6] = last[6] + last[3] + last[5] + last[9];
        next[7] = last[7] + last[4] + last[8];
        next[8] = last[8] + last[5] + last[7] + last[9] + last[0];
        next[9] = last[9] + last[8] + last[6];

        for (int j = 0; j < 10; j++) {
            dp[i] += last[j];
            last[j] = next[j];
        }
    }

    return dp[N - 1];
}

int partitionDisjoint(vector<int> &nums) {
    int size = nums.size();
    int mx = nums[0];
    int minIdx = 1;
    int mn = INT32_MAX;
    for (int i = 1; i < size; i++) {
        mx = max(mx, nums[i - 1]);
        if (i >= minIdx) {
            mn = INT32_MAX;
            for (int j = i; j < size; j++) {
                if (mn > nums[j]) {
                    mn = nums[j];
                    minIdx = j;
                }
            }
        }
        if (mx <= mn) {
            return i;
        }
    }

    return size;
}

vector<vector<int>> fourSum2(vector<int> &arr, int target) {

    int size = arr.size();
    vector<vector<int>> res;

    if (size < 3) {
        return res;
    }

    sort(arr.begin(), arr.end());

    set<vector<int>> st;
    int count = 0;

    for (int i = 0; i < size - 3; i++) {
        for (int j = i + 1; j < size - 2; j++) {
            int req = target - arr[i] - arr[j];
            int k = j + 1, l = size - 1;

            while (k < l) {
                int sm = arr[k] + arr[l];
                if (sm == req) {
                    vector<int> t;
                    t.push_back(arr[i]);
                    t.push_back(arr[j]);
                    t.push_back(arr[k]);
                    t.push_back(arr[l]);
                    // st.insert(t);
                    res.push_back(t);
                    k++;
                    l--;
                } else if (sm < req) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }

    // for (auto it : st) {
    //     res.push_back(it);
    // }

    print2dVect(res);
    return res;
}

bool compareRange(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int minTaps(vector<int> &arr) {
    vector<pair<int, int>> vt;
    int size = arr.size();

    for (int i = 0; i < arr.size(); i++) {
        pair<int, int> pr;
        pr.first = max(i - arr[i], 0);
        pr.second = min(i + arr[i], size - 1);
        vt.push_back(pr);
    }

    sort(vt.begin(), vt.end(), compareRange);
    cout << endl;
    for (auto it : vt) {
        cout << it.first << " " << it.second << endl;
    }

    for (auto it : vt) {
        cout << it.first << " " << it.second << endl;
    }
    cout << " ------------ " << endl;

    int low = vt[0].first, high = vt[0].second;
    int count = 1;
    for (int i = 0; i < vt.size(); i++) {
        pair<int, int> it = vt[i];

        if (it.second > high && it.first <= low) {
            high = it.second;
            low = min(it.first, low);
        }

        if (it.first > low && it.first <= high && it.second > high) {
            int j = i;
            while (vt[j].first < high) {
                j++;
            }
            count++;
            i = j - 1;
            low = vt[i].first;
            high = vt[i].second;
        }

        cout << i << " -> " << low << " " << high << endl;
    }

    return count;
}

bool winnerSquareGameUtil(int n) {
    bool check = isPerfectSquare(n);

    if (n <= 0) {
        cout << n << " gotcha" << endl;
        return false;
    }

    for (int i = 1; i * i < n; i++) {
        bool res = winnerSquareGameUtil(n - i * i);

        if (res) {
            return true;
        }
    }

    return false;
}

bool winnerSquareGame(int n) { return winnerSquareGameUtil(n); }

int findIntegers(int n) {

    int count = 0;
    for (int i = 0; i <= n; i++) {
        int temp = i;
        int check = 0;

        while (temp != 0) {
            if (temp % 2 == 1) {
                check++;
            } else {
                check = 0;
            }

            temp = temp / 2;

            if (check == 2) {
                cout << i << endl;
                count++;
                break;
            }
        }
    }

    return n - count + 1;
}

bool stoneGame(vector<int> &piles) {
    int size = piles.size();

    vector<vector<vector<int>>> dp(
        size, vector<vector<int>>(size, vector<int>(2, 0)));

    for (int i = 0; i < size; i++) {
        dp[i][i][0] = piles[i];
        dp[i][i][1] = 0;
        if (i > 0) {
            dp[i - 1][i][0] = max(piles[i], piles[i - 1]);
            dp[i - 1][i][1] = min(piles[i], piles[i - 1]);
        }
    }
    for (int k = 2; k < size; k++) {
        for (int i = 0; i < size - k; i++) {
            int j = i + k;
            int c1 = piles[i] + dp[i + 1][j][1];
            int c2 = piles[j] + dp[i][j - 1][1];
            if (c1 > c2) {
                dp[i][j][0] = c1;
                dp[i][j][1] = dp[i + 1][j][0];
            } else {
                dp[i][j][0] = c2;
                dp[i][j][1] = dp[i][j - 1][0];
            }
        }
    }

    // for (auto it : dp) {
    //     for (auto i : it) {
    //         cout << "(" << i[0] << ", " << i[1] << ")" << "  ";
    //     }
    //     cout << endl;
    // }

    return dp[0][size - 1][0] > dp[0][size][1];
}

vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    print2dVect(matrix);
    cout << " ------------ " << endl;
    vector<vector<int>> res(m, vector<int>(n, 0));
    vector<vector<int>> arr;
    vector<vector<int>> row(m, vector<int>(2, 0));
    vector<vector<int>> col(n, vector<int>(2, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr.push_back({matrix[i][j], i, j});
        }
    }

    sort(arr.begin(), arr.end(), [](auto &a, auto &b) { return a[0] < b[0]; });
    print2dVect(arr);
    cout << " ----- " << endl;
    cout << row.size() << " " << col.size() << endl;

    for (int i = 0; i < m * n; i++) {
        int el = arr[i][0];
        int r = arr[i][1];
        int c = arr[i][2];

        cout << "r: " << r << " c: " << c << "  val -> " << el << endl;
        cout << row[r][0] << " " << row[r][1] << " ------ " << col[c][0] << " "
             << col[c][1] << endl;
        if (max(row[r][0], col[c][0]) == 0) {
            row[r][0] = 1;
            row[r][1] = el;
            col[c][0] = 1;
            col[c][1] = el;
            res[r][c] = 1;
        } else if (row[r][0] > col[c][0]) {
            if (row[r][1] == el) {
                res[r][c] = row[r][0];
                col[c][0] = row[r][0];
                col[c][1] = el;
            } else {
                row[r][0]++;
                row[r][1] = el;
                col[c][0] = row[r][0];
                col[c][1] = el;
                res[r][c] = row[r][0];
            }
        } else {
            if (col[c][1] == el) {
                res[r][c] = col[c][0];
                row[r][0] = col[c][0];
                row[r][1] = col[c][1];
            } else {
                col[c][0]++;
                col[c][1] = el;
                row[r][0] = col[c][0];
                row[r][1] = el;
                res[r][c] = col[c][0];
            }
        }

        cout << "Row: ";
        for (auto it : row) {
            cout << "(" << it[0] << "," << it[1] << ") ";
        }
        cout << endl << "Col: ";
        for (auto it : col) {
            cout << "(" << it[0] << "," << it[1] << ") ";
        }
        cout << endl;
        print2dVect(res);
    }

    print2dVect(res);

    return res;
}

void findSumLength(vector<vector<int>> arr) {

    map<int, int> freq;
    for (auto i : arr)
        freq[i[0]] = i[1];

    map<int, int> freq_2;

    for (auto i : freq) {
        if (freq[i.first] >= 2)
            freq_2[i.first] = freq[i.first];
    }

    vector<int> arr1;
    for (auto i : freq_2)
        arr1.push_back((i.first) * (freq_2[(i.first)] / 2) * 2);
    sort(arr1.begin(), arr1.end());

    reverse(arr1.begin(), arr1.end());
    int summ = 0;
    if (arr1.size() % 2 == 0) {
        for (int i : arr1)
            summ += i;
    } else {
        for (int i = 0; i < arr1.size() - 1; i++) {
            summ += arr1[i];
        }
    }
    cout << summ;
}

int solve(long int n, long int g, long int b) {
    long int cycles = n / (g + b);
    long int remG = n % (g + b);

    long int totalG = cycles * (g + b) - cycles * b + remG;

    if (n <= totalG) {
        return n;
    } else if (n > totalG && totalG >= n / 2) {
        return totalG;
    }
    return n;
}

int main() {
    int size = 15;
    // int arr[size] = {7, 6, 13, 8, 6, 3, 1, 2, 9, 7, 8, 5, 3, 3, 1};
    int size2 = 2;
    int arr2[size2] = {3, 4};

    vector<vector<char>> mt = {{'1', '0'}, {'1', '0'}};

    vector<vector<int>> res;

    vector<vector<int>> res2 = {{-19}};

    vector<int> sd = {1, 4,  63, 6, 5,  12, 47,  56, 71, 5,  63, 15, 57, 12,
                      1, 63, 5,  0, 67, 5,  178, 8,  6,  94, 5,  47, 69, 8};

    vector<vector<int>> ct = {{5, 6}, {3, 2}, {4, 3}, {6, 1}};

    vector<vector<int>> f = {{1, 1}};
    vector<int> dt = {1, 1, 2,  2,  2,  3,  4,  5,  5,  6,  7, 7,
                      1, 0, 12, 14, 15, 16, 17, 17, 18, 19, 19};

    vector<int> vt = {5, 3, 4, 5};
    vector<int> d = {5, 9, 11, 11, 14, 17};
    vector<int> t = {1, 2, 3, 2, 2, 1};
    vector<int> rs;

    // printVect(vt);

    cout << solve(5, 4, 4);
    // matrixRankTransform(ct);
    // stoneGame(vt);
    // cout << findPairs(vt, 0);
    // cout << findCount(15) << endl;
    // cout << winnerSquareGame(1) << endl;
    // cout << minTaps(vt);
    // fourSum2(vt, 8);
    // cout << partitionDisjoint(vt) << endl;
    // cout << getCount(5) << endl;
    // cout << maximumSumRectangle(4, 6, ct);
    // cout << equalPartition(7, arr);
    // maximumAmount(vt);
    // countBits(10);
    // cout << maximumPath(6, ct);
    // cout << count(8) << endl;
    // maxProfit4(vt);
    // createHeap(vt);
    // printCommonElements(ct);
    // searchMatrix(f, 5);
    // cout << subArrayExists(vt) << endl;
    // nextPermutation(vt);
    // cout << minJumps(vt) << endl;
    // cout << jump(vt);
    // cout << canJump(vt);
    // generateMatrix(10);
    // spiralOrder(ct);
    // printVect(vt);
    // printVect(dt);
    // cout << removeOuterParentheses(s) << endl;
    // advantageCount(vt, dt);
    // cout << kthGrammar(5, 5);
    // mostCompetitive(vt, 8);
    // cout << subarraySum(vt, 0) << endl;
    // cout << spyDetected(vt) << endl;
    // cout << minOperations(vt, 4);
    // longestIncreasingPath(f);
    // cout << reverseBits(4, 0);
    // cout << maxProfit(vt) << endl;
    // cout << maxProfit3(vt) << endl;
    // cout << maxProfitFee(vt, 3) << endl;
    // cout << singleNumber2(vt);
    // subsetsBitMasking(vt);
    // subsets(vt);
    // rob(vt);
    // cout << maximumScore(vt, 3) << endl;
    // firstBadVersion();
    // cout << numFactoredBinaryTrees(vt) << endl;
    // cout << coinChange(vt, 31) << endl;
    // rotate(ct);
    // cout << intToRoman(3949) << endl;
    // findDisappearedNumbers(vt);
    // thirdMax(vt);
    // sortArrayByParity(vt);
    // duplicateZeros(vt);
    // cout << findLHS(vt) << endl;
    // cout << validMountainArray(vt) << endl;
    // merge(vt, 0, sd, 4);
    // cout << " h s " << isPalindrome(1231) << "hey";
    // sd = sortedSquares(vt);
    // cout << findMaxConsecutiveOnes(vt) << endl;
    // kWeakestRows(ct, 7);
    // cout << shortestPathBinaryMatrix(ct);
    // cout <<numberOfSteps(121) << endl;
    // findErrorNums(vt);

    // ambiguousCoordinates(s);
    // cout << reverse(-1230) << endl;
    // moveZeroes(vt);
    // rs = plusOne(vt);
    // intersect(vt, sd);
    // singleNumber(vt);
    // rotate(vt, 1);
    // cout << containsDuplicate(vt) << endl;
    // removeDuplicates(vt);
    // removeElement(vt, 2);

    // cout << maxDistance(vt, 4);
    // cout << canReorderDoubled(vt) << endl;
}
