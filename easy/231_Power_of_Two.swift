//
//  231_Power_of_Two.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/5.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.231
 * Given an integer, write a function to determine if it is a power of two.
 */

class Solution {
    func isPowerOfTwo(_ n: Int) -> Bool {
        if n != 0 && n & (n - 1) == 0 {
            return true
        }
        return false
    }
}
