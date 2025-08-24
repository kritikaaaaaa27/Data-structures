#include <bits/stdc++.h>
using namespace std;
struct Product {
    int id;
    string name;  
    int quantity;
    float price;
    Product* next;
};
Product* head = nullptr;
void addProd(int id, string name, int quantity, float price) {
    Product* newp = new Product;
    newp->id = id;
    newp->name = name;
    newp->quantity = quantity;
    newp->price = price;
    newp->next = nullptr;

    if (head == nullptr) {
        head = newp;
    }
    else {
        Product* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newp;
    }
}

void disppro() {
    Product* temp = head;
    if (temp == nullptr) {
        cout << "   Empty.\n";
        return;
    }
    while (temp != nullptr) {
        cout << "ID: " << temp->id
            << ", Name: " << temp->name
            << ", Qty: " << temp->quantity
            << ", Price: " << temp->price << endl;
        temp = temp->next;
    }
}

void updateProd(int id, int quantity2, float price2) {
    Product* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->id == id) {  
            temp->quantity = quantity2;
            temp->price = price2;
            cout << "Price and Quantity Updated.\n";
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Not found.\n";
    }
}

void delPro(int id) {
    if (head == nullptr) {
        cout << "Empty.\n";
        return;
    }

    if (head->id == id) {
        Product* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Product deleted.\n";
        return;
    }

    Product* temp = head;
    while (temp->next != nullptr && temp->next->id != id) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Not found.\n";
    }
    else {
        Product* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Deleted.\n";
    }
}

void totalval() {
    float tot = 0;
    Product* temp = head;
    while (temp != nullptr) {
        tot = tot + temp->quantity * temp->price;
        temp = temp->next;
    }
    cout << "Total Value: " << tot << endl;
}

int main() {
    int choice;
    do {
        cout << "\nChoices:\n"
             << "1. Add Product\n"
             << "2. Display Products\n"
             << "3. Update Product\n"
             << "4. Delete Product\n"
             << "5. Total valuation\n"
             << "6. Exit\n"
             << "Enter:";
        cin >> choice;
       
        if (choice == 1) {
            int id, qty;
            float price;
            string name;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Quantity: ";
            cin >> qty;
            cout << "Price: ";
            cin >> price;
            addProd(id, name, qty, price);
        }
        else if (choice == 2) {
            disppro();
        }
        else if (choice == 3) {
            int id, qty;
            float price;
            cout << "Product ID: ";
            cin >> id;
            cout << "New Quantity: ";
            cin >> qty;
            cout << "New Price: ";
            cin >> price;
            updateProd(id, qty, price);
        }
        else if (choice == 4) {
            int id;
            cout << "Product ID: ";
            cin >> id;
            delPro(id);
        }
        else if (choice == 5) {
            totalval();
        }
        else if (choice == 6) {
            cout << "Exit.\n";
        }
        else {
            cout << "Invalid.\n";
        }
    } while (choice != 6);
    return 0;
}
