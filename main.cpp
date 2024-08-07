#include <iostream> 
#include "coordinates.h" 
#include "board.h" 
#include "piece.h" 

using namespace std;
int main() {
    Coordinates **mvs_1; 
    int num_mvs; 

    Board t1(8, "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr"); 

    Piece *piece = t1.getSquares()[1].getPiece(); // Getting the piece at a specific position in this case the knight at b1
    if (piece) {
        num_mvs = piece->possibleMoves(mvs_1); // Getting the possible moves for the piece
        cout << "There are " << num_mvs << " possible moves for the knight" << endl; // Printing the number of possible moves
        cout << "On the board: RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr" << endl;
        cout << "From the current position: " << piece->getPosition() << endl; // Printing the current position of the piece
        for (int i = 0; i < num_mvs; i++) {
            cout << "Move[" << i << "]: " << *mvs_1[i] << endl; // Printing each possible move
        }

        for (int i = 0; i < num_mvs; i++) {
            delete mvs_1[i]; // Delete each Coordinates object
        }
        delete[] mvs_1; // Delete the array of Coordinates pointers
    } else {
        cout << "No piece found at the specified position." << endl; // Print a message if no piece is found
    }

    return 0; 
}
