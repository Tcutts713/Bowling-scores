// Bowling for Scores.cpp : This program reads from a file BowlingScores.txt and makes builds up an array of players from the structure Scores and from the file.  This program will also calculate the average of the players
// scores and store that into an array.   THe last function out puts the players name, their scores and then what they averaged.
// Tim Cutts    Programming assignment Week 7 modified to for GITHUB assignment

#include <iostream> //to use input and output
#include <string> //to use strings
#include <fstream> //to write and to read from files
#include <iomanip> //to format lines and fills

using namespace std; //to not type std::

const int NUMROWS = 10; //Declaring global variables for rows and columns
const int NUMCOLS = 5;



struct Scores //delcaring structure and its variables
{
    string playerName;
    int playerScores[NUMCOLS];
    int playerAvg;
};




int GetBowlingData(Scores playerlist[]) //function to get the data from the file
{                                                          

    ifstream inFile; //variable for file

    inFile.open("BowlingScores.txt"); //open file
    if (!inFile) //checks to see if file opens and if it does not out puts an error
    {
        cout << "Error with file." << endl;
        return -1;
    }

    for (int row = 0; row < NUMROWS; row++) //for loop to get data for the rows
    {
        inFile >> playerlist[row].playerName;
        for (int c = 0; c < NUMCOLS; c++) //for loop to get data for scores
            inFile >> playerlist[row].playerScores[c];

    }
    return 0;

}

void GetAverageScore(Scores playerlist[]) //function to get the average score for each player
{                                                                                         
    int sum;//variables so we can find the average
    double average;


    for (int row = 0; row < NUMROWS; row++) //for loop to jump throught the rows
    {
        sum = 0; //setting sum to 0 for every loop
        for (int col = 0; col < NUMCOLS; col++) //for loop to read the data from the columns in each row
        {
            sum += playerlist[row].playerScores[col]; //totals up the scores for each row
        }
        average = sum / NUMCOLS; //averages each rows total
        playerlist[row].playerAvg = static_cast<int>(average); //stores averages scores in their own array.  Set to be int for cleaner averages
    }
}

void PrettyPrintResults(Scores playerlist[]) //This function outputs the names, scores and averages to the console
{                                                                                                                        
    cout << "\n" << endl; //new line space
    cout << setw(42) << setfill('~') << "" << endl; //decorative line filled with ~
    cout << setw(30) << setfill('>') << " Bowling Score Cards " << setw(12) << setfill('<') << "" << endl; //decorative line with title and > <
    cout << setw(42) << setfill('~') << "" << endl; //decorative line filled with ~
    cout << "\n" << endl;

    cout << setw(40) << setfill('*') << endl; //line to display 40 '*'s to the console
    cout << "\n" << endl;//new line space

    for (int row = 0; row < NUMROWS; row++)//for loop to read through the rows
    {
        cout << playerlist[row].playerName << "'s scores are: "; //outputs the players name
        for (int col = 0; col < NUMCOLS; col++)//for loop to read throught the columns in each row
        {
            cout << playerlist[row].playerScores[col] << " ";//outputs the scores for players
        }
       cout << "\n" << endl; //new line space
       cout << playerlist[row].playerName << " had an average score of : " << playerlist[row].playerAvg << endl; //for each player outputs their average score
       cout << setw(40) << setfill('*') << endl; //line to display 40 '*'s to the console
       cout << "\n" << endl; //new line space
    }
}




int main() //main
{
    Scores playerlist[NUMROWS]; //declaring our number of players

    GetBowlingData (playerlist); //calling function GetBowlingData

    GetAverageScore(playerlist); //calling function GetAverageScore 

    PrettyPrintResults(playerlist); //calling function PrettyPrintResults

    return 0;

}
