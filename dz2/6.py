class Node:
    def __init__(self, value = None, next = None):
        self.value = value
        self.next = next

class LinkedList:
    def __init__(self):
        self.first = None
        self.last = None
        self.length = 0

    def __str__(self):
        if self.first != None:
            current = self.first
            out = 'LinkedList [\n' +str(current.value) +'\n'
            while current.next != None:
                current = current.next
                out += str(current.value) + '\n'
            return out + ']'
        return 'LinkedList []'

    def clear(self):
        self.__init__()

    def add(self, x):
        self.length+=1
        if self.first == None:
            #self.first и self.last будут указывать на одну область памяти
            self.last = self.first = Node(x, None)
        else:
            #здесь, уже на разные, т.к. произошло присваивание
            self.last.next = self.last = Node(x, None)

    def RemoveSortedDuplicates(self):
        if (self.first == None):
            return
        curr = self.first
        while curr != None:
            _del = 0 
            if curr.next != None:
                if curr.value == curr.next.value:
                    curr.next = curr.next.next
                    _del = 1
            if _del == 0:
                curr = curr.next


L = LinkedList()
L.add(1)
L.add(2)
L.add(3)
L.add(3)
L.add(4)
L.add(4)
L.add(4)
L.add(5)
print(L)
L.RemoveSortedDuplicates()
print(L)