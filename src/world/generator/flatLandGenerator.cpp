#include "flatLandGenerator.h"


void FlatLandGenerator::generateTerrain(Chunk& chunk) {
    srand((unsigned) time(NULL));
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

    int numbOfTrees = 3;
    for (int i = 0; i < numbOfTrees; ++i) {
        int randX = rand() % 16;
        int randZ = rand() % 16;

        this->generateTree(chunk, {randX, 4, randZ}, 6);
    }
}

void FlatLandGenerator::generateTree(Chunk& chunk, glm::vec3 coords, int treeHeight) {
    // trunk
    for (int i = 1; i <= treeHeight; ++i){
        chunk.addBlock({coords.x, coords.y+i, coords.z}, BlockType::Dirt);
    }
    // leaves
    chunk.addBlock({coords.x+1, coords.y+treeHeight, coords.z-1}, BlockType::Leaves);
    chunk.addBlock({coords.x+1, coords.y+treeHeight, coords.z}, BlockType::Leaves);
    chunk.addBlock({coords.x+1, coords.y+treeHeight, coords.z+1}, BlockType::Leaves);
    chunk.addBlock({coords.x, coords.y+treeHeight, coords.z+1}, BlockType::Leaves);
    chunk.addBlock({coords.x-1, coords.y+treeHeight, coords.z+1}, BlockType::Leaves);
    chunk.addBlock({coords.x-1, coords.y+treeHeight, coords.z}, BlockType::Leaves);
    chunk.addBlock({coords.x-1, coords.y+treeHeight, coords.z-1}, BlockType::Leaves);
    chunk.addBlock({coords.x, coords.y+treeHeight, coords.z-1}, BlockType::Leaves);
    chunk.addBlock({coords.x, coords.y+treeHeight+1, coords.z}, BlockType::Leaves);
}