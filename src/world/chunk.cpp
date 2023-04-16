#include "chunk.h"

Chunk::Chunk() {
    this->_blocks.fill(BlockType::Air);
};

void Chunk::addBlock(glm::vec3 coords, BlockType block){
    this->_blocks.at(coords.y * (CHUNK_SIZE*CHUNK_SIZE) + coords.z*CHUNK_SIZE + coords.x) = block;
    this->_numberOfBlocks++;
    //this->_mesh.updateMesh(block, coords, this->_numberOfBlocks++, this);
};

void Chunk::generateMesh() {
    for(unsigned int i = 0; i < this->_blocks.size(); ++i) {
        int x = i % CHUNK_SIZE;
        int y = i / (CHUNK_SIZE * CHUNK_SIZE);
        int z = (i / CHUNK_SIZE) % CHUNK_SIZE;
        glm::vec3 coords = {x, y, z};
        // check which "fac.x << " | "e" of the blockcoords.z << " | " <<  has to be renderedcoords.y << 
        std::array<bool, 6> visibleFaces {
            !this->blockHasNeighbours(coords, 0),
            !this->blockHasNeighbours(coords, 1), // fehler
            !this->blockHasNeighbours(coords, 2),
            !this->blockHasNeighbours(coords, 3), // fehler
            !this->blockHasNeighbours(coords, 4),
            !this->blockHasNeighbours(coords, 5)
        };

        bool isVisible = false;
        for(bool isFaceVisible : visibleFaces) {
            isVisible = isVisible || isFaceVisible;
        }
        isVisible = true;
        if (isVisible)
            this->_mesh.updateMesh(*this->getBlockByCoords(coords), coords, visibleFaces, this->_numberOfBlocks);
    }
};

void Chunk::updateMesh(glm::vec3& coords, BlockType block) {
    // if block is modified
    // -> update new block
    // check if new block is transparent(e.g. air, water) -> update surrounding blocks
}

bool Chunk::blockHasNeighbours(glm::vec3& coords, short face) {
    if (face == 0) {
        if (coords.y + 1 < CHUNK_HEIGHT) {
            glm::vec3 newCoords = {coords.x, coords.y+1, coords.z};
            return *this->getBlockByCoords(newCoords) != BlockType::Air;
        }
    } else if (face == 1) {
        if (coords.x > 0) {
            glm::vec3 newCoords = {coords.x-1, coords.y, coords.z};
            return *this->getBlockByCoords(newCoords) != BlockType::Air;
        }
    } else if (face == 2) {
        if (coords.z + 1 < CHUNK_SIZE) {
            glm::vec3 newCoords = {coords.x, coords.y, coords.z+1};
            return *this->getBlockByCoords(newCoords) != BlockType::Air;
        }
    } else if (face == 3) {
        if (coords.x + 1 < CHUNK_SIZE) {
            glm::vec3 newCoords = {coords.x+1, coords.y, coords.z};
            return *this->getBlockByCoords(newCoords) != BlockType::Air;
        }
    } else if (face == 4) {
        if (coords.z > 0) {
            glm::vec3 newCoords = {coords.x, coords.y, coords.z-1};
            return *this->getBlockByCoords(newCoords) != BlockType::Air;
        }
    } else if (face == 5) {
        if (coords.y > 0) {
            glm::vec3 newCoords = {coords.x, coords.y-1, coords.z};
            return *this->getBlockByCoords(newCoords) != BlockType::Air;
        }
    }



    return false;
};
