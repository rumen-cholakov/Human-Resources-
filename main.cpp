#include <cctype>
#include"Company.h"
#include <limits>

using namespace std;

void ShowMenu()
{
    cout << "\n\t\t*** Company ***";
    cout << "\n\tA \tAdd information for the company";
    cout << "\n\tI \tDisplay information for the company";
    cout << "\n\tE \tAdd employee";
    cout << "\n\tD \tDisplay information for an employee";
    cout << "\n\tF \tFire an employee";
    cout << "\n\tC \tChange the information for an employee";
    cout << "\n\tP \tDisplay information for the employees working on a project";
    cout << "\n\tQ \tQuit";
}

char GetAChar(char* promptString)
{
    char response;
    cout << promptString;
    cin >> response;
    response = toupper(response);
    cin.get();
    return response;
}

char Legal(char c)
{
    return	((c == 'A') || (c == 'I') || (c == 'E') || (c == 'D') ||
             (c == 'F') || (c == 'C') || (c == 'P') || (c == 'Q'));
}

char GetCommand()
{
    int stopLoop = 0;
    char cmd = GetAChar("\n\n>");
    while (!Legal(cmd))
    {
        if(stopLoop > 5)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "An error occurred!";
            return cmd = 'Q';
        }
        ++stopLoop;
        cout << "\nIllegal command, please try again . . .";
        ShowMenu();
        cmd = GetAChar("\n\n>");
    }
    return cmd;
}

int main()
{
    Company s("Rcorp", "The World", "Rake");
    //s.print();
    ShowMenu();

    char command;
    do
    {
        command = GetCommand();
        switch (command)
        {
            case 'A': s.AddInformation();       break;
            case 'I': s.print();				break;
            case 'E': s.AddPersonal();			break;
            case 'D': s.ShowEmployee(); 		break;
            case 'F': s.RemovePersonal();  	    break;
            case 'C': s.ChangeEmployeeInfo();   break;
            case 'P': s.WorkingOnProject();     break;
            case 'Q': 					        break;
        }
     } while (command != 'Q');

    return 0;
}
