#include <bits/stdc++.h>

using namespace std;
// class Queue
// {
//   int *arr;
//   int start, end, currSize, maxSize;

// public:
//   Queue()
//   {
//     arr = new int[16];
//     start = -1;
//     end = -1;
//     currSize = 0;
//   }

//   Queue(int maxSize)
//   {
//     (*this).maxSize = maxSize;
//     arr = new int[maxSize];
//     start = -1;
//     end = -1;
//     currSize = 0;
//   }
//   void push(int newElement)
//   {
//     if (currSize == maxSize)
//     {
//       cout << "Queue is full\nExiting..." << endl;
//       exit(1);
//     }
//     if (end == -1)
//     {
//       start = 0;
//       end = 0;
//     }
//     else
//     {
//       end = (end + 1) % maxSize;
//     }
//     arr[end] = newElement;
//     cout << "The element pushed is " << newElement << endl;
//     currSize++;
//   }
//   int pop()
//   {
//     if (start == -1)
//     {
//       cout << "Queue Empty\nExiting..." << endl;
//     }
//     int popped = arr[start];
//     if (currSize == 1)
//     {
//       start = -1;
//       end = -1;
//     }
//     else
//       start = (start + 1) % maxSize;
//     currSize--;
//     return popped;
//   }
//   int top()
//   {
//     if (start == -1)
//     {
//       cout << "Queue is Empty" << endl;
//       exit(1);
//     }
//     return arr[start];
//   }
//   int size()
//   {
//     return currSize;
//   }
// };
// or code with less space complexity
class myQueue {
    int start;
    int end;
    int currSize;
    int size;
    int *arr;

public:
    myQueue(int n) {
        size = n;              // ✅ FIXED
        arr = new int[n];
        start = -1;
        end = -1;
        currSize = 0;
    }

    bool isEmpty() {
        return currSize == 0;   // ✅ cleaner
    }

    bool isFull() {
        return currSize == size;
    }

    // push is enqueue and pop is dequeue
    void push(int x) {
        if (isFull()) return;

        if (currSize == 0) {
            start = end = 0;
        } else {
            end = (end + 1) % size;
        }

        arr[end] = x;
        currSize++;
    }

    void pop() {
        if (isEmpty()) return;

        if (currSize == 1) {
            start = end = -1;
        } else {
            start = (start + 1) % size;
        }

        currSize--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[start];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[end];
    }
};
int main()
{
  myQueue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.getFront() << endl;
  cout << "The bottom of the queue before deleting any element " << q.getRear() << endl;
  q.pop();
  cout << "The peek of the queue after deleting an element " << q.getFront() << endl;
  cout << "The size of the queue after deleting an element " << q.getRear() << endl;

  return 0;
}