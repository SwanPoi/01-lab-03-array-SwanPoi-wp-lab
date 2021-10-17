// Copyright 2018 Your Name <your_email>

#include <iostream>
#include <tasks.hpp>
#include <vector>

// Task 1.
void multi_2(std::vector<int>& input) {
  for (int& element : input) {
    element *= 2;
  }
}

void reduce_a(std::vector<int>& input, int a) {
  for (int& element : input) {
    element -= a;
  }
}

void div_on_first(std::vector<int>& input) {
  int div_1 = input[0];
  for (size_t i = 0; i < input.size(); ++i) {
    input[i] = input[i] / div_1;
  }
}
