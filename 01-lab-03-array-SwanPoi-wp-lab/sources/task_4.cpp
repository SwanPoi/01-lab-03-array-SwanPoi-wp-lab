// Copyright 2018 Your Name <your_email>

#include <iostream>
#include <tasks.hpp>
#include <vector>

// Task 4.
void remove_negative(std::vector<int>& input) {
  size_t index = 0;
  int index_negative = -1;
  while (index_negative == -1 && index < input.size()) {
    if (input[index] < 0) {
      index_negative = index;
    }
    index += 1;
  }
  if (index_negative != -1) {
    input.erase(input.begin() + index_negative);
  }
}

void remove_last_even(std::vector<int>& input) {
  size_t index = input.size() - 1;
  int index_even = -1;
  while (index > 0 && index_even == -1) {
    if (input[index] % 2 == 0) {
      index_even = index;
    }
    index -= 1;
  }
  if (index_even != -1) {
    input.erase(input.begin() + index_even);
  }
}
