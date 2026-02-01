#include <iostream>
#include <string>
using namespace std;

class WaterBottle {
private:
    string company;
    string color;
    double capacityLiters;
    double capacityMilliliters;

public:
    void setCompany(string c) { company = c; }
    void setColor(string col) { color = col; }
    void setCapacity(double ml) {
        capacityMilliliters = ml;
        capacityLiters = ml / 1000.0;
    }
    
    string getCompany() { return company; }
    string getColor() { return color; }
    double getCapacityLiters() { return capacityLiters; }
    double getCapacityMilliliters() { return capacityMilliliters; }
    
    void updateCapacity() {
        double drunk;
        cout << "How much water drank (in ml): ";
        cin >> drunk;
        
        capacityMilliliters -= drunk;
        capacityLiters = capacityMilliliters / 1000.0;
        
        cout << "Remaining capacity: " << capacityLiters << " liters (" << capacityMilliliters << " ml)" << endl;
    }
};

int main() {
    WaterBottle bottle;
    
    bottle.setCompany("Milton");
    bottle.setColor("Blue");
    bottle.setCapacity(1000);
    
    cout << "Company: " << bottle.getCompany() << endl;
    cout << "Color: " << bottle.getColor() << endl;
    cout << "Initial capacity: " << bottle.getCapacityLiters() << " liters (" << bottle.getCapacityMilliliters() << " ml)" << endl;
    
    bottle.updateCapacity();
    bottle.updateCapacity();
    
    return 0;
}
