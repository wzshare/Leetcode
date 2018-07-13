//
//  264_Ugly_Number_II.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/13.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.264
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 */

class Solution {
    func nthUglyNumber(_ n: Int) -> Int {
        guard n > 0 else {
            return 0
        }
        var nums = Array(repeating: 0, count: n)
        nums[0] = 1
        var next = 1, m2 = 0, m3 = 0, m5 = 0
        while next < n {
            let ugly = min(nums[m2] * 2, nums[m3] * 3, nums[m5] * 5)
            nums[next] = ugly
            while nums[m2] * 2 <= ugly {
                m2 += 1
            }
            while nums[m3] * 3 <= ugly {
                m3 += 1
            }
            while nums[m5] * 5 <= ugly {
                m5 += 1
            }
            next += 1
        }
        return nums.last!
    }
}
