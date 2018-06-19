//
//  leetcode.swift
//  testSwift
//
//  Created by wangzhe on 2018/6/19.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * No.412
 * Write a program that outputs the string representation of numbers from 1 to n.
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 */

class Solution {
    func fizzBuzz(_ n: Int) -> [String] {
        var res: [String] = []
        for i in 1...n {
            if (i % 3 == 0 && i % 5 == 0) {
                res.append("FizzBuzz")
            }
            else if (i % 3 == 0) {
                res.append("Fizz")
            }
            else if (i % 5 == 0) {
                res.append("Buzz")
            }
            else {
                res.append(String(i))
            }
        }
        return res
    }
}
