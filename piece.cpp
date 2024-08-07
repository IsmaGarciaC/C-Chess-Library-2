#include "piece.h" // Include the piece header file
#include <iostream> 

const string Piece::NAME_BLACK = "black"; 
const string Piece::NAME_WHITE = "white"; 
const string Piece::NAME_NO_COLOR = "*"; 

Piece::Piece(string name, Coordinates position, string color, Board *board)
    : name(name), position(position), color(color), board(board), value(0) {} // Constructor initializing variables

Piece::~Piece() {} // Destructor

void Piece::move(Coordinates finalPosition) {
    position = finalPosition; // Moving the piece to the final position
}

Coordinates Piece::getPosition() const {
    return position; // Returning the current position of the piece
}

ostream &operator<<(ostream &os, const Piece &p) {
    os << p.name << " at " << p.position << " (" << p.color << ")"; // Output format
    return os; // Returning the output
}

Knight::Knight(string name, Coordinates position, string color, Board *board)
    : Piece(name, position, color, board) {
    value = 3; // Setting the value of the knight
}

int Knight::possibleMoves(Coordinates **&arrayMoves) {
    // Knight moves: 8 possible moves
    static const int moveOffsets[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}}; //Aqui puede ser la causa de uno de los errores!!

    arrayMoves = new Coordinates *[8]; // 8 possible moves
    int count = 0; 

    for (int i = 0; i < 8; ++i) {
        char newCol = position.getColumn() + moveOffsets[i][0]; // Calculate the new column
        int newRow = position.getRow() + moveOffsets[i][1]; // Calculate the new row

        cout << "Checking move: newCol = " << newCol << ", newRow = " << newRow << std::endl; 

        if (newCol >= 'a' && newCol <= 'h' && newRow >= 1 && newRow <= 8) {
            Coordinates *newMove = new Coordinates(newCol, newRow); // Creating a new Coordinates object
            arrayMoves[count++] = newMove; // Adding the valid move to the array
        }
    }

    return count; // Returning the valid moves
}
