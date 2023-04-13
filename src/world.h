#ifndef WORLD_H
#define WORLD_H

#define MAX_CHUNK_UPDATE_DISTANCE 20

class World {
	private:
		unsigned short _chunkUpdateDistance = 10;
	public:
		inline void setRenderDistance(unsigned short chunkUpdateDistance) {
			if(chunkUpdateDistance <= MAX_CHUNK_UPDATE_DISTANCE)	
				this->_chunkUpdateDistance = chunkUpdateDistance;
		};
		inline unsigned short getChunkUpdateDistance() {
			return this->_chunkUpdateDistance;
		};
};
#endif
