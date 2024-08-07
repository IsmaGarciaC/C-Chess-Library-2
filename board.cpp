#include "board.h"
#include "piece.h"

const string Square::NAME_BLACK = "black";
const string Square::NAME_WHITE = "white";
const string Square::NAME_NO_COLOR = "*";

Square::Square() : coordinates('a', 1), color(NAME_NO_COLOR), piece(nullptr) {} // Default constructor initializing coordinates, color, and piece

Square::Square(Coordinates crdns, string clr, Piece *pp) : coordinates(crdns), color(clr), piece(pp) {} // Constructor initializing member variables

Square::~Square() {} // Destructor

void Square::setCoordinatesColor(char column, int row)
{
    coordinates.setColumn(column); // Setting the column of the coordinates
    coordinates.setRow(row);       // Setting the row of the coordinates
    if ((column - 'a' + row) % 2 == 0)
        color = NAME_WHITE; // Setting the color to white if the sum of column index and row is even
    else
        color = NAME_BLACK; // Setting the color to black if the sum of column index and row is odd
}

void Square::setColor(string clr)
{
    color = clr; // Set the color of the square
}

void Square::setPiece(Piece *pp)
{
    piece = pp; // Set the piece on the square
}

Coordinates Square::getCoordinates()
{
    return coordinates; // Return the coordinates of the square
}

char Square::getColumn()
{
    return coordinates.getColumn(); // Return the column of the square
}

int Square::getRow()
{
    return coordinates.getRow(); // Return the row of the square
}

string Square::getColor()
{
    return color; // Return the color of the square
}

Piece *Square::getPiece()
{
    return piece; // Return the piece on the square
}

Board::Board() : numRows(8), numColumns(8)
{
    squares = new Square[numRows * numColumns];
    for (int r = 0; r < numRows; ++r)
    {
        for (int c = 0; c < numColumns; ++c)
        {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1); // Set coordinates and color of each square
        }
    }
}

Board::Board(int dim) : numRows(dim), numColumns(dim)
{
    squares = new Square[numRows * numColumns];
    for (int r = 0; r < numRows; ++r)
    {
        for (int c = 0; c < numColumns; ++c)
        {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1); // Set coordinates and color of each square
        }
    }
}

Board::Board(int dim, string array_char_position) : numRows(dim), numColumns(dim)
{
    squares = new Square[numRows * numColumns];
    for (int r = 0; r < numRows; ++r)
    {
        for (int c = 0; c < numColumns; ++c)
        {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1); // Set coordinates and color of each square
            char pieceChar = array_char_position[r * numColumns + c];        // Get the piece character from the array
            if (pieceChar != '-')
            {
                string pieceColor = isupper(pieceChar) ? Piece::NAME_WHITE : Piece::NAME_BLACK; // Determine the color of the piece
                Piece *newPiece = nullptr;                                                      // Pointer to the new piece
                switch (tolower(pieceChar))
                {
                case 'p':
                    newPiece = new Pawn("Pawn", squares[r * numColumns + c].getCoordinates(), pieceColor, this);
                    break;
                case 'n':
                    newPiece = new Knight("Knight", squares[r * numColumns + c].getCoordinates(), pieceColor, this);
                    break;
                    // Add other pieces (e.g., rook, bishop, queen, king) as needed
                }
                if (newPiece)
                {
                    squares[r * numColumns + c].setPiece(newPiece); // Set the piece on the square
                }
            }
        }
    }
}

Board::~Board()
{
    delete[] squares;
}

void Board::setNumRows(int rws)
{
    numRows = rws; // Set the number of rows
}

void Board::setNumColumns(int clmns)
{
    numColumns = clmns; // Set the number of columns
}

int Board::getNumRows()
{
    return numRows;
}

int Board::getNumColumns()
{
    return numColumns;
}

Square *Board::getSquares()
{
    return squares;
}

Piece *Board::pieceEn(char column, int row)
{
    return squares[(row - 1) * numColumns + (column - 'a')].getPiece(); // Return the piece at the specified column and row
}

Piece *Board::pieceEn(Coordinates *position)
{
    return squares[(position->getRow() - 1) * numColumns + (position->getColumn() - 'a')].getPiece(); // Return the piece at the specified coordinates
}
