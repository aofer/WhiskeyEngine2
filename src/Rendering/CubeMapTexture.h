#pragma once
#include <Common/WECommon.h>
#include <string>
#include <GL/glew.h>
NAMESPACE_BEGIN(Rendering)

class CubeMapTexture
	{
	public:
		~CubeMapTexture();
		CubeMapTexture(const std::string& Directory,
						const std::string& PosXFilename,
						const std::string& NegXFilename,
						const std::string& PosYFilename,
						const std::string& NegYFilename,
						const std::string& PosZFilename,
						const std::string& NegZFilename);

		bool Load();

		void Bind(GLenum TextureUnit);

	private:
		std::string m_fileNames[6];
		//GLenum m_textureTarget;
		GLuint m_textureObj;

	};

NAMESPACE_END