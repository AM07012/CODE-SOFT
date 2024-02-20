#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() 
{
    srand(static_cast<unsigned int>(time(0)));
    int RandomNumber = rand() % 10 + 1;
    int userGuess = 0;
    while (userGuess != RandomNumber) 
	{
        cout<<"Guess the number between 1 and 10:";
        cin>>userGuess;
        if (userGuess<RandomNumber) {
            cout<<"Too low! try again."<<endl;
        } else if (userGuess>RandomNumber) {
            cout<<"Too high! try again."<<endl;
        } else {
            cout<<"You guessed the correct number,"<<RandomNumber<<endl;
        }
    }
    return 0;
}
