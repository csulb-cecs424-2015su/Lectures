#include "LinkedQueue.h"
#include <iostream>
#include <stdexcept>


using std::cout;
using std::endl;

// Default construct a LinkedQueue with no elements.
LinkedQueue::LinkedQueue()
   : mHead(nullptr), mTail(nullptr), mSize(0) { // "nullptr" instead of "null"
}


LinkedQueue::LinkedQueue(const LinkedQueue &other)
   : mHead(other.mHead), mTail(other.mTail), mSize(other.mSize) {
   *this = other;
}

void LinkedQueue::Add(int data) {
   if (mSize == 0) {
      Node *newNode = new Node(data, nullptr);
      mHead = mTail = newNode;
   }
   else {
      Node *newNode = new Node(data, nullptr);
      mTail->mNext = newNode;
      mTail = newNode;
   }
   mSize++;
}

int LinkedQueue::Remove() {
   if (mSize == 0) {
      throw std::out_of_range("Queue was empty");
   }

   int data = mHead->mData;
   Node *temp = mHead;
   mHead = mHead->mNext;
   delete temp;

   if (mSize == 1) {
      mTail = nullptr;
   }

   mSize--;
   return data;
}


LinkedQueue::~LinkedQueue() {
   Node *n = mHead;

   while (n != nullptr) {
      Node *temp = n;
      n = n->mNext;
      delete temp;
   }
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue &rhs) {
   if (this == &rhs) {
      return *this;
   }

   if (mHead != nullptr) {
      Node *n = mHead;
      while (n != nullptr) {
         Node *temp = n;
         n = n->mNext;
         delete temp;
      }
   }
   mSize = rhs.mSize;
   mHead = nullptr;
   Node *o = rhs.mHead;
   Node *mine = nullptr;

   for (int i = 0; i < rhs.mSize; i++) {
      Node *n = new Node(o->mData, nullptr);

      if (i == 0) { // this is the first Node I created as a copy
         mHead = n;
      }
      else {
         mine->mNext = n;
      }
      o = o->mNext;
      mine = n;
   }
   mTail = mine;

   return *this;
}
