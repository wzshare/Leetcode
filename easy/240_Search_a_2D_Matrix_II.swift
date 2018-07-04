//
//  240_Search_a_2D_Matrix_II.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/4.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

 /*
 NO.240
 Write an efficient algorithm that searches for a value in an m x n matrix.
 This matrix has the following properties:
 
 Integers in each row are sorted in ascending from left to right.
 Integers in each column are sorted in ascending from top to bottom.
 
 Example:
 Consider the following matrix:
 [
    [1,   4,  7, 11, 15],
    [2,   5,  8, 12, 19],
    [3,   6,  9, 16, 22],
    [10, 13, 14, 17, 24],
    [18, 21, 23, 26, 30]
 ]
 Given target = 5, return true.
 Given target = 20, return false.
 */

class Solution {
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        if matrix.count == 0 || matrix[0].count == 0 {
            return false
        }
        var row = 0, col = matrix[0].count - 1
        while row < matrix.count && col >= 0 {
            if matrix[row][col] == target {
                return true
            } else if matrix[row][col] > target {
                col -= 1
            } else if matrix[row][col] < target {
                row += 1
            }
        }
        return false
    }
}
