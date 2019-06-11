#include <iostream>
#include <string>
 
// say what standard-library names we use
using std::cin;
using std::endl;
using std::cout;
using std::string;
 
int main()
{
    // ask for the person's name
    cout << "Please enter your first name: ";
 
    // read the name
    string name;
    cin >> name;
 
    // ask user to provide the vertical padding
    cout << "Please provide integer padY (vertical padding): ";
    int inPadY;
    cin >> inPadY;
 
    // ask user to provide the horizontal padding
    cout << "Please provide integer padX (horizontal padding): ";
    int inPadX;
    cin >> inPadX;
 
    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";
 
    // build the constant padding parameters
    const int padY = inPadY; // vertical padding
    const int padX = inPadX; // horizontal padding
 
    // the number of rows to write
    const int rows = ( padY * 2 ) + 3;
 
    // the number of columns to write
    const string::size_type cols = greeting.size() + ( padX * 2 ) + 2;
 
    // write a blank line to separate the output from the input
    cout << endl;
 
    // write 'rows' rows of output
    // invariant: we have written r rows so far
    for ( int r = 0; r != rows ; ++r )
    {
        string::size_type c = 0;
 
        // invariant: we have written c characters so far in the current row
        while ( c != cols)
        {
            // is it time to write the greeting?
            if ( ( r == padY+ 1 ) && ( c == padX + 1 ) )
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                // are we on the border?
                if (
                       ( r == 0 )         // top row
                    || ( r == rows - 1 )  // or bottom row
                    || ( c == 0 )         // or left-most column
                    || ( c == cols - 1 )  // or right-most column
                   )
                {
                    cout <<  "*";
                }
                else
                {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}