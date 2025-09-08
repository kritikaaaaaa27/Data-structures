#include <iostream>
using namespace std;

struct Request {
    int id;
    string name;
    string service;
    string status;
    Request* next;

    Request(int i, string n, string s) {
        id = i;
        name = n;
        service = s;
        status = "Pending";
        next = NULL;
    }
};
class Queue {
    Request* head;
    Request* tail;
public:
    Queue() {
        head = tail = NULL;
    }
    void add(int id, string name, string service) {
        Request* newReq = new Request(id, name, service);
        if (tail == NULL) {
            head = tail = newReq;
        } else {
            tail->next = newReq;
            tail = newReq;
        }
        cout << "Added: Request ID: " << id 
             << ", Name: " << name 
             << ", Service: " << service 
             << ", Status: Pending" << endl;
    }
    void process() {
        if (head == NULL) {
            cout << "No requests to process." << endl;
            return;
        }
        Request* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;

        temp->status = "Completed";
        cout << "Processed: Request ID: " << temp->id 
             << ", Name: " << temp->name 
             << ", Service: " << temp->service 
             << ", Status: " << temp->status << endl;
        delete temp;
    }
    void show() {
        if (head == NULL) {
            cout << "No pending requests." << endl;
            return;
        }
        cout << "Pending Requests:" << endl;
        Request* temp = head;
        while (temp != NULL) {
            cout << "Request ID: " << temp->id 
                 << ", Name: " << temp->name 
                 << ", Service: " << temp->service 
                 << ", Status: " << temp->status << endl;
            temp = temp->next;
        }
    }
};
int main() {
    Queue q;
    q.add(101,"John Doe","Technical Support");
    q.add(102,"Jane Smith","Billing Inquiry");
    q.add(103,"David Brown","Product Information");
    cout << endl;
    q.show();
    q.process();
    q.process();
    cout << endl;
    q.show();
    return 0;
}
