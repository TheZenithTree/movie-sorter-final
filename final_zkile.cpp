//Zenith Kile
//11/29/22
//Final Exam
/*This program reads in movie data from an input file and outputs
various sort options to the screen for the user to sort from*/

//Preprocessor Directives
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "person.h"

using namespace std;

//Classes

class movie : public virtual person {
public: 
    //Constructor -- Runs necessary function calls
    movie()
    {
        fileCheck();
        readData();
        readIn();
        favCheck();
    }

    //Sets and gets
    void setmovName(string temp)
    {
        movName.push_back(temp);
    }

    string getmovName(int a)
    {
        return movName[a];
    }

    //Used for swap function
    void specmovName(string temp, int a) // spec short for specific
    {
        movName[a] = temp;
    }

    void setyear(int temp)
    {
        year.push_back(temp);
    }

    int getyear(int a)
    {
        return year[a];
    }

    //Used for swap function
    void specyear(int temp, int a)
    {
        year[a] = temp;
    }

    void setboxGross(double temp)
    {
        boxGross.push_back(temp);
    }

    double getboxGross(int a)
    {
        return boxGross[a];
    }

    //Used for swap function
    void specboxGross(double temp, int a)
    {
        boxGross[a] = temp;
    }

    //Opens file and checks for validity
    void fileCheck()
    {
        iFile.open("input.txt");

        if (!iFile.is_open())
        {
            cout << "Input file not found.";
            exit(1);
        }
    }

    //Reads in data from the file
    void readData()
    {
        string tempS;
        double tempD;
        int tempI;

        while (!iFile.eof())
        {
            getline(iFile, tempS);
            setmovName(htmlCheck(tempS));
            

            iFile >> tempI;
            setyear(tempI);

            iFile >> tempD;
            setboxGross(tempD);
            iFile.ignore();
        }
        
    }

    //Checks if user inputted favorite movie is contained in the input file
    void favCheck()
    {
        for (int a = 0; a < 3; a++)
        {
            for (int b = 0; b < movName.size(); b++)
            {
                if (getfavMovie(a) == getmovName(b))
                {
                    cout << getfName(a) << " " << getlName(a) << "'s "
                        << "favorite movie '" << getfavMovie(a)
                        << "' is contained in the input file."
                        << endl << endl;
                }
            }
        }
    }

    //Sorts data based on input choice
    void sortData(int menuChoice)
    {
        for (int a = 0; a < movName.size(); a++)
        {
            for (int b = 0; b < movName.size() - 1; b++)
            {
                if (menuChoice == 1)
                {
                    if (getmovName(b) > getmovName(b + 1))
                        swap(b);
                }
                else if (menuChoice == 2)
                {
                    if (getyear(b) > getyear(b + 1))
                        swap(b);
                }
                else if (menuChoice == 3 || menuChoice == 4 || menuChoice == 5)
                {
                    if (getboxGross(b) > getboxGross(b + 1))
                        swap(b);
                }
            }
        }
    
    }

    //Swaps data 
    void swap(int b)
    {
        
        string tempS;
        int tempI;
        double tempD;

        tempS = getmovName(b);
        specmovName(getmovName(b + 1), b);
        specmovName(tempS, b + 1);

        tempI = getyear(b);
        specyear(getyear(b + 1), b);
        specyear(tempI, b + 1);

        tempD = getboxGross(b);
        specboxGross(getboxGross(b + 1), b);
        specboxGross(tempD, b + 1);
        
    }

    //Outputs menu to screen
    void menu()
    {
        int menuChoice;

        cout << "Please select one of the options below." << endl;
        cout << "1. Sort on Movie Name" << endl;
        cout << "2. Sort on Year" << endl;
        cout << "3. Sort on Box Office Gross" << endl;
        cout << "4. Display highest grossing movie's info" << endl;
        cout << "5. Display lowest grossing movie's info" << endl;
        cout << "6. Exit Program" << endl;
        cout << "Enter your choice here: ";
        cin >> menuChoice;
        cout << endl;

        if (menuChoice == 6)
        {
            cout << "Thank you for using our program.";
            exit(0);
        }
        else if (menuChoice == 1 || menuChoice == 2 || menuChoice == 3 || menuChoice == 4 || menuChoice == 5)
        {
            sortData(menuChoice);
            output(menuChoice);
        }
        else
        {
            cout << "You did not choose one of the options presented." << endl;
            cout << "Please run the program again." << endl;
            exit(0);
        }
    }

    //Outputs selection to the screen with results
    void output(int menuChoice)
    {
        int repeat;

        cout << "You chose menu option " << menuChoice << endl;
        cout << "Here are your results." << endl;
        cout << showpoint << fixed << setprecision(2);

        if (menuChoice == 1 || menuChoice == 2 || menuChoice == 3)
        {
            for (int a = 0; a < movName.size(); a++)
            {
                cout << getmovName(a) << " (" << getyear(a) << ", $" << getboxGross(a) << ")   " << endl;
            }

            cout << endl;
        }

        else if (menuChoice == 4)
        {
            cout << "The highest grossing movie is: " << getmovName((movName.size()-1))
                << " (" << getyear((movName.size() - 1)) << ", $" 
                << getboxGross((movName.size() - 1)) << ")   ";
            cout << endl << endl;
        }

        else if (menuChoice == 5)
        {
            cout << "The lowest grossing movie is: " << getmovName(0)
                << " (" << getyear(0) << ", $" << getboxGross(0) << ")   ";
            cout << endl << endl;
        }

        cout << "Would you like to run the program again?" << endl;
        cout << "Enter 1 for yes. Enter 2 for no." << endl;
        cout << "Selection: ";
        cin >> repeat;

        if (repeat == 1)
        {
            system("cls");
            menu();
        }

        else
        {
            cout << endl;
            cout << "You have either chosen to exit the program or entered an incorrect value." << endl;
            cout << "Thank you for using our program.";
            cout << endl;
            exit(0);
        }
    }


private: 
    vector <string> movName;
    vector <int> year;
    vector <double> boxGross;
    ifstream iFile;
        
};

//Function Declarations

//Main Function
int main()
{
    movie user;

    user.menu();

    return 0;
}

//Function Definitions

