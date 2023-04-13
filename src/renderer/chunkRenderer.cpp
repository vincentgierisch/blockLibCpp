#include "chunkRenderer.h"

ChunkRenderer::ChunkRenderer(): _shader("res/shaders/SimpleShader.vert", "res/shaders/SimpleShader.frag") {
    
}

void ChunkRenderer::draw(ChunkMesh& chunkMesh, Camera& camera) {
    this->_shader.Activate();
    chunkMesh.getVao().Bind();

    camera.updateMatrix(45.0f, 0.1f, 100.0f);
    camera.exportMatrix(this->_shader);
    glDrawElements(GL_TRIANGLES, chunkMesh.getMesh().indices.size(), GL_UNSIGNED_INT, 0);
}