// Copyright 2018 Your Name <your_email>

#include <iostream>
#include <locale>
#include <string>
#include <tasks.hpp>

// Task 5.
bool name_is_even(const std::string& name) {
  if (name.size() % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

// Task 6.
bool first_is_longer(const std::string& name_one, const std::string& name_two) {
  if (name_one.size() > name_two.size()) {
    return true;
  } else {
    return false;
  }
}

// Task 7.
void longest_shortest(const std::string& name_one, const std::string& name_two,
                      const std::string& name_three, std::string& the_longest,
                      std::string& the_shortest) {
  if (name_one.size() > name_two.size()) {
    if (name_one.size() < name_three.size()) {
      the_longest = name_three;
      the_shortest = name_two;
    } else if (name_two.size() > name_three.size()) {
      the_longest = name_one;
      the_shortest = name_three;
    } else {
      the_longest = name_one;
      the_shortest = name_two;
    }
  } else if (name_two.size() > name_one.size()) {
    if (name_two.size() < name_three.size()) {
      the_longest = name_three;
      the_shortest = name_one;
    } else if (name_three.size() > name_one.size()) {
      the_longest = name_two;
      the_shortest = name_one;
    } else {
      the_longest = name_two;
      the_shortest = name_three;
    }
  }
}

// Task 8.
std::string sub_str(const std::string& word, int m, int n) {
  std::string part_string = "";
  if (m <= n && n <= int(word.size())) {
    for (int i = m; i <= n; ++i) {
      part_string += word[i];
    }
  } else if (n > int(word.size())) {
    part_string = word;
  }
  return part_string;
}

// Task 9.
void add_stars(std::string& word) {
  std::string stars = "";
  for (size_t i = 0; i < word.size(); ++i) {
    stars += "*";
  }
  word = stars + word + stars;
}

// Task 10.
int percent_of_a(const std::string& word) {
  float count_a = 0.0;
  int percent_a = 0;
  std::string symbol = "";
  for (size_t i = 0; i < word.size(); ++i) {
    symbol = word[i];
    if (symbol == "a") {
      count_a += 1.0;
    }
  }
  percent_a = int((count_a / word.size()) * 100);
  return percent_a;
}

// Task 11.
std::string replace_can(const std::string& new_word) {
  std::string word = "Can you can a can as a canner can can a can?";
  std::string new_string = "";
  std::string buf = "";
  size_t length = 0;
  for (size_t i = 0; i < word.size(); ++i) {
    new_string += word[i];
    length = new_string.size();
    if (length >= 3) {
      buf = new_string[length - 3];
      buf += new_string[length - 2];
      buf += new_string[length - 1];
      if (buf == "can") {
        new_string.erase((length - 3));
        new_string += new_word;
      }
    }
  }
  return new_string;
}
