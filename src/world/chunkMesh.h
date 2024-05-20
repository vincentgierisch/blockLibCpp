#ifndef CHUNKMESH_H
#define CHUNKMESH_H

#include <glm/glm.hpp>
#include <array>

#include "../mesh.h"
#include "blockType.h"
#include "../ogl/vbo.h"
#include "../ogl/vao.h"
#include "../ogl/ebo.h"
#include "../ogl/shader.h"

class ChunkMesh {
	private:
		Mesh _mesh;
		VAO _vao;
		VBO _vbo;
		EBO _ebo;
		unsigned int _numberOfBlocks;
	public:
		ChunkMesh():_numberOfBlocks(0){};
		void updateMesh(BlockType block, glm::vec3 coords, std::array<bool, 6>& visibleFaces, unsigned int indexOffset);
		void activate();
		inline Mesh& getMesh() {
			return this->_mesh;
		};
		inline VAO& getVao() {
			return this->_vao;
		};
		inline VBO& getVbo() {
			return this->_vbo;
		};
		inline EBO& getEbo() {
			return this->_ebo;
		};
};
#endif
