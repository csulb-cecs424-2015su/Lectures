#include <iostream>

using namespace std;


int binary_search(int *data, int toFind, int start, int end) {
   //Get the midpoint.
   int mid = start + (end - start) / 2;  

   if (start > end)
      return -1;
   else if (data[mid] == toFind)        //Found?
      return mid;
   else if (data[mid] > toFind)         //Data is greater than toFind, search lower half
      return binary_search(data, toFind, start, mid - 1);
   else                                 //Data is less than toFind, search upper half
      return binary_search(data, toFind, mid + 1, end);
}

int get_input() {
   cout << "What prime number do you want to binary search for? ";
   int input;
   cin >> input;
   return input;
}

// Draw out a simplified stack frame diagram for this program's execution.
int main() {
   int data[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
   int input = get_input();
   cout << "The number " << input << " is at index " << binary_search(data, input, 0, 10) << endl;
}