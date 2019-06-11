#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::string;

static int numRows = 6;
static int numCols = 10;


void createSquare(size_t &c, const int &r) {
    cout << "*";
    ++c;
}

void createRectangle(size_t &c, const int &r) {
    if ((r == 0) || (r == (numRows - 1))) {
        cout << " ";
    } else {
        cout << "*";
    }
    ++c;
}

void createTriangle(size_t &c, const int &r) {
    if (
        (c >= ((numCols - 1) / 2) - r)    // between the triangle left edge
        && (c <= ((numCols - 1) / 2) + r) // and the triangle right edge
    )
    {
        cout << "*";
        ++c;
    }
    else
    {
        cout << ' ';
        ++c;
    }
}

int main()
{
    cout << "Type a shape to print out" << std::endl;

    string option;
    cin >> option;

    // invariant: we have written r rows so far
    for (int r = 0; r != numRows; ++r)
    {
        string::size_type c = 0;
        // invariant: we have written c characters so far in the current row
        while (c != numCols)
        {
            if (option == "triangle")
            {
                createTriangle(c, r);
            } else if (option == "square") {
                createSquare(c, r);
            } else if (option == "rectangle") {
                createRectangle(c, r);
            } else {
                cout << "invalid option" << std::endl;
                return 1;
            }
        }
        cout << std::endl;
    }
    return 0;
}
