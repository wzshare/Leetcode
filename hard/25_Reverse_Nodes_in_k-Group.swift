//
//  25_Reverse_Nodes_in_k-Group.swift
//  LeetCode
//
//  Created by wangzhe on 2018/10/26.
//  Copyright © 2018 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.25
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * k is a positive integer and is less than or equal to the length of the linked list. If the number
 * of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * Example:
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be changed.
 */

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func reverseKGroup(_ head: ListNode?, _ k: Int) -> ListNode? {
        if head?.next == nil {
            return head
        }
        let dummy: ListNode? = ListNode(0)
        dummy!.next = head
        var pre = dummy, start = dummy, end = dummy
        while end != nil {
            end = pre
            for _ in 0..<k {
                end = end?.next
                if end == nil {
                    return dummy?.next
                }
            }
            for _ in 1..<k {
                start = pre!.next
                pre!.next = start!.next
                start!.next = end!.next
                end!.next = start
            }
            for _ in 0..<k {
                pre = pre!.next
            }
        }
        return dummy!.next
    }
}
