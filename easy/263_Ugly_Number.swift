//
//  263_Ugly_Number.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/4.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.263
 * Write a program to check whether a given number is an ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 */

class Solution {
    func isUgly(_ num: Int) -> Bool {
        var res = num
        for p in [2, 3, 5] {
            while res > 0 && res % p == 0 {
                res /= p;
            }
        }
        return res == 1;
    }
}
