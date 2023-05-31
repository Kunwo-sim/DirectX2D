#include "yaRenderer.h"



namespace ya::renderer
{
	Vertex vertexes[9] = {};
	
	// Input Layout (정점 정보)
	ID3D11InputLayout* triangleLayout = nullptr;

	// Vertex Buffer
	ID3D11Buffer* triangleBuffer = nullptr;
	
	// error blob
	ID3DBlob* errorBlob = nullptr;
	
	// Vertex Shader code -> Binary Code
	ID3DBlob* triangleVSBlob = nullptr;

	// Vertex Shader
	ID3D11VertexShader* triangleVSShader = nullptr;

	// Pixel Shader code -> Binary Code
	ID3DBlob* trianglePSBlob = nullptr;

	// Vertex Shader
	ID3D11PixelShader* trianglePSShader = nullptr;

	void SetupState()
	{


		

	}

	void LoadBuffer()
	{
		D3D11_BUFFER_DESC triangleDesc = {};
		triangleDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		triangleDesc.ByteWidth = sizeof(Vertex) * 9;
		triangleDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		triangleDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		D3D11_SUBRESOURCE_DATA triangleData = {};
		triangleData.pSysMem = vertexes;
		ya::graphics::GetDevice()->CreateBuffer(&triangleBuffer, &triangleDesc, &triangleData);
	}

	void LoadShader()
	{
		ya::graphics::GetDevice()->CreateShader();
	}

	void Initialize()
	{
		vertexes[0].pos = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(-0.5f, 0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[3].pos = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[3].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[4].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[4].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[5].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[5].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[6].pos = Vector3(0.0f, 0.9f, 0.0f);
		vertexes[6].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[7].pos = Vector3(0.75f, 0.5f, 0.0f);
		vertexes[7].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[8].pos = Vector3(-0.75f, 0.5f, 0.0f);
		vertexes[8].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		SetupState();
		LoadBuffer();
		LoadShader();
	}
}



