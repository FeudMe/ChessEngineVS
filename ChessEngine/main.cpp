#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif 
#include "board.h"
#include "movegen.h"
#include "search.h"
#include <chrono>
#include <iostream>



using namespace std;
using namespace std::chrono;
/**
 * @brief Runs the program
 *
 * @param argc number of command line arguments
 * @param argv array of command line arguments
 * @return int
 */

void perft(Board* b, int depth);
void search(Board* b, int depth);
void uci_console();

int main(int argc, char** argv)
{
	Board* board = new Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
	perft(board, 3);
	search(board, 3);
	delete board;
	


	_CrtDumpMemoryLeaks();
	return 0;
}

void perft(Board* b, int depth) {
	std::list<Board*>* moves = b->possible_moves();
	int total = 0;
	for (Board* const& move : *moves) {
		Movegen* gen = new Movegen(move);
		int num_moves = gen->generate_moves(depth - 1);
		total += num_moves;
		std::cout << move->get_last_move() << ": " << num_moves << std::endl;
		delete gen;
	}
	for (Board* const& move : *moves) {
		delete move;
	}
	std::cout << "Nodes searched: " << total << std::endl;
	std::cout << std::endl;
	delete moves;
}

void search(Board* b, int depth) {
	Search* s = new Search();
	s->evaluate_iterative_deepening(b, depth);
	delete s;
}

void uci_console() {
	Board* board = new Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");


	delete board;
}
