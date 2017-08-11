#pragma once
#include <Common/WECommon.h>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <GL\glew.h>
#include <string.h>


NAMESPACE_BEGIN(Rendering)


static std::string ReadFileIntoString(const std::string& filename);


	class ShaderManager
	{

	public:
		//TODO consider removing singleton
		static ShaderManager& GetInstance()
		{
			static ShaderManager    instance; // Guaranteed to be destroyed.
											  // Instantiated on first use.
			return instance;
		}
		ShaderManager(ShaderManager const&) = delete;
		void operator=(ShaderManager const&) = delete;


		void CreateProgram(const std::string& shaderName,
			const std::string& VertexShaderFilename,
			const std::string& FragmentShaderFilename);

		const GLuint GetShader(const std::string&);
		void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
		void SetResourcesFolder(const std::string& path);

	private:

		ShaderManager(void) {}
		~ShaderManager(void);
		static ShaderManager* instance;

		std::string ReadShader(const std::string& filename);
		GLuint CreateShader(GLenum shaderType,
			const std::string& source,
			const std::string& shaderName);

		typedef std::map<std::string, GLuint> ProgramMap;
		ProgramMap programs;
		std::string m_resourcesFolderPath;
	};

	NAMESPACE_END