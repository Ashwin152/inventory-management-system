#include <iostream>
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;
    float price;

    void addProduct() {
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
    }

    void displayProduct() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nQuantity: " << quantity;
        cout << "\nPrice: " << price << endl;
    }
};

int main() {
    Product p[100];
    int count = 0;
    int choice;

    do {
        cout << "\n\n--- Inventory Management System ---";
        cout << "\n1. Add Product";
        cout << "\n2. Display Products";
        cout << "\n3. Update Product";
        cout << "\n4. Delete Product";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            p[count].addProduct();
            count++;
            break;

        case 2:
            for (int i = 0; i < count; i++) {
                p[i].displayProduct();
            }
            break;

        case 3: {
            int id, found = 0;
            cout << "Enter Product ID to update: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (p[i].id == id) {
                    cout << "Enter new details:\n";
                    p[i].addProduct();
                    found = 1;
                    break;
                }
            }

            if (!found)
                cout << "Product not found!";
            break;1
        }
        case 4: {
            int id, found = 0;
            cout << "Enter Product ID to delete: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (p[i].id == id) {
                    for (int j = i; j < count - 1; j++) {
                        p[j] = p[j + 1];
                    }
                    count--;
                    found = 1;
                    cout << "Product deleted!";
                    break;
                }
            }
            if (!found)
                cout << "Product not found!";
            break;
        }

        case 5:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice!";
        }
    } while (choice != 5);
    return 0;
}