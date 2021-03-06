#include "Piece.h"

/**
 * Default constructor. Sets the piece type.
 * 
 * \param set_type tpe of the piece
 */
Piece::Piece(unsigned set_type)
{
    this->type = set_type;
}
Piece::Piece() {
    this->type = 0U;
}

int Piece::set_piece_type(unsigned t)
{
    this->type = t;
    return t;
}

unsigned Piece::get_type()
{
    return this->type;
}

bool Piece::is_white()
{
    return (this->type % 2 == 1);
}

bool Piece::is_black()
{
    return (!this->is_white()) && (this->type > 0);
}

bool Piece::is_empty()
{
    return this->get_type() == 0;
}

Piece* Piece::clone()
{
    Piece* p = new Piece(this->type);
    return p;
}


char Piece::piece_to_char()
{
    switch (this->type)
    {
    case 0:
        return ' ';
    case 1:
        return 'K';
    case 2:
        return 'k';
    case 3:
        return 'Q';
    case 4:
        return 'q';
    case 5:
        return 'R';
    case 6:
        return 'r';
    case 7:
        return 'B';
    case 8:
        return 'b';
    case 9:
        return 'N';
    case 10:
        return 'n';
    case 11:
        return 'P';
    case 12:
        return 'p';
    default:
        break;
    }
    return 'E';
}

bool Piece::is_opponent(Piece* other)
{
    return ((other->is_black() && this->is_white()) || (other->is_white() && this->is_black()));
}

bool Piece::is_team_member(Piece* other)
{
    return ((other->is_black() && this->is_black()) || (other->is_white() && this->is_white()));
}

int Piece::value() {
    switch (this->type)
    {
    case 0:
        return 0;
    case 1:
        return 100000;
    case 2:
        return 100000;
    case 3:
        return 950;
    case 4:
        return 950;
    case 5:
        return 500;
    case 6:
        return 500;
    case 7:
        return 350;
    case 8:
        return 350;
    case 9:
        return 320;
    case 10:
        return 320;
    case 11:
        return 100;
    case 12:
        return 100;
    default:
        break;
    }
    return 0;
}

Piece::~Piece()
{
}
