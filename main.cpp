#include <iostream> 
#include "coordinates.h" 
#include "board.h" 
#include "piece.h" 

using namespace std;
int main() {
    Coordinates **mvs_1; 
    int num_mvs; 

    Board t1(8, "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr"); 

    num_mvs = t1.getSquares()[1].getPiece()->possibleMoves(mvs_1);
    cout << "There are "<<num_mvs <<" possible moves" << endl;
    cout << " On the board " << "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr" << endl;
    cout << "From the current position " << t1.getSquares()[1].getCoordinates() <<endl;
    for (int i = 0; i < num_mvs; i++)
    {
        cout << "Movs["<< i << "]:" <<*mvs_1[i] <<endl;
    }
    
    for (int i = 0; i < num_mvs; i++)
    {
        delete mvs_1[i];
    }
    free (mvs_1);

    return 0;
    
}
