//
//  49_Group_Anagrams.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/16.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *  ["ate","eat","tea"],
 *  ["nat","tan"],
 *  ["bat"]
 * ]
 * Note:
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */

class Solution {
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        var map = [String: [String]]()
        
        for str in strs {
            let sortedStr = String(str.sorted())
            
            var anagrams = [String]()
            if let list = map[sortedStr] {
                anagrams = list
            }
            anagrams.append(str)
            map[sortedStr] = anagrams
        }
        return map.values.map({ value in value.sorted() })
    }
}
