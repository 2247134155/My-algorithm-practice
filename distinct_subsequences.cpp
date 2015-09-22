/*
 * Source.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: Xiangchen
 */
/*
 Given a string S and a string T, count the number of distinct subsequences of T in S.
 
 A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 
 Here is an example:
 S = "rabbbit", T = "rabbit"
 
 Return 3.
 
 */



#include <iostream>
#include <cstdint>

class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size()==0||t.size()==0){
            return 0;
        }
        int M = s.size();
        int N = t.size();
        int a[M+1][N+1];
        a[0][0] = 1;
        for(int i = 1;i<M+1;i++){
            a[i][0] = 1;
        }
        for(int i = 1;i<N+1;i++){
            a[0][i] = 0;
        }
        for(int i = 1;i<M+1;i++){
            for(int j =1;j<N+1;j++){
                if(s[i-1]==t[j-1]){
                    a[i][j] = a[i-1][j-1]+a[i-1][j];
                }
                else a[i][j] = a[i-1][j];
            }
        }
        return a[M][N];
    }
};
