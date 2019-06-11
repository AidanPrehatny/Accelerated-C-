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
    string name = "";
    cin >> name;
 
    // ask user to provide the padding between frame border and greeting message
    cout << "Please specify an integer padding value: ";
    int inPad = 0;
    cin >> inPad;
 
    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";
 
    // build the constant padding parameters
    const int pad = inPad; // padding
 
    // compute the number of rows to write
    const int rows = ( pad * 2 ) + 3;
 
    // compute the number of columns to write
    const string::size_type cols = greeting.size() + ( pad * 2 ) + 2;
 
    // build the padding string that lives on the same row as the greeting, between the greeting and the border.
    const string padStringLeftRight( pad, ' ' );
 
    // build the padding string that lives between the top (or bottom) border and and greeting.
    const string padStringTopBottom( ( cols - 2 ) , ' ' );
 
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
            // Are we at the exact position where the greeting should start?
            if ( ( r == pad + 1 ) && ( c == pad + 1 ) )
            {
                // output the greeting message
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
                    // output the border asterisks
                    cout <<  "*";
                    ++c;
                }
                else
                {
                    // are we on the greeting line?
                    if ( r == pad + 1)
                    {
                        // output the empty spaces between left (or right) border and the greeting
                        cout << padStringLeftRight;
                        c += padStringLeftRight.size();
                    }
 
                    else
                    {
                        // output the empty spaces between top (or bottom) border and the greeting
                        cout << padStringTopBottom;
                        c += padStringTopBottom.size();
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}