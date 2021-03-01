#pragma once
#include <GL/glew.h>

class Sprite
{
public:
    Sprite();
    ~Sprite();
    void init(float x, float y, float w, float h);
    void draw();
private:
    float _x, _y, _w, _h;
    GLuint _vertexBufferObjectID;
};