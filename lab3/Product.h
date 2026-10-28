#pragma once 
#include <iostream> 
#include <string> 
#include <stdexcept>

using namespace std;
class WarehouseException : public exception 
{
    string message; 
public: 
    WarehouseException(string msg) : message(msg) {} 
    const char* what() const noexcept override { return message.c_str();
    } 
};
class Product 
{
private: 
    string name; 
       int quantity; 
       double price;
public: Product() : name("Unknown"), quantity(0), price(0.0) {}
      Product(string n, int q, double p) 
      {
          setName(n);
          setQuantity(q);
          setPrice(p);
      }

      string getName() const { return name; }

      int getQuantity() const
      {
          if (quantity < 0) throw WarehouseException("Invalid quantity!");
          return quantity;
      }

      double getPrice() const
      {
          if (price < 0.0) throw WarehouseException("Invalid price!");
          return price;
      }

      void setName(const string& n)
      {
          if (n.empty()) throw WarehouseException("Name cannot be empty!");
          name = n;
      }

      void setQuantity(int q) 
      {
          if (q < 0) throw WarehouseException("Quantity cannot be negative!");
          quantity = q;
      }

      void setPrice(double p) 
      {
          if (p < 0.0) throw WarehouseException("Price cannot be negative!");
          price = p;
      }

      Product& operator++()
      {
          ++quantity;
          return *this;
      }

      Product& operator--()
      {
          if (quantity <= 0) throw WarehouseException("Quantity is already zero!");
          --quantity;
          return *this;
      }

      Product& operator=(const Product& other)
      {
          if (this == &other) return *this;
          name = other.name;
          quantity = other.quantity;
          price = other.price;
          return *this;
      }

      void display() const {
          cout << name << " | Qty: " << quantity << " | Price: " << price << endl;
      }
};