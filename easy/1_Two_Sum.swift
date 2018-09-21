//
//  1_Two_Sum.swift
//  LeetCode
//
//  Created by wangzhe on 2018/9/21.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/**
 * NO.1
 * Given an array of integers, return indices of the two numbers such that they add
 * up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not
 * use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dic = [Int: Int]()
        for (i, num) in nums.enumerated() {
            if let index = dic[target - num] {
                return [index, i]
            } else {
                dic[num] = i
            }
        }
        return [0, 0]
    }
}
