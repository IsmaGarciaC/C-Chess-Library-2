#pragma once
#include <iostream>
#include <utility> // Necessary library
#include "coordinates.h"
#include "piece.h"

using namespace std;

class Square
{
   friend class Board; // Declaring Board as a friend class
 
private:
   Coordinates coordinates;
   string color;
   Piece *piece;
 
public:
   static const string NAME_BLACK;
   static const string NAME_WHITE;
   static const string NAME_NO_COLOR;
 
   void setCoordinatesColor(char column, int row);
   void setColor(string color);
   void setPiece(Piece *pp);
   Coordinates getCoordinates();
   char getColumn();
   int getRow();
   string getColor();
   Piece * getPiece();
 
   Square();
   Square(Coordinates crdns, string clr, Piece *pp);
   ~Square();
};

 class Board
{
   private:
       int numRows, numColumns;
       Square * squares;
 
   public:
       void setNumRows(int rws);
       void setNumColumns(int clmns);
 
       int getNumRows();
       int getNumColumns();
       Square *getSquares();
 
 
       Piece * pieceEn(char column, int row);
       Piece * pieceEn(Coordinates* position);
 
 
       Board();
       Board(int dim);
       Board(int dim, string array_char_position);
 
       ~Board();
};

