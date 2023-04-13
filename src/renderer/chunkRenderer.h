#ifndef CHUNK_RENDERER_H
#define CHUNK_RENDERER_H

#include "../world/chunkMesh.h"
#include "../common/camera.h"

class ChunkRenderer {
	private:
		Shader _shader;
	public:
		ChunkRenderer();
		void draw(ChunkMesh& chunkMesh, Camera& camera);
};
#endif
