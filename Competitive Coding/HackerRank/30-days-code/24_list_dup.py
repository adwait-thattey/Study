class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def insert(self, head, data):
            p = Node(data)
            if head == None:
                head = p
            elif head.next == None:
                head.next = p
            else:
                start = head
                while(start.next != None):
                    start = start.next
                start.next = p
            return head

    def display(self, head):
        current = head
        while current:
            print(current.data, end=' ')
            current = current.next


    def removeDuplicates(self, head):
        if not head: return None
            
        new_head = head
        while new_head and new_head.next:
            head_val = new_head.data
            cur_p = new_head
            # print("hi")
            while cur_p and cur_p.next:
                if cur_p.next.data == head_val:
                    tbd = cur_p.next
                    cur_p.next = cur_p.next.next
                    del(tbd)

                else:
                    cur_p = cur_p.next

            new_head = new_head.next
        
        return head
            #Write your code here


mylist = Solution()
T = int(input())
head = None
for i in range(T):
    data = int(input())
    head = mylist.insert(head, data)
head = mylist.removeDuplicates(head)
mylist.display(head)
