// Copyright 2018 Your Name <your_email>

#include <iostream>
#include <tasks.hpp>
#include <vector>

// Task 3.
void swap_el(std::vector<int>& input) {
  size_t end_index = 3;
  int buffer = 0;
  for (size_t i = 0; i < 3; ++i) {
    buffer = input[i];
    input[i] = input[input.size() - end_index];
    input[input.size() - end_index] = buffer;
    end_index -= 1;
  }
}
