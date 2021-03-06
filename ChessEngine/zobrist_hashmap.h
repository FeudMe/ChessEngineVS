#pragma once
#include <stdint.h>
#include <unordered_map>

#include "utility.h"
#include "hash_entry.h"

class zobrist_hashmap
{
public:
	zobrist_hashmap(size_t set_size);
	~zobrist_hashmap();
	hash_entry* map;
	size_t size;
	size_t count;

    int probe_hash(uint64_t z_key, int depth_left, int ply, int alpha, int beta);
	void record_hash(uint64_t set_z_key, int set_depth_left, int set_ply, int set_score, int set_flag, Move* set_move);

	Move* probe_for_prev_best_move(uint64_t z_key);

	void clear();
	static uint64_t zobrist_base_numbers[781];
	static void init_bases();
private:
};

