#include "functions.h"

int main()
{
    // creating the objects of structs
    Inventory inv;
    Supplier supp, *details;
    Product pro;

    // declaraion of variables
    string supplier, contact, productName, findProduct;
    float price;
    int space;
    int MAX, choice;

    while (true)
    {
        // choice
        cout << endl;
        cout << "Press -1 for exit" << endl;
        cout << "Press 1 for Setting the inventory" << endl;
        cout << "Press 2 for Setting supplier data" << endl;
        cout << "Press 3 for Setting Product data" << endl;
        cout << "Press 4 for Adding Product in inventory" << endl;
        cout << "Press 5 for Searching a Product" << endl;
        cout << "Press 6 for Displaying the inventory" << endl;
        cout << "\n";
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();
        cin.clear();

        if (choice == 1)
        {
            // size of inventory
            cout << "What should be the size of the inventory:";
            cin >> MAX;
            cin.ignore();
            cin.clear();
            // calling function
            initializeInventory(inv, MAX);
        }

        else if (choice == 2)
        {
            // user inputs;
            
            cout << "Enter the supplier Name: ";
            getline(cin, supplier);
            cout << "Enter the supplier Contact: ";
            getline(cin, contact);
            cout << "\n";
            // functions calling
            setSupplierData(supp, supplier, contact);
        }

        else if (choice == 3)
        {
            // user inputs
            cout << "Enter the product name:";
            getline(cin, productName);
            cout << "Enter the Product Price: ";
            cin >> price;
            cin.ignore();
            cout << "\n";
            // function calling
            setProductData(pro, supp, productName, price);
        }

        else if (choice == 4)
        {
            // function calling
            space = addProductToInventory(inv, pro);
            // checking
            if (space == 1)
            {
                cout << "Inventory is full\n";
            }
            else
            {
                cout << "Product is added to the inventory\n";
            }
        }

        else if (choice == 5)
        {
            // user inputs
            cout << "Enter the Product You want to find: ";
            getline(cin, findProduct);
            // function calling
            details = searchProductByName(inv, findProduct);
            if (details != nullptr)
            {
                // displaying information
                cout << "Supplier Name: " << details->supplierName << endl;
                cout << "Supplier Contact Number: " << details->contactNumber << endl;
            }
            else
            {
                cout << "No Product Founded" << endl;
            }
        }
        else if (choice == 6)
        {
            // function calling
            // displayProduct(pro);
            // function calling
            displayInventory(inv);
        }
        
        else if(choice == -1)
        {
            cout<<"System is shutting dowm"<<endl;
            break;
        }

        else 
        {
            cout<<"Invalid Input.Try Again"<<endl;
        }
    }
}