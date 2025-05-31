#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"

class Renderer
{
	public:
		void Clear() const;
		void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};

#endif
