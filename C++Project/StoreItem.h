#pragma once
#include <iostream>
#include <string>

template <typename NameTemplate, typename PriceTemplate>
class StoreItem

{
private:
    NameTemplate id; //template for id 
    using String = std::string;
    String name;
    PriceTemplate price; // template for price
    int quantity;

public:
    // constructor
    StoreItem(NameTemplate id, const std::string& name, PriceTemplate price, int quantity)
        : id(id), name(name), price(price), quantity(quantity) {
    }

    // setters
    void setPrice(PriceTemplate newPrice) {
        price = newPrice;
    }

    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    // getters
    NameTemplate getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    PriceTemplate getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

 // debug display mehtod
    void display() const {
        std::cout << "Item ID: " << id << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
    }

};


