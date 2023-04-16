#include "chunkMesh.h"

void ChunkMesh::updateMesh(BlockType block, glm::vec3 coords, std::array<bool, 6>& visibleFaces, unsigned int indexOffset) {
    if (block == BlockType::Air)
        return; 
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
        case BlockType::Wood:
            color = {0.530f, 0.369f, 0.0477f};
            surfaceColor = color;
            break;
        case BlockType::Leaves:
            color = {0.265f, 0.530f, 0.0477f};
            surfaceColor = {0.198f, 0.440f, 0.00f};
            break;
        default:
            break;
    }

    std::array<glm::vec3, 8> verticiesCoords {
        coords,
        {coords.x, coords.y, coords.z + 1.0f},
        {coords.x - 1.0f, coords.y, coords.z + 1.0f},
        {coords.x - 1.0f, coords.y, coords.z},
        {coords.x, coords.y - 1.0f, coords.z},
        {coords.x, coords.y - 1.0f, coords.z + 1.0f},
        {coords.x - 1.0f, coords.y - 1.0f, coords.z + 1.0f},
        {coords.x - 1.0f, coords.y - 1.0f, coords.z}
    };

    for(glm::vec3& c : verticiesCoords) {
        Vertex vertex;
        vertex.position = c;
        vertex.color = color;
        this->_mesh.vertexPositions.push_back(vertex);
    }


    
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
        2,  5,  6,
        2,  1,  5,
        // 3
        3,  2,  6,
        7,  6,  3,
        // 4
        3,  0,  7,
        7,  4,  0,
        // 5
        4,  6,  5,
        7,  4,  6
    };

    for(short i = 0; i < 6; ++i) {
        if (visibleFaces[i]) {
            for (short y = 0; y < 6; ++y) {
                this->_mesh.indices.push_back(indices.at((i*6)+y) + (this->_numberOfBlocks*8));
            }
        }
    }
    this->_numberOfBlocks++;
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