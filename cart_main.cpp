#include <iostream>
#include <vector>
#include "datamodel.h"

using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 220),
    Product(2, "cherry", 400),
    Product(3, "mango", 70),
    Product(4, "orange", 80),
    Product(5, "guava", 110),
    Product(6, "pineapple", 90),
    Product(7, "strawberry", 420),
    Product(8, "watermelon", 25),
};

Product *chooseProduct()
{
    // Display the list of products
    string productlist;
    cout << "Available Products " << endl;
    cout << endl;

    for (auto product : allProducts)
    {
        productlist.append(product.getDisplayName());
    }
    cout << productlist << endl;

    cout << "-------------------------------------------------------------" << endl;
    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getShortName() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "Fruit not available!" << endl;
    return NULL;
}

bool checkout(Cart &cart)
{
    if (cart.isEmpty())
    {
        return false;
    }

    int total = cart.getTotal();
    cout << "Pay in Cash";

    int paid;
    cin >> paid;

    if (paid >= total)
    {
        cout << "Change " << paid - total << endl;
        cout << "Thank you for shopping!";
        return true;
    }
    else
    {
        cout << "Not enough case";
        return false;
    }
}

int main()
{
    char option;
    Cart cart;
    while (true)
    {
        cout << "Select an option - (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> option;
        if (option == 'a')
        {
            // TODO: Add to cart
            // View all products + choose prodcut + add to the cart
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Added to the Cart - " << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        }
        else if (option == 'v')
        {
            cout << "-------------------------------------------------------------" << endl;
            cout << cart.viewCart();
            cout << "-------------------------------------------------------------" << endl;
        }
        else if (option == 'c')
        {
            cart.viewCart();
            if (checkout(cart))
            {
                break;
            }
        }
    }

    return 0;
}