#include <iostream>
using namespace std;
#include <string>

struct Supplier
{
    string supplierName;
    string contactNumber;
};

struct Product
{
    string productName;
    float ProductPrice;
    Supplier supplier;
};

struct Inventory
{
    Product *products;
    int size;
    int currentCount;
};

void initializeInventory(Inventory &inv, int size);
void setSupplierData(Supplier &supplier, string supplierName, string contactNumber);
void setProductData(Product &product, Supplier supplier, string productName,float productPrice);
int addProductToInventory(Inventory &inv, Product product);
Supplier* searchProductByName(Inventory &inv, string productName);
void displayProduct(Product &product);
void displayInventory(Inventory &inv);
