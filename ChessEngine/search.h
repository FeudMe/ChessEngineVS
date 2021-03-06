#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>

#include "board.h"
#include "piece.h"
#include "evaluator.h"
#include "utility.h"

#include <chrono>
#include <atomic>
#include <thread>

constexpr int EVAL_SCORE_CUTOFF = 900000;
constexpr int MATE_IN_ZERO = 1000000;
constexpr int NO_VALUE = 2000000;

class Search
{
public:
	Search();
	int node_count = 0;
	int evaluate(Board* pos, unsigned int depth);
	int search_depth = 0;

	std::atomic<bool> stop_now = false;
	bool reduced = false;
	bool extended = false;
	bool active_zero_window = false;
	std::chrono::milliseconds start_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	std::chrono::milliseconds duration = std::chrono::milliseconds(INT32_MAX);

	std::vector<Move*>* prev_pv = new std::vector<Move*>();
	std::vector<std::vector<Move*>*>* killer_moves = new std::vector<std::vector<Move*>*>();
	
	int alpha_beta(Board* pos, int alpha, int beta, unsigned int depth_left, std::list<Move*>* PV, int ply, bool left_most);
	int quiescence(Board* pos, int alpha, int beta, int ply);
	int evaluate_iterative_deepening(Board* pos, unsigned int depth);
	int evaluate_iterative_deepening_time(Board* pos, int ms);
	bool swap_first = true;
	~Search();
};
