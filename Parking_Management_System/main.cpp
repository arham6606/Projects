#include "parking.h"

int main()
{
    // Variables for storing owner and car details
    int count1 = 0;          // this is for making code cleaner
    int count = 0;           // To track the first-time owner entry
    Car c1[100];             // Array of cars
    Owner o1[100];           // Array of owners
    Garage g1("Pak_Wheels"); // Creating a Garage object
    string name;             // Owner's name
    int index = 0, i = 0;    // Index tracking for cars and owners
    string ownerEnter = "e"; // Control variable for owner addition

    while (true)
    {
        // Display the main menu
        showMenu();
        string choiceMenu;
        cout << "Enter your choice: ";
        getline(cin, choiceMenu);
        cin.clear();

        // Adding owner and cars
        if (choiceMenu == "1")
        {
            loadingEffect("Loading");
            while (true)
            {
                // Check if we need to add another owner
                if (ownerEnter != "1" && count1 == 0)
                {
                    string choice;
                    cout << "Press -1 to Exit, any key to Continue: ";
                    getline(cin, choice);
                    if (choice == "-1")
                        break;
                }

                // Get owner name (only once per owner)
                if (count == 0)
                {
                    cout << "Enter Owner's Name: ";
                    getline(cin, name);
                    count++;
                }

                // Get car details
                string model;
                cout << "Enter Car Model: ";
                getline(cin, model);

                int year;
                cout << "Enter Launch Year: ";
                while (!(cin >> year))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Enter a valid year: ";
                }

                float price;
                cout << "Enter Price: ";
                while (!(cin >> price))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Enter a valid price: ";
                }
                cin.ignore();

                // Assign car details to owner
                assign(o1[index], c1[i], name, model, year, price);
                addCar(o1[index], c1[i]);

                // Ask to add more cars
                cout << "\nEnter 1 to add more cars, 0 to stop: ";
                int yesNo;
                while (!(cin >> yesNo) || (yesNo != 1 && yesNo != 0))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Enter 1 or 0: ";
                }
                cin.ignore();

                if (yesNo == 1)
                {
                    i++;
                    count1 = 1;
                }
                else
                {
                    cout << endl;
                    break;
                }
            }

            addOwner(g1, o1[index]);

            cout << "Press 1 to Enter Another Owner, any key to continue: ";
            getline(cin, ownerEnter);

            if (ownerEnter == "1")
            {
                count = 0;
                i = 0;
                index++;
                count1 = 0;
            }
        }

        // Display owner's cars
        else if (choiceMenu == "2")
        {
            loadingEffect("Loading");

            string ownerName;
            cout << "Enter Owner's Name: ";
            getline(cin, ownerName);
            for (int i = 0; i < g1.numOwners; i++)
            {
                if (g1.owners[i].name == ownerName)
                {
                    Car *owned = listOwnerCars(g1.owners[i]);
                    if (owned)
                    {
                        cout << "\n"
                             << g1.owners[i].name << "'s Cars:\n";
                        cout << "----------------------------------\n";
                        cout << left << setw(15) << "Model" << setw(10) << "Year" << setw(10) << "Price" << endl;
                        cout << "----------------------------------\n";
                        for (int j = 0; j < g1.owners[i].numCars; j++)
                        {
                            cout << left << setw(15) << owned[j].model << setw(10) << owned[j].year << "$" << fixed << setprecision(2) << owned[j].price << endl;
                        }
                        delete[] owned;
                    }
                    else
                    {
                        cout << "No cars found for " << ownerName << "!\n";
                    }
                    break;
                }
            }
        }

        // Remove a car from an owner
        else if (choiceMenu == "3")
        {
            loadingEffect("Loading");

            string ownerName, model;
            cout << "Enter Owner's Name: ";
            getline(cin, ownerName);
            cout << "Enter Car Model to Remove: ";
            getline(cin, model);
            for (int i = 0; i < g1.numOwners; i++)
            {
                if (g1.owners[i].name == ownerName)
                {
                    removeCar(g1.owners[i], model);
                    cout << "Car Removed Successfully!\n";
                    break;
                }
            }
        }

        // most expensive car
        else if (choiceMenu == "4")
        {
            loadingEffect("Loading");

            // creating object
            Car expensive = findMostExpensiveCar(g1);

            // good screen output
            cout << "----------------------------------\n";
            cout << left << setw(15) << "Model" << setw(10) << "Year" << setw(10) << "Price" << endl;
            cout << "----------------------------------\n";
            cout << left << setw(15) << expensive.model << setw(10) << expensive.year << "$" << fixed << setprecision(2) << expensive.price << endl;
        }

        // total number of cars
        else if (choiceMenu == "5")
        {
            loadingEffect("Loading");

            // function calling
            int result = countTotalCars(g1);

            cout << "The total number of cars in the garage: " << result << endl;
        }

        // Exit program
        else if (choiceMenu == "6")
        {
            loadingEffect("Loading");

            cout << "Thank you for using the Parking System! Exiting...\n";
            break;
        }

        else
        {
            cout << "Invalid Choice! Try Again.\n";
        }
    }
    return 0;
}
