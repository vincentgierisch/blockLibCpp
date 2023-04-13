#ifndef FLAT_WORLD_GENERATOR_H
#define FLAT_WORLD_GENERATOR_H

#include "../chunk.h"
#include "../blockType.h"

class FlatLandGenerator {
	public:
		void generateTerrain(Chunk& chunk);
};
#endif
