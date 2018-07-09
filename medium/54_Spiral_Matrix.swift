//
//  54_Spiral_Matrix.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/9.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.54
 * Given a matrix of m x n elements (m rows, n columns),
 * return all elements of the matrix in spiral order.
 */

class Solution {
    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        var result = [Int]()
        
        guard matrix.count != 0 else {
            return result
        }
        
        var start = 0
        let cols = matrix[0].count, rows = matrix.count
        while cols > start * 2 && rows > start * 2 {
            let endx = cols - 1 - start
            let endy = rows - 1 - start
            
            for i in start...endx {
                result.append(matrix[start][i])
            }
            if start < endy {
                for i in (start + 1)...endy {
                    result.append(matrix[i][endx])
                }
            }
            if start < endx && start < endy {
                for i in stride(from: endx - 1, through: start, by: -1) {
                    result.append(matrix[endy][i])
                }
            }
            if start < endx && start < endy - 1 {
                for i in stride(from: endy - 1, through: start + 1, by: -1) {
                    result.append(matrix[i][start])
                }
            }
            start += 1
        }
        return result
    }
}
