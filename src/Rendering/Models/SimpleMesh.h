#pragma once
#include <map>
#include <vector>
#include <GL/glew.h>
#include <Common/WECommon.h>
#include "VertexFormat.h"

NAMESPACE_BEGIN2(Rendering,Models)

class SimpleMesh
{
	//friend class ObjMeshFactory;
public:
	SimpleMesh();
	~SimpleMesh();

	void InitOnGPU();

	void Draw();



private:


	struct SubMesh {
		SubMesh();

		~SubMesh();

		void InitOnGPU();

		GLuint VB;
		GLuint IB;
		GLuint VAO;

		std::vector<VertexFormat> m_vertices;
		std::vector<unsigned int> m_indices;

	};

	std::vector<SubMesh>		m_entries;
	bool						m_isLoadedOnGPU;

	public:
	std::vector<SubMesh>& GetEntries();
	bool IsLoadedOnGPU() const;
	void SetIsLoadedOnGPU(const bool& isLoaded);

};

NAMESPACE_END2