class _Node:
    def __init__(self, val):
        self._value = val
        self._next = None

class LinkedQueue:
    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0

    def append(self, value):
        if self._size == 0:
            self._tail = self._head = _Node(value)
        else:
            temp = _Node(value)
            self._tail._next = temp
            self._tail = temp
        
        self._size += 1

    def remove(self):
        if self._size == 0:
            raise Exception("queue is empty")
        temp = self._head
        self._head = self._head._next
        self._size -= 1
        return temp._value

    def first(self):
        if self._size == 0:
            raise Exception("queue is empty")

        return self._head._value

    def size(self):
        return self._size
            
q = LinkedQueue()
q.append(10)
q.append(20)
q.append(30)
print q.remove()
print q.remove()
print q.size()
