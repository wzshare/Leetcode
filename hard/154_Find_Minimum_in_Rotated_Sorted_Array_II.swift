//
//  154_Find_Minimum_in_Rotated_Sorted_Array_II.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/5.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.154
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 *
 * Example 2:
 *
 * Input: [2,2,2,0,1]
 * Output: 0
 */

class Solution {
    func findMin(_ nums: [Int]) -> Int {
        var low = 0, high = nums.count - 1
        while nums[low] >= nums[high] {
            if high - low == 1 {
                return nums[high]
            }
            let mid = (low + high) / 2
            if nums[mid] == nums[low] && nums[mid] == nums[high] {
                return helper(nums, low, high)
            } else if nums[low] <= nums[mid] {
                low = mid
            } else {
                high = mid
            }
        }
        return nums[low]
    }
    
    func helper(_ nums: [Int], _ from: Int, _ to: Int) -> Int {
        var res = nums[from]
        for i in from...to {
            if res > nums[i] {
                res = nums[i]
            }
        }
        return res
    }
}
