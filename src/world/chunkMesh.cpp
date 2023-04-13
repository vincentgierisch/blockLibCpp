#include "chunkMesh.h"

void ChunkMesh::updateMesh(BlockType block, glm::vec3 coords, unsigned int indexOffset, Chunk* chunk) {
    Vertex vertex0, vertex1, vertex2, vertex3, vertex4, vertex5, vertex6, vertex7;
    glm::vec3 color{1.0f, 0.0f, 0.0f};
    glm::vec3 surfaceColor{1.0f, 0.0f, 0.0f};
    switch (block)
    {
        case BlockType::Grass:
            color = {0.0f, 1.0f, 0.0f};
            surfaceColor = {0.0557f, 0.530f, 0.0477f};
            break;
        case BlockType::Dirt:
            color = {0.54f, 0.261f, 0.151f};
            surfaceColor = color;
            break;
        case BlockType::Stone:
            color = {0.460f, 0.444f, 0.437f};
            surfaceColor = color;
            break;
        default:
            break;
    }

    vertex0.position = coords;
    vertex0.color = surfaceColor;
    this->_mesh.vertexPositions.push_back(vertex0);

    vertex1.position = {coords.x, coords.y, coords.z + 1.0f};
    vertex1.color = surfaceColor;
    this->_mesh.vertexPositions.push_back(vertex1);

    vertex2.position = {coords.x - 1.0f, coords.y, coords.z + 1.0f};
    vertex2.color = surfaceColor;
    this->_mesh.vertexPositions.push_back(vertex2);
    
    vertex3.position = {coords.x - 1.0f, coords.y, coords.z};
    vertex3.color = surfaceColor;
    this->_mesh.vertexPositions.push_back(vertex3);

    vertex4.position = {coords.x, coords.y - 1.0f, coords.z};
    vertex4.color = color;
    this->_mesh.vertexPositions.push_back(vertex4);

    vertex5.position = {coords.x, coords.y - 1.0f, coords.z + 1.0f};
    vertex5.color = color;
    this->_mesh.vertexPositions.push_back(vertex5);

    vertex6.position = {coords.x - 1.0f, coords.y - 1.0f, coords.z + 1.0f};
    vertex6.color = color;
    this->_mesh.vertexPositions.push_back(vertex6);

    vertex7.position = {coords.x - 1.0f, coords.y - 1.0f, coords.z};
    vertex7.color = color;
    this->_mesh.vertexPositions.push_back(vertex7);
    
    const unsigned short amountOfIndices = 6*3*2;

    // indices
    std::array<GLuint, amountOfIndices> indices{
        // 0
        3,  2,  0,
        0,  2,  1,
        // 1
        0,  1,  4,
        4,  1,  5,
        // 2
        3,  0,  7,
        7,  4,  0,
        // 3
        7,  3,  2,
        7,  2,  6,
        // 4
        2,  6,  1,
        6,  1,  5,
        // 5
        4,  6,  5,
        7,  6,  4
    };

    for (unsigned short i = 0; i < amountOfIndices; ++i) {
        this->_mesh.indices.push_back(indices.at(i) + (indexOffset*8));
    }
}

void ChunkMesh::activate() {
    this->_vao.Bind();
    
    this->_vbo.addVertices(this->_mesh.vertexPositions);
    this->_ebo.addIndices(this->_mesh.indices);

    this->_vao.LinkAttrib(this->_vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	this->_vao.LinkAttrib(this->_vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));

    this->_vao.Unbind();
    this->_vbo.Unbind();
    this->_ebo.Unbind();
}