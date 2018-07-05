//
//  191_Number_of_1_Bits.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/5.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.191
 * Write a function that takes an unsigned integer and returns the
 * number of '1' bits it has.
 */

class Solution {
    func numberOfOne(_ n: Int) -> Int {
        var flag = 1, res = 0
        while flag > 0 {
            if (flag & n) > 0 {
                res += 1
            }
            flag <<= 1
        }
        return res
    }
    
    func numberOfOne1(_ n: Int) -> Int {
        var flag = n, res = 0
        while flag > 0 {
            res += 1
            flag = flag & (flag - 1)
        }
        return res
    }
}
