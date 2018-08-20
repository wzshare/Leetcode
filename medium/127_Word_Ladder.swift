//
//  127_Word_Ladder.swift
//  LeetCode
//
//  Created by wangzhe on 2018/8/20.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation


/*
 * NO.127
 * Given two words (beginWord and endWord), and a dictionary's word list,
 * find the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 1. Only one letter can be changed at a time.
 * 2. Each transformed word must exist in the word list.Note that beginWord is not
 *    a transformed word.
 */

class Solution {
    func ladderLength(_ beginWord: String, _ endWord: String, _ wordList: [String]) -> Int {
        guard wordList.contains(endWord) else {
            return 0
        }
        var result = 1
        var hashset = Set(wordList)
        var beginSet = Set([beginWord])
        var endSet = Set([endWord])
        hashset.remove(endWord)
        while !beginSet.isEmpty && !endSet.isEmpty {
            if beginSet.count > endSet.count {
                (beginSet, endSet) = (endSet, beginSet)
            }
            var tempReached = Set<String>()
            for reach in beginSet {
                for end in endSet {
                    if isTransformed([Character](reach), [Character](end)) {
                        return result + 1
                    }
                }
                var tempHashset = hashset
                for word in hashset {
                    if isTransformed([Character](reach), [Character](word)) {
                        tempReached.insert(word)
                        tempHashset.remove(word)
                    }
                }
                hashset = tempHashset
            }
            result += 1
            beginSet = tempReached
        }
        return 0
    }
    func isTransformed(_ wordA: [Character], _ wordB: [Character]) -> Bool {
        var diff = 0
        for i in 0..<wordA.count {
            if wordA[i] != wordB[i] {
                diff += 1
            }
            if (diff > 1) {
                return false
            }
        }
        return diff == 1
    }
}
