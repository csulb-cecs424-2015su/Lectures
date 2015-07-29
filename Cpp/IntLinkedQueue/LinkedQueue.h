#ifndef __LINKEDQUEUE_H
#define __LINKEDQUEUE_H

// Demonstrate using dynamic memory management to create a queue of integers.
class LinkedQueue {
private:
   // A class to store a piece of data, and a link to the next data in the queue
   class Node {
   private:
      int mData;
      Node *mNext;
      friend class LinkedQueue;

   public:
      // Initialize a Node with the given data, and a pointer for the next Node.
      Node(int data, Node *next) : mData(data), mNext(next) {
      }
   };


   // A linked list is just a pointer to a head node, a pointer to a tail node,
   // and a count of how many nodes there are.
   Node *mHead;
   Node *mTail;
   int mSize;

public:
   LinkedQueue();
   LinkedQueue(const LinkedQueue &other);
   ~LinkedQueue();

   // Assignment=
   LinkedQueue& operator=(const LinkedQueue &rhs);

   // Add an element to the end of the queue.
   void Add(int data);
   // Remove and return the front element from the queue.
   int Remove();
   
   inline int Size() const {
      return mSize;
   }
};

#endif