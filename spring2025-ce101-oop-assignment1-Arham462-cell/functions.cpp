#include "functions.h"

void initializeInventory(Inventory &inv, int size)
{
    inv.products = new Product[size];
    inv.currentCount = 0;
    inv.size = size;
}

void setSupplierData(Supplier &supplier, string supplierName, string contactNumber)
{
    supplier.supplierName = supplierName;
    supplier.contactNumber = contactNumber;
}

void setProductData(Product &product, Supplier supplier, string productName, float productPrice)
{
    product.productName = productName;
    product.ProductPrice = productPrice;
    product.supplier = supplier;
}

int addProductToInventory(Inventory &inv, Product product)
{
    if (inv.size > inv.currentCount)
    {
        inv.products[inv.currentCount] = product;
        inv.currentCount++;
        return 0;
    }
    else
    {
        return 1;
    }
}

Supplier *searchProductByName(Inventory &inv, string productName)
{
    for (int i = 0; i < inv.currentCount; i++)
    {
        if (inv.products[i].productName == productName)
        {
            return &inv.products[i].supplier;
        }
    }
    return nullptr;
}

void displayProduct(Product &product)
{
    cout << "\nProduct Name: " << product.productName << endl;
    cout << "Product Price: " << product.ProductPrice << endl;
    cout << "Supplier Name: " << product.supplier.supplierName << endl;
    cout << "Contact Number: " << product.supplier.contactNumber << endl;
}

void displayInventory(Inventory &inv)
{
    if(inv.currentCount==0)
    {
        cout<<"You are accessing an empty inventory"<<endl;
        return;
    }

    for(int i = 0 ; i<inv.currentCount;i++)
    {
        displayProduct(inv.products[i]);
    }


}