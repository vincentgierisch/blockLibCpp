#ifndef CHUNK_H
#define CHUNK_H

#define CHUNK_HEIGHT 32
#define CHUNK_SIZE 16

#include <array>
#include "block.h"
#include "blockType.h"
#include "chunkMesh.h"

class ChunkMesh;


class Chunk {
	private:
		unsigned int _numberOfBlocks = 0;	
		std::array<BlockType, CHUNK_HEIGHT*CHUNK_SIZE*CHUNK_SIZE> _blocks;
		ChunkMesh _mesh;
	public:
		Chunk();
		void addBlock(glm::vec3 coords, BlockType block);
		void generateMesh();
		void updateMesh(glm::vec3& coords, BlockType block);
		bool blockHasNeighbours(glm::vec3& coords, short face);
		inline unsigned int getNumberOfBlocks() {
			return this->_numberOfBlocks;
		};
		inline ChunkMesh& getMesh() {
			return this->_mesh;
		};
		inline BlockType* getBlockByCoords(glm::vec3& coords) {
			return &(this->_blocks.at(coords.y * (CHUNK_SIZE*CHUNK_SIZE) + coords.z*CHUNK_SIZE + coords.x));
		}; 
		
};
#endif
