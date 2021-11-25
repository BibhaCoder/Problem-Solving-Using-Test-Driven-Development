/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */
 
 /**
  * Solution 1: generate all 4 memebrs subarray and check if their sum is equal to given sum
  * for (i = 0; i < num - 3; i++)
  *    for (j = i + 1; j < num - 2; j++)
  *         for (k = j + 2; k < num - 1; k++)
  *                for (l =  k + 3; l < num; l++)
  *                     check if a[i] + a[j] + a[k] + a[l] == given_sum
  * Runtime : O(N ^ 4)
  *
  *
  * Solution 2: Optimal solution:
  * Generate all 2 element pair sub aux arrays.
  * Sort this 2 elements aux arrays 
  * Use 2_sum 2 pointers left and right method to find all 4 pairs whose sum == given_sum
  * Runtime: O(N ^ 2 logN)
  * This is best possible solution.
  */
