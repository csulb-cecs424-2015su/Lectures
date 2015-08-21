#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
using std::cout;
using std::endl;

int main() {
   std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   
   // "filter"
   std::vector<int> evens;
   std::copy_if(nums.begin(), nums.end(), std::back_inserter(evens),
      [](int x) {return x % 2 == 0; });

   cout << "Even numbers:" << endl;
   for (int &i : evens) {
      cout << i << " ";
   }
   cout << endl;

   // "map"
   std::vector<int> squares;
   std::transform(nums.begin(), nums.end(), std::back_inserter(squares),
      [](int x) {return x * x; });
   cout << "Squared numbers:" << endl;
   for (int &i : squares) {
      cout << i << " ";
   }
   cout << endl;

   // "reduce"
   int sum = std::accumulate(nums.begin(), nums.end(), 0, std::plus<int>());
   cout << "Sum: " << sum << endl;
}