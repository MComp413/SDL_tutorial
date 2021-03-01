#include "Sprite.hpp"

#define UNBOUND_VERTEX_BUFFER_ID 0
#define QUAD_VERTEX_AMOUNT 6

Sprite::Sprite()
    :_vertexBufferObjectID(UNBOUND_VERTEX_BUFFER_ID)
{}

void Sprite::init(float x, float y, float w, float h)
{
    _x = x;
    _y = y;
    _w = w;
    _h = h;

    if(_vertexBufferObjectID == UNBOUND_VERTEX_BUFFER_ID)
         glGenBuffers(1, &_vertexBufferObjectID);

    float vertexCoords[QUAD_VERTEX_AMOUNT*2]; //2 triangulos = 1 quadrado = 6 vertices com x e y => 6*2=12

    //1st triangle
    vertexCoords[0] = x + w;
    vertexCoords[1] = y + h;

    vertexCoords[2] = x;
    vertexCoords[3] = y + h;

    vertexCoords[4] = x;
    vertexCoords[5] = y;

    //2nd triangle
    vertexCoords[6] = x;
    vertexCoords[7] = y;

    vertexCoords[8] = x + w;
    vertexCoords[9] = y;

    vertexCoords[10] = x + w;
    vertexCoords[11] = y + h;

    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObjectID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexCoords), vertexCoords, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, UNBOUND_VERTEX_BUFFER_ID);
}

void Sprite::draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObjectID);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, UNBOUND_VERTEX_BUFFER_ID);
}

Sprite::~Sprite()
{
    if(_vertexBufferObjectID != 0)
        glDeleteBuffers(1, &_vertexBufferObjectID);
}