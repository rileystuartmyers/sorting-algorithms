#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "sorting.h"

int main() {

  std::ofstream ofs("output.txt");
  std::ifstream ifs("input.txt"); 

  std::string input_string;
  std::getline(ifs, input_string);

  if (!isdigit(input_string[0])) {

    ofs << "Input is invalid.";
    return 0;

  } else {

    std::string num;
    std::stringstream nums(input_string);

    while (nums >> num) {

      AddToTail(std::stoi(num));

    }

  }

  std::getline(ifs, input_string);
  bool bubble_find = input_string.find("Bubble") != std::string::npos;
  bool selection_find = input_string.find("Selection") != std::string::npos;
  bool insertion_find = input_string.find("Insertion") != std::string::npos;
  
  if (bubble_find) {

    BubbleSort(ofs);

  } else if (selection_find) {

    SelectionSort(ofs);

  } else if (insertion_find) {

    InsertSort(ofs);

  } else {

    ofs << "Input is invalid.";

  }
  
  return 0;

};