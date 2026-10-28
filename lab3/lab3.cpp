#include <iostream> 
#include "Warehouse.h"
using namespace std;
int main() {
    try {
        Warehouse wh;
        wh.addProduct(Product("Item1", 10, 100.0));
        wh.addProduct(Product("Item2", 20, 200.0));

        wh.display();

        ++wh.getProduct(0);
        --wh.getProduct(1);

        wh.display();

        wh.getProduct(1) = Product("Item3", 15, 150.0);
        wh.display();

        int idx = wh.search("Item1");
        if (idx != -1) {
            wh.getProduct(idx).display();
        }

        try {
            wh.getProduct(0).setPrice(-50.0);
        }
        catch (const exception& e) {
            cout << "Caught: " << e.what() << endl;
        }

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}