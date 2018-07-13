//
//  387_First_Unique_Character_in_a_String.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/13.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.387
 * Given a string, find the first non-repeating character in it and return it's index.
 * If it doesn't exist, return -1.
 */

class Solution {
    func firstUniqChar(_ s: String) -> Int {
        var dict = [Character: Int]()
        for char in s {
            if let _ = dict[char] {
                dict[char]? += 1
            } else {
                dict[char] = 1
            }
        }
        for (i, char) in Array(s).enumerated() {
            if dict[char] == 1 {
                return i
            }
        }
        return -1
    }
}
