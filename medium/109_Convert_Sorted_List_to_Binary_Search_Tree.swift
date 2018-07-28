//
//  109_Convert_Sorted_List_to_Binary_Search_Tree.swift
//  LeetCode
//
//  Created by 王哲 on 2018/7/28.
//  Copyright © 2018年 WangZhe. All rights reserved.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

class Solution {
    func sortedListToBST(_ head: ListNode?) -> TreeNode? {
        if head == nil {
            return nil
        }
        if head?.next == nil {
            return TreeNode(head!.val)
        }
        var slow = head, fast = head, pre = head
        while fast != nil && fast?.next != nil {
            pre = slow
            slow = slow?.next
            fast = fast?.next?.next
        }
        pre?.next = nil
        let root = TreeNode(slow!.val)
        root.left = sortedListToBST(head)
        root.right = sortedListToBST(slow?.next)
        return root
    }
}
