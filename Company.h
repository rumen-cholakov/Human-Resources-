#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"

class Company
{
    public:
        Company();
        Company(string name, string addres, string ceo);
        ~Company();

        void AddInformation();
        void AddPersonal();
        void RemovePersonal();
        void ShowEmployee();
        void ChangeEmployeeInfo();
        void WorkingOnProject();

        void print() const;

        string Getname() const { return name; }
        void Setname(string val) { name = val; }

        string Getaddress() const { return address; }
        void Setaddress(string val) { address = val; }

        string Getceo() const { return ceo; }
        void Setceo(string val) { ceo = val; }

    private:
        int searchEmployee(string emp);
        bool searchProject(string pro, int i);
        string name;
        string address;
        string ceo;
        vector<Employee*> c_personal;
};

#endif // COMPANY_H
