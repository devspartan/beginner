#include<bits/stdc++.h>

using namespace std;

int max(int i, int j) {
    return (i > j) ? i : j;
}

int knapsack(int wt[], int pr[], int i, int W, int size, int **dp) {
    if(i == size) {
        return 0;
    }

    if(dp[i][W] != 0) {
        cout << "from dp " << endl;
        return dp[i][W];
    }

    if(wt[i] > W) {
        knapsack(wt, pr, i+1, W, size, dp);
    }
    else {
        int temp =  max(pr[i] + knapsack(wt, pr, i+1, W-wt[i], size, dp), knapsack(wt, pr, i+1, W, size, dp));
        dp[i][W] = temp;
        cout << dp[i][W] << endl;
        return temp;
    
    }
    
}

int main() {
    int size = 5;
    int W = 15;
    int **dp;
    dp = new int *[size];
    for(int i = 0; i < size; i++) {
        dp[i] = new int[W];
    }


    int wt[size] = {5, 8, 6, 9, 4};
    int pr[size] = {7, 5, 8, 4, 3};


    cout << knapsack(wt, pr, 0, W, size, dp) << endl; 


    for(int i = 0; i < size; i++) {
        for(int j = 0; j < W; j++) {
            dp[i][j] = 0;
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}