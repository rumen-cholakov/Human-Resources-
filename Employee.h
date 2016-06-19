#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

enum position {junior_programmer, junior_tester, senior_programmer};

class Employee
{
    public:
        Employee();
        Employee(string name, string egn, string address, string dstart, string supervisor, position pos, string project, string os);

        string GetName() const { return name; }
        void SetName(string val) { name = val; }

        string GetEgn() const { return egn; }
        void SetEgn(string val) { egn = val; }

        string GetAddress() const { return address; }
        void SetAddress(string val) { address = val; }

        string GetDateStart() const { return dateStart; }
        void SetDateStart(string val) { dateStart = val; }

        string GetSupervisor() const { return supervisor; }
        void SetSupervisor(string val) { supervisor = val; }

        position GetPosition() const { return e_position; }
        void SetPosition(string val);

        string GetProject() const { return project; }
        void SetProject(string val) { project = val; }

        string GetOs() const { return os; }
        void SetOs(string val) { os = val; }

        void print() const;

    private:
        string name;
        string egn;
        string address;
        string dateStart;
        string supervisor;
        position e_position;
        string project;
        string os;
};

#endif // EMPLOYEE_H
