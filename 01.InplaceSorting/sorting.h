#ifndef SORTING_H
#define SORTING_H

#include <iterator>
#include <utility>

template <typename Iterator> void bubble_sort(Iterator begin, Iterator end) {
  if (begin == end || std::next(begin) == end)
    return;

  for (Iterator i = begin; i != end; ++i) {
    bool swapped = false;

    for (Iterator j = begin; std::next(j) != end; ++j) {
      Iterator next_j = std::next(j);
      if (*next_j < *j) {
        using std::swap;
        swap(*j, *next_j);
        swapped = true;
      }
    }

    if (!swapped)
      break;
  }
}

namespace detail {
template <typename Iterator>
void quick_sort_impl(Iterator begin, Iterator end) {
  if (begin == end || std::next(begin) == end)
    return;

  std::ptrdiff_t dist = std::distance(begin, end);
  Iterator pivot_iter = std::next(begin, dist / 2);

  Iterator left = begin;
  Iterator right = std::prev(end);

  while (true) {
    while (*left < *pivot_iter)
      ++left;

    while (*pivot_iter < *right)
      --right;

    if (left >= right)
      break;

    using std::swap;
    swap(*left, *right);
    ++left;
  }

  quick_sort_impl(begin, left);
  quick_sort_impl(left, end);
}
} // namespace detail

template <typename Iterator> void quick_sort(Iterator begin, Iterator end) {
  detail::quick_sort_impl(begin, end);
}

#endif
