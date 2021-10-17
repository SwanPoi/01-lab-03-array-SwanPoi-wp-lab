// Copyright 2018 Your Name <your_email>

#include <iostream>
#include <tasks.hpp>
#include <vector>

// Task 2.
int sum(const std::vector<int>& input) {
  int sum_vector = 0;
  for (int element : input) {
    sum_vector += element;
  }
  return sum_vector;
}

int square_sum(const std::vector<int>& input) {
  int square_sum_vector = 0;
  for (int element : input) {
    square_sum_vector += element * element;
  }
  return square_sum_vector;
}

int sum_six(const std::vector<int>& input) {
  int sum_six_vector = 0;
  for (size_t i = 0; i < 6; ++i) {
    sum_six_vector += input[i];
  }
  return sum_six_vector;
}

int sum_k(const std::vector<int>& input, int k1, int k2) {
  int sum_k_vector = 0;
  for (int i = k1; i <= k2; ++i) {
    sum_k_vector += input[i];
  }
  return sum_k_vector;
}

int mean(const std::vector<int>& input) {
  int sum = 0;
  int arithm_mean = 0;
  for (int element : input) {
    sum += element;
  }
  arithm_mean = sum / input.size();
  return arithm_mean;
}

int mean_k(const std::vector<int>& input, int s1, int s2) {
  int sum = 0;
  int mean = 0;
  for (int i = s1; i <= s2; ++i) {
    sum += input[i];
  }
  mean = sum / (s2 - s1 + 1);
  return mean;
}
