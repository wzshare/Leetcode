//
//  169_Majority_Element.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/12.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.169
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 */

class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        guard nums.count > 0 else {
            return -1
        }
        var result = nums[0], times = 1
        for i in 1..<nums.count {
            if times == 0 {
                result = nums[i]
                times = 1
            } else if result == nums[i] {
                times += 1
            } else {
                times -= 1
            }
        }
        return result
    }
}
