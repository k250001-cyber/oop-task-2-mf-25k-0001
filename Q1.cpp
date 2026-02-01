#include <iostream>
#include <string>
using namespace std;

class BoardMarker {
private:
    string company;
    string color;
    bool refillable;
    bool inkEmpty;

public:
    void setCompany(string c) { company = c; }
    void setColor(string col) { color = col; }
    void setRefillable(bool r) { refillable = r; }
    void setInkStatus(bool empty) { inkEmpty = empty; }
    
    string getCompany() { return company; }
    string getColor() { return color; }
    bool getRefillable() { return refillable; }
    bool getInkStatus() { return inkEmpty; }
    
    void write() {
        if (inkEmpty) {
            cout << "Cannot write. Ink is empty." << endl;
        } else {
            cout << "Writing with " << color << " marker." << endl;
        }
    }
    
    void refill() {
        if (refillable) {
            inkEmpty = false;
            cout << "Marker refilled successfully." << endl;
        } else {
            cout << "This marker cannot be refilled." << endl;
        }
    }
};

int main() {
    BoardMarker marker1, marker2, marker3;
    
    marker1.setCompany("Dollar");
    marker1.setColor("Black");
    marker1.setRefillable(true);
    marker1.setInkStatus(false);
    
    marker2.setCompany("Faber");
    marker2.setColor("Red");
    marker2.setRefillable(false);
    marker2.setInkStatus(true);
    
    marker3.setCompany("Pilot");
    marker3.setColor("Blue");
    marker3.setRefillable(true);
    marker3.setInkStatus(true);
    
    cout << "Marker 1:" << endl;
    marker1.write();
    
    cout << "\nMarker 2:" << endl;
    marker2.write();
    marker2.refill();
    
    cout << "\nMarker 3:" << endl;
    marker3.write();
    marker3.refill();
    marker3.write();
    
    return 0;
}
