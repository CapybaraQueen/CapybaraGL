#include<CapybaraGL/Window.h>
#include<CapybaraGL/VertexBufferLayout.h>
#include<CapybaraGL/VertexArray.h>
#include<CapybaraGL/VertexBuffer.h>
#include<CapybaraGL/IndexBuffer.h>
#include<CapybaraGL/Renderer.h>
#include<CapybaraGL/Shader.h>

#include<iostream>

int main()
{
	Window window("Test", 800, 800);

	float positions[] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	VertexArray va;
	VertexBuffer vb(positions, 4 * 2 * sizeof(float));

	IndexBuffer ib(indices, 6);

	VertexBufferLayout layout;
	layout.AddFloat(2);

	va.AddBuffer(vb, layout);

	Shader shader("/home/Angie/Documents/CppCode/CapybaraGL/res/shaders/Basic.glsl");
	shader.Bind();

	float red = 0.0f;
	float green = 0.3f;
	
	float blue = 0.8f;
	float step = 0.05f;

	Renderer renderer;

	do
	{
		renderer.Clear();

		shader.Bind();
		shader.SetUniform4f("u_color", red, green, blue, 1.0);

		renderer.Draw(va, ib, shader);

		window.LoopTest();
		window.PollEvents();

		if (red < 0.0f || red > 1.0f)
		{
			step *= -1.0;
		}

		red += step;

	}

	while (window.WindowExists());

	return 0;
}
