#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "collvalue.h"
#include "sorting.h"

typedef CollectingValue<int> CollInt;

std::vector<CollInt> generate_data(size_t n) {
  std::vector<CollInt> data(n);
  for (size_t i = 0; i < n; ++i)
    data[i] = CollInt(i);
  return data;
}

void shuffle_data(std::vector<CollInt> &data) {
  srand(time(0));
  for (size_t i = 0; i < data.size(); ++i) {
    size_t j = rand() % data.size();
    std::swap(data[i], data[j]);
  }
}

int main() {
  size_t sizes[] = {100, 500, 1000, 2000};

  std::cout << "N\tAlgo\t\tComps\t\tSwaps\t\tMoves\n";
  std::cout
      << "----------------------------------------------------------------\n";

  for (int si = 0; si < 4; ++si) {
    size_t n = sizes[si];
    std::vector<CollInt> number_data = generate_data(n);

    // --- Std Sort ---
    shuffle_data(number_data);
    CollInt::reset_stats();
    std::sort(number_data.begin(), number_data.end());
    std::cout << n << "\tstd::sort\t" << CollInt::comps << "\t\t"
              << CollInt::swaps << "\t\t" << CollInt::moves << "\n";

    // --- Bubble Sort ---
    shuffle_data(number_data);
    CollInt::reset_stats();
    bubble_sort(number_data.begin(), number_data.end());
    std::cout << n << "\tBubble\t\t" << CollInt::comps << "\t\t"
              << CollInt::swaps << "\t\t" << CollInt::moves << "\n";

    // --- Quick Sort ---
    shuffle_data(number_data);
    CollInt::reset_stats();
    quick_sort(number_data.begin(), number_data.end());
    std::cout << n << "\tQuickSort\t" << CollInt::comps << "\t\t"
              << CollInt::swaps << "\t\t" << CollInt::moves << "\n";

    std::cout
        << "--------------------------------------------------------------\n";
  }

  return 0;
}
