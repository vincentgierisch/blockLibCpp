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

class Chunk;

class ChunkMesh {
	private:
		Mesh _mesh;
		VAO _vao;
		VBO _vbo;
		EBO _ebo;
	public:
		ChunkMesh(){};
		void updateMesh(BlockType block, glm::vec3 coords, unsigned int indexOffset, Chunk* chunk);
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