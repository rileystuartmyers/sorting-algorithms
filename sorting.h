#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifndef SORTING_H
#define SORTING_H

struct node {

  int data;

  node *next;
  node *prev;

};

int size = 0;
node *head = nullptr;

void AddToHead(int _data) {

  node *temp = new node();

  if (head == nullptr) {

    temp->data = _data;
    temp->next = nullptr;
    temp->prev = nullptr;

    head = temp;
    ++size;
    return;
  }

  temp->data = _data;
  temp->next = head;
  temp->prev = nullptr;
  head->prev = temp;

  head = temp;
  ++size;
  return;
};

void AddToTail(int _data) {

  node *temp = new node();

  if (head == nullptr) {

    temp->data = _data;
    temp->next = nullptr;
    temp->prev = nullptr;

    head = temp;
    ++size;
    return;
  }

  temp->data = _data;
  temp->next = nullptr;

  node *thead = head;

  while (thead->next != nullptr) {

    thead = thead->next;
  }

  temp->prev = thead;
  thead->next = temp;
  ++size;
  return;
};

void PrintAll(std::ofstream& ofs) {

  node *thead = head;

  ofs << "[";

  while (thead->next != nullptr) {

    ofs << thead->data << ",";
    thead = thead->next;
  }

  ofs << thead->data << "]" << std::endl;
  
};

void Swap(node *node2, node *node3) {

  if ((node2 == nullptr) || (node3 == nullptr)) { // check for empty list

    return;

  }

  if ((node2->prev != nullptr) &&
      (node3->next != nullptr)) { // switched nodes are in middle of list

    node *node1 = node2->prev;
    node *node4 = node3->next;

    node1->next = node3;
    node3->prev = node1;

    node4->prev = node2;
    node2->next = node4;

    node2->prev = node3;
    node3->next = node2;

    return;

  } else if ((node2->prev == nullptr) &&
             (node3->next == nullptr)) { // head and tail are only nodes

    node2->prev = node3;
    node3->next = node2;

    return;

  } else if (node2->prev == nullptr) { // head is one of switched elements

    node *node4 = node3->next;

    node4->prev = node2;
    node2->next = node4;

    node2->prev = node3;
    node3->prev = nullptr;

    node3->next = node2;

    head = node3;

    return;

  } else { // tail is one of switched elements

    node *node1 = node2->prev;

    node1->next = node3;
    node3->prev = node1;

    node2->prev = node3;
    node3->next = node2;
    node2->next = nullptr;

    return;
  }
};

void BubbleSort(std::ofstream& opstream) {

  if (head == nullptr) {

    return;

  }

  PrintAll(opstream);

  int count = size;
  node *temp_head;
  int swap_count;

  for (int i = 0; i <= count; ++i) {

    temp_head = head;
    swap_count = 0;

    for (int u = 0; u < count - 1; ++u) {

      node *node1 = temp_head;
      node *node2 = node1->next;

      if (node1->data > node2->data) {

        Swap(node1, node2);
        temp_head = node2;
        swap_count = 1;
      }

      temp_head = temp_head->next;
    }

    if (swap_count == 0) {

      break;
    }

    PrintAll(opstream);

  }
  
};

void SelectionSort(std::ofstream& opstream) {

  if (head == nullptr) {

    return;

  }
  
  int lowest_flag;
  int lowest_value;
  
  if (size == 0) {

    return;
  }

  node* iterator;

  for (int i = 0; i < size - 1; ++i) { // swap(temp -> prev, temp);

    lowest_value = 99999;
    iterator = head;

    for (int b = 0; b < i; ++b) { // placing head in area of list that's unsorted

      iterator = iterator -> next;

    }

    for (int lowind = 0; lowind < size -i; ++lowind) { // find lowest value and its index

      if (iterator -> data <= lowest_value) {

        lowest_value = iterator -> data;
        lowest_flag = lowind + i;
        
      }

      iterator = iterator -> next;
      
    }

    iterator = head;

    for (int g = 0; g < lowest_flag; ++g) { // placing iterator at lowest value

      iterator = iterator -> next;
      
    }

    int swap_count = 0;

    for (int swaps_num = 0; swaps_num < (lowest_flag - i); ++swaps_num) {

      Swap(iterator -> prev, iterator);
      swap_count++;

    }
    
    node* rev1 = iterator -> next;
    node* rev2 = rev1 -> next;

    for (int swaps_rev = 0; swaps_rev < (swap_count - 1); swaps_rev++) {

      Swap(rev1, rev2);
      rev2 = rev1 -> next;

    }

    PrintAll(opstream);
    
  }

  return;
  
};

void InsertSort(std::ofstream& opstream){

  if (head == nullptr) {

    return;

  }
  
  for (int i = 1; i < size; ++i) {

    node* thead = head;

    for (int h = 0; h < i; ++h) { // get head in right place

      thead = thead -> next;

    }


    while ( (thead -> prev != nullptr) && ((thead -> data) < (thead -> prev -> data)) ) {

      node* phead = thead -> prev;

      Swap(phead, thead);

    }

    PrintAll(opstream);

  }



};

#endif
