#include <fmt/format.h>
#include <range/v3/algorithm.hpp>

#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

struct Employee {
    std::string department;
    unsigned int id;
};

std::istream &operator>>(std::istream &is, Employee &employee) {
    is >> employee.id >> employee.department;
    return is;
}

std::vector<Employee> read_all_employees(std::istream &is) {
    std::vector<Employee> employees;
    Employee buffer_employee;
    // read all of the employees from provided is, think of is like std::cin
    // by the way, you can use >> on Employee, like std::cin >> buffer_employee
    // but you will need to do it on is
    is >> buffer_employee;

    return employees;
}

int main() {
    std::ifstream file("input.txt");
    auto employees = read_all_employees(file);
    // shuffle them
    // cut last 20 employees
    // count which department has more employees
    // output <department> has more employees
}