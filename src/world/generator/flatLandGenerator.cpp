#include "flatLandGenerator.h"


void FlatLandGenerator::generateTerrain(Chunk& chunk) {
    // chunk.addBlock({0, 0, 0}, BlockType::Grass);
    // chunk.addBlock({0, 0, 3}, BlockType::Stone);
    // return;
    for (int x = 0; x < 16; ++x)
        for (int z = 0; z < 16; ++z) {
            chunk.addBlock({x, 0, z}, BlockType::Stone);
            chunk.addBlock({x, 1, z}, BlockType::Dirt);
            chunk.addBlock({x, 2, z}, BlockType::Dirt);
            chunk.addBlock({x, 3, z}, BlockType::Dirt);
            chunk.addBlock({x, 4, z}, BlockType::Grass);
        }
}