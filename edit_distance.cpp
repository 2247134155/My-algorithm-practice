/*
 * Source.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: Xiangchen
 */

/*
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 
 You have the following 3 operations permitted on a word:
 
 a) Insert a character
 b) Delete a character
 c) Replace a character
 */


#include <iostream>
#include <cstdint>

class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();
        int a[M+1][N+1];
        a[0][0] = 0;
        for (int i = 1;i<M+1;i++){
            a[i][0]=i;
        }
        for(int i = 1;i<N+1;i++){
            a[0][i]=i;
        }
        for(int i = 1;i<M+1;i++){
            for (int j = 1;j <N+1;j++){
                if(word1[i-1]==word2[j-1]){
                    a[i][j] = mins(a[i-1][j]+1,a[i][j-1]+1,a[i-1][j-1]);
                }
                else a[i][j] = mins(a[i-1][j]+1,a[i][j-1]+1,a[i-1][j-1]+1);
            }
        }
        return a[M][N];
    }
    int mins(int a, int b, int c){
        int minun = a<b?a:b;
        return minun<c?minun:c;
    }
    
};
