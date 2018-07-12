//
//  233_Number_of_Digit_One.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/12.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

class Solution {
    func countDigitOne(_ n: Int) -> Int {
        guard n > 0 else {
            return 0
        }
        let str = String(n), first = firstDigit(n), length = str.count
        if length == 1 && first == 0 {
            return 0
        }
        if length == 1 && first > 0{
            return 1
        }
        var numFisrstDigit = 0
        if first == 1 {
            numFisrstDigit = n - powerBase10(length - 1) + 1
        } else {
            numFisrstDigit = powerBase10(length - 1)
        }
        
        let numOtherDigits = first * (length - 1) * powerBase10(length - 2)
        let numRecursive = countDigitOne(n - first * powerBase10(length - 1))
        return numFisrstDigit + numOtherDigits + numRecursive
    }
    
    private func powerBase10(_ n: Int) -> Int {
        var result = 1
        for _ in 0..<n {
            result *= 10
        }
        return result
    }
    
    private func firstDigit(_ n: Int) -> Int {
        var result = n
        while result >= 10 {
            result /= 10
        }
        return result
    }
}
