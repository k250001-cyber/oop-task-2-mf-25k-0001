#include <iostream>
#include <string>
using namespace std;

class StationeryShop {
private:
    string items[100];
    double prices[100];
    int itemCount;

public:
    StationeryShop() {
        itemCount = 0;
    }
    
    void addItem() {
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, items[itemCount]);
        cout << "Enter price: ";
        cin >> prices[itemCount];
        itemCount++;
        cout << "Item added successfully." << endl;
    }
    
    void displayItems() {
        cout << "\nItems List:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << items[i] << endl;
        }
    }
    
    void editPrice() {
        string item;
        cout << "Enter item name to edit: ";
        cin.ignore();
        getline(cin, item);
        
        for (int i = 0; i < itemCount; i++) {
            if (items[i] == item) {
                cout << "Enter new price: ";
                cin >> prices[i];
                cout << "Price updated." << endl;
                return;
            }
        }
        cout << "Item not found." << endl;
    }
    
    void viewAll() {
        cout << "\nAll Items and Prices:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << items[i] << " - Rs. " << prices[i] << endl;
        }
    }
    
    void generateReceipt() {
        string purchasedItems[50];
        int quantities[50];
        int purchaseCount = 0;
        
        cout << "How many different items purchased: ";
        cin >> purchaseCount;
        
        for (int i = 0; i < purchaseCount; i++) {
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, purchasedItems[i]);
            cout << "Enter quantity: ";
            cin >> quantities[i];
        }
        
        cout << "\n========== RECEIPT ==========" << endl;
        double total = 0;
        
        for (int i = 0; i < purchaseCount; i++) {
            for (int j = 0; j < itemCount; j++) {
                if (items[j] == purchasedItems[i]) {
                    double itemTotal = prices[j] * quantities[i];
                    cout << purchasedItems[i] << " x " << quantities[i] << " = Rs. " << itemTotal << endl;
                    total += itemTotal;
                }
            }
        }
        
        cout << "----------------------------" << endl;
        cout << "Total: Rs. " << total << endl;
        cout << "============================" << endl;
    }
};

int main() {
    StationeryShop shop;
    int choice;
    
    do {
        cout << "\n1. Add Item" << endl;
        cout << "2. Display Items" << endl;
        cout << "3. Edit Price" << endl;
        cout << "4. View All Items with Prices" << endl;
        cout << "5. Generate Receipt" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                shop.addItem();
                break;
            case 2:
                shop.displayItems();
                break;
            case 3:
                shop.editPrice();
                break;
            case 4:
                shop.viewAll();
                break;
            case 5:
                shop.generateReceipt();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 6);
    
    return 0;
}
