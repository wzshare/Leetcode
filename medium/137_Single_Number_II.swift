//
//  137_Single_Number_II.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/16.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * Given a non-empty array of integers, every element appears three times except for one,
 * which appears exactly once. Find that single one.
 */

class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        var ans = 0
        for i in 0..<64 {
            var sum = 0
            let tmp = (1 << i)
            for j in 0..<nums.count {
                if tmp & nums[j] != 0 {
                    sum += 1
                }
            }
            if sum % 3 == 1 {
                ans = ans ^ tmp
            }
        }
        return ans
    }
}
