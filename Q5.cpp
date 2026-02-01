#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double monthlySalary;
    double taxPercentage;

public:
    void get_data() {
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter monthly salary: ";
        cin >> monthlySalary;
        cout << "Enter tax percentage: ";
        cin >> taxPercentage;
    }
    
    double Salary_after_tax() {
        double tax = (taxPercentage / 100) * monthlySalary;
        return monthlySalary - tax;
    }
    
    void update_tax_percentage() {
        cout << "Enter new tax percentage: ";
        cin >> taxPercentage;
        cout << "Tax percentage updated to " << taxPercentage << "%" << endl;
        cout << "New salary after tax: " << Salary_after_tax() << endl;
    }
    
    void display() {
        cout << "\nEmployee: " << name << endl;
        cout << "Monthly Salary: " << monthlySalary << endl;
        cout << "Tax Percentage: " << taxPercentage << "%" << endl;
        cout << "Salary after tax: " << Salary_after_tax() << endl;
    }
};

int main() {
    Employee emp;
    
    emp.get_data();
    emp.display();
    emp.update_tax_percentage();
    
    return 0;
}
