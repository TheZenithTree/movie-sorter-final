#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class person {
public:
    //Sets and Gets
    void setfname(string temp)
    {
        fName.push_back(temp);
    }

    string getfName(int a)
    {
        return fName[a];
    }

    void setlName(string temp)
    {
        lName.push_back(temp);
    }

    string getlName(int a)
    {
        return lName[a];
    }

    void setfavMovie(string temp)
    {
        favMovie.push_back(temp);
    }

    string getfavMovie(int a)
    {
        return favMovie[a];
    }

    //Reads in data from user
    void readIn()
    {
        string tempS;
        cout << "Please enter the information of three different people "
            << "and their favorite movies." << endl;
        for (int a = 0; a < 3; a++) //3 people total
        {
            cout << "Enter person " << (a + 1) << "'s first name: ";
            getline(cin, tempS);
            setfname(htmlCheck(tempS));

            cout << "Enter person " << (a + 1) << "'s last name: ";
            getline(cin, tempS);
            setlName(htmlCheck(tempS));

            cout << "Enter person " << (a + 1) << "'s favorite movie: ";
            getline(cin, tempS);
            setfavMovie(htmlCheck(tempS));
            cout << endl;
        }
        system("cls"); //Clears screen

    }

    //Checks for html tags in the strings
    string htmlCheck(string temp)
    {
        for (int a = 0; a < temp.length(); a++)  //a=Counter variable for whole
        {
            if (temp[a] == '<') //Checks for beginning html tag
            {
                for (int b = a; b < temp.length(); b++) //b=counter variable for part
                {
                    if (temp[b] == '>') //Checks for ending html tag
                    {
                        temp.erase(a, b - a + 1); //erases "<...>" section
                        a--; //sets a back to before html tag was recognized
                        break;
                    }
                }
            }
        }

        return temp;
    }

private:
    vector <string> fName, lName, favMovie;

};
