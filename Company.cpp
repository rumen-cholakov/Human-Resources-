#include "Company.h"
#include <limits>
Company::Company()
{
}

Company::Company(string name, string address, string ceo)
{
    this->name = name;
    this->address = address;
    this->ceo = ceo;
}

Company::~Company()
{
    for (int i = 0;i < this->c_personal.size() ;i++ )
    {
        delete c_personal[i];
    }
}

int Company::searchEmployee(string emp)
{
    for (int i = 0;i < this->c_personal.size() ;i++ )
    {
        if ( emp == this->c_personal[i]->GetEgn()) return i;
    }
    return -1;
}

bool Company::searchProject(string pro, int i)
{
    if ( pro == this->c_personal[i]->GetProject())
        return true;

    return false;
}

void Company::print() const
{
    cout << "Name of the company: ";
    cout << this->name << endl;
    cout << "Address of the company: ";
    cout << this->address << endl;
    cout << "Name of the CEO of the company: ";
    cout << this->ceo << endl;
}

void Company::AddInformation()
{
    string n;
    cout << "Name of the company: ";
    getline(cin, n);
    this->name = n;
    string ad;
    cout << "Address of the company: ";
    getline(cin, ad);
    this->address = ad;
    string ceo;
    cout << "Name of the CEO of the company: ";
    getline(cin, ceo);
    this->ceo = ceo;
}

void Company::AddPersonal()
{
    string name;
    cout << "Name: ";
    getline(cin, name);
    string egn;
    cout << "EGN: ";
    getline(cin, egn);
    string address;
    cout << "Address: ";
    getline(cin, address);
    string dstart;
    cout << "Date of beginning of work: ";
    getline(cin, dstart);
    string supervisor;
    cout << "Supervisor: ";
    getline(cin, supervisor);

    int pos, counter = 5;
    do
    {
        cout << "Enter the code corresponding to the position\njunior programmer - 0;"
             << "\njunior tester - 1;\nsenior programmer - 2;\n\>";
        cin >> pos;
        if(pos == 0 || pos == 1 || pos == 2) break;

        counter--;
        if(counter == 0)
        {
            cout << "Too many invalid inputs! Please try again!";
            return;
        }
    } while (counter);

    if (!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid inputs! Please try again!";
        return;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string project;
    cout << "Name of project: ";
    getline(cin, project);
    position pos1;
    string os = "";
    if (pos == 0)
    {
         pos1 = junior_programmer;
    }
    else if (pos == 1)
    {
        pos1 = junior_tester;
        cout << "Name of OS: ";
        getline(cin, os);
    }
    else if (pos == 2)
    {
        pos1 = senior_programmer;
        cout << "Name of OS: ";
        getline(cin, os);
    }

    Employee* p = new Employee(name, egn, address, dstart, supervisor, pos1, project, os);
    c_personal.push_back(p);
}

void Company::RemovePersonal()
{
    string egn;
    cout << "Please input the EGN of the employee who will be fired!\nEGN: ";
    getline(cin, egn);
    int sr = this->searchEmployee(egn);
    if (sr == -1)
    {
        cout << "No employee found!\n";
    }
    else
    {
        delete c_personal[sr];
        c_personal.erase(c_personal.begin()+sr);
    }
}

void Company::ShowEmployee()
{
    string egn;
    cout << "Please input the EGN of the employee whose information should be displayed!\nEGN: ";
    getline(cin, egn);
    int sr = this->searchEmployee(egn);
    if (sr == -1)
    {
        cout << "No employee found!\n";
    }
    else
    {
        c_personal[sr]->print();
    }
}

void Company::ChangeEmployeeInfo()
{
    string egn;
    cout << "Please input the EGN of the employee whose information should be displayed!\nEGN: ";
    getline(cin, egn);
    int sr = this->searchEmployee(egn);
    if (sr == -1)
    {
        cout << "No employee found!\n";
    }
    else
    {
        string name;
        cout << "Name: ";
        getline(cin, name);

        string egn;
        cout << "EGN: ";
        getline(cin, egn);

        string address;
        cout << "Address: ";
        getline(cin, address);

        string dstart;
        cout << "Date of beginning of work: ";
        getline(cin, dstart);

        string supervisor;
        cout << "Supervisor: ";
        getline(cin, supervisor);


        int pos, counter = 5;
        do
        {
            cout << "Enter the code corresponding to the position\njunior programmer - 0;"
                 << "\njunior tester - 1;\nsenior programmer - 2;\n\>";
            cin >> pos;
            if(pos == 0 || pos == 1 || pos == 2) break;

            counter--;
            if(counter == 0)
            {
                cout << "Too many invalid inputs! Please try again!";
                return;
            }
        } while (counter);
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid inputs! Please try again!";
            return;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string project;
        cout << "Name of project: ";
        getline(cin, project);
        position pos1;
        string os = "";
        if (pos == 0)
        {
             c_personal[sr] -> SetPosition("junior programmer");
        }
        else if (pos == 1)
        {
            c_personal[sr] -> SetPosition("junior tester");
            cout << "Name of OS: ";
            getline(cin, os);
        }
        else if (pos == 2)
        {
            c_personal[sr] -> SetPosition("senior programmer");
            cout << "Name of OS: ";
            getline(cin, os);
        }
        c_personal[sr]->SetName(name);
        c_personal[sr]->SetEgn(egn);
        c_personal[sr]->SetAddress(address);
        c_personal[sr]->SetDateStart(dstart);
        c_personal[sr]->SetSupervisor(supervisor);
        c_personal[sr]->SetProject(project);
        c_personal[sr]->SetOs(os);
    }
}

void Company::WorkingOnProject()
{
    string project;
    cout << "Please input the name of the project!\nProject: ";
    getline(cin, project);

    for (int i = 0;i < c_personal.size() ;i++ )
        if (searchProject(project, i))
            c_personal[i]->print();
}


















