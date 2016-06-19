#include "Employee.h"

Employee::Employee()
{
}

Employee::Employee(string cname, string cegn, string caddress, string cdstart, string csupervisor, position cpos, string cproject, string cos)
{
    this->name = cname;
    this->egn = cegn;
    this->address = caddress;
    this->dateStart = cdstart;
    this->supervisor = csupervisor;
    this->e_position = cpos;
    this->project = cproject;
    switch(cpos)
    {
        case 0: this->os = "";
                break;
        case 1: this->os = cos;
                break;
        case 2: this->os = cos;
                break;
    }

}

void Employee::SetPosition(string val)
{
    if (val == "junior programmer")
    {
        this->e_position = junior_programmer;
    }
    else if (val == "junior tester")
    {
        this->e_position = junior_tester;
    }
    else if (val == "senior programmer")
    {
        this->e_position = senior_programmer;
    }
}

void Employee::print() const
{
    cout << this->name << endl;
    cout << this->egn << endl;
    cout << this->address << endl;
    cout << this->dateStart << endl;
    cout << this->supervisor << endl;
    switch(this->e_position)
    {
        case 0: cout << "junior programmer" << endl;
                break;
        case 1: cout << "junior tester" << endl;
                break;
        case 2: cout << "senior programmer" << endl;
                break;
    }
    cout << this->project << endl;
    cout << this->os << endl;
}





















