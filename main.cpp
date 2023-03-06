#include<bits/stdc++.h>
using namespace std;

/**
 * Function to solve the knapsack problem using dynamic programming
 * 
 * @param W The maximum weight that can be carried in the knapsack
 * @param wt[] The weights of the items
 * @param val[] The values of the items
 * @param n The number of items
 * 
 * @return The maximum value that can be achieved within the weight constraint
 */
int knapsack(int W, int wt[], int val[], int n) {
   int i, w;
   
   // Create a 2D array to store the maximum value for all possible combinations of weights and items
   int K[n+1][W+1];
   
   // Initialize the array with 0 for the base case when there are no items or the weight is 0
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i==0 || w==0)
            K[i][w] = 0;
         else if (wt[i-1] <= w)
            // If the current item can be included in the knapsack, compute the maximum value that can be achieved by either including or excluding the item
            K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
         else
            // If the current item cannot be included in the knapsack, use the maximum value achieved without the current item
            K[i][w] = K[i-1][w];
      }
   }
   
   // Return the maximum value that can be achieved within the weight constraint
   return K[n][W];
}

int main() {
   // Initialize the values of the items and the weight constraint
   int val[] = {60, 100, 120}; // Values of the items
   int wt[] = {10, 20, 30}; // Weights of the items
   int W = 50; // Maximum weight that can be carried in the knapsack
   int n = sizeof(val)/sizeof(val[0]); // Number of items
   
   // Compute the maximum value that can be achieved within the weight constraint using dynamic programming
   int max_value = knapsack(W, wt, val, n);
   
   // Output the maximum value that can be achieved within the weight constraint
   cout<<"The maximum value that can be achieved within the weight constraint is "<<max_value<<endl;
   
   // Exit the program with status code 0
   return 0;
}
