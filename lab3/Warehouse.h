#pragma once
#include  <iostream> 
#include <vector> #include <string> 
#include "Product.h"
using namespace std;
class Warehouse {
private: vector<Product> products;
public: void addProduct(const Product& p) { products.push_back(p); }
      int search(const string& targetName) const {
          for (size_t i = 0; i < products.size(); ++i) {
              if (products[i].getName() == targetName) return static_cast<int>(i);
          }
          return -1;
      }

      vector<int> search(double targetPrice) const {
          vector<int> results;
          for (size_t i = 0; i < products.size(); ++i) {
              if (products[i].getPrice() == targetPrice) results.push_back(static_cast<int>(i));
          }
          return results;
      }

      vector<int> search(int minQ, int maxQ) const {
          vector<int> results;
          for (size_t i = 0; i < products.size(); ++i) {
              int q = products[i].getQuantity();
              if (q >= minQ && q <= maxQ) results.push_back(static_cast<int>(i));
          }
          return results;
      }

      Product& getProduct(int index) {
          if (index < 0 || index >= static_cast<int>(products.size())) {
              throw WarehouseException("Index out of bounds!");
          }
          return products[index];
      }

      void display() const {
          for (size_t i = 0; i < products.size(); ++i) {
              cout << "[" << i << "] ";
              products[i].display();
          }
      }
};