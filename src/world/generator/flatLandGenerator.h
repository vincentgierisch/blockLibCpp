#ifndef FLAT_WORLD_GENERATOR_H
#define FLAT_WORLD_GENERATOR_H

#include "../chunk.h"
#include "../blockType.h"

class FlatLandGenerator {
	private:
		void generateTree(Chunk& chunk, glm::vec3 coords, int treeHeight);
	public:
		void generateTerrain(Chunk& chunk);
};
#endif
