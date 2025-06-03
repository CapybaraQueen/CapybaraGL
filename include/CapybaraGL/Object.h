#ifndef OBJECT_H
#define OBJECT_H

#include<CapybaraGL/VertexArray.h>
#include<CapybaraGL/VertexBuffer.h>
#include<CapybaraGL/VertexBufferLayout.h>
#include<CapybaraGL/IndexBuffer.h>
#include<CapybaraGL/Shader.h>

#include<vector>

enum ObjectType
{
	TRIANGLE = 0, SQUARE = 1, CIRCLE = 2
};

class Object
{
	private:
		float m_radius;
		float m_width;
		float m_height;
		float m_color[4];

		float centerPosition[2];
		
		std::vector<float> m_vertexPositions;
		std::vector<unsigned int> m_indices;

		VertexArray m_va;
		VertexBuffer m_vb;
		VertexBufferLayout m_layout;
		IndexBuffer m_ib;

		inline static std::string filepathBasicShader = "";
		inline static std::string filepathCircleShader = "";

	public:
		Object(ObjectType type, float radius, float width, float height, float color[4], std::vector<float> vertices, std::vector<unsigned int> indices);
		~Object() = default;
};

#endif
