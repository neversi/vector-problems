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
    std::string buff_line;
    while (is >> buffer_employee) {
        employees.push_back(buffer_employee);
    }

    // read all of the employees from provided is, think of is like std::cin
    // by the way, you can use >> on Employee, like std::cin >> buffer_employee
    // but you will need to do it on is
    

    return employees;
}

int main() {
    std::srand((unsigned)time(0));
    std::ifstream file("input.txt");
    auto employees = read_all_employees(file);
    // shuffle them
    // cut last 20 employees
    // count which department has more employees
    // output <department> has more employees
    std::random_shuffle(employees.begin(), employees.end());
    for (size_t i = 0; i < 20; ++i) {
        employees.pop_back();
    }
    // Counting the number of each departments' employees
    std::vector<std::pair<std::string, int>> departments;
    bool is_exist = false;
    size_t temp;
    for (size_t i = 0; i < employees.size(); ++i) {
        for (size_t j = 0; j < departments.size(); ++j) { 
            if (departments[j].first == employees[i].department) {
                is_exist = true;
                temp = j;
            }
        }
        if (!is_exist) {
                departments.push_back(std::make_pair(employees[i].department, 1));
            } else {
                departments[temp].second++;
            }
            is_exist = false;
    }
    std::sort(departments.begin(), departments.end(), [] (const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {return a.second > b.second;});
    for (auto name: departments) {
        std::cout<< name.first<< ": "<<name.second << "\n";
    }
    std::cout << departments[0].first <<" has more employees";
    return 0;
}
