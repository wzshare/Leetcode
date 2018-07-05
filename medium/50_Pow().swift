//
//  50_Pow(x, n).swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/5.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.50
 * Implement pow(x, n)
 */

class Solution {
    func myPow(_ x: Double, _ n: Int) -> Double {
        if n == 0 {
            return 1
        }
        if n == 1 {
            return x
        }
        let flag = abs(n)
        var res = myPow(x, flag >> 1)
        res *= res
        if flag & 1 == 1 {
            res *= x
        }
        return n > 0 ? res : 1 / res
    }
}
