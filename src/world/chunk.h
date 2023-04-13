#ifndef CHUNK_H
#define CHUNK_H

#define CHUNK_HEIGHT 16
#define CHUNK_WIDTH 16
#define CHUNK_DEPTH 32

#include <array>
#include "block.h"
#include "blockType.h"
#include "chunkMesh.h"


class Chunk {
	private:
		unsigned int _numberOfBlocks = 0;	
		std::array<BlockType, CHUNK_HEIGHT*CHUNK_WIDTH*CHUNK_DEPTH> _blocks;
		ChunkMesh _mesh;
	public:
		void addBlock(glm::vec3 coords, BlockType block){
			this->_blocks.at(coords.y * CHUNK_HEIGHT + coords.z*(CHUNK_HEIGHT*CHUNK_HEIGHT) + coords.x) = block;
			this->_mesh.updateMesh(block, coords, this->_numberOfBlocks++, this);
		};
		inline unsigned int getNumberOfBlocks() {
			return this->_numberOfBlocks;
		};
		inline ChunkMesh& getMesh() {
			return this->_mesh;
		};
		inline BlockType* getBlockByCoords(glm::vec3 coords) {
			return &(this->_blocks.at(coords.y * CHUNK_HEIGHT + coords.z*(CHUNK_HEIGHT*CHUNK_HEIGHT) + coords.x));
		}; 
		
};
#endif
