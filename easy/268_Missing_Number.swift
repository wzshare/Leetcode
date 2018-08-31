//
//  268_Missing_Number.swift
//  LeetCode
//
//  Created by wangzhe on 2018/8/31.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 */

class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        let expectSum = nums.count * (nums.count + 1) / 2;
        let sum = nums.reduce(0, +);
        return expectSum - sum
    }
}
