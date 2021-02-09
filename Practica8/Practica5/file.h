#pragma once

// Open file
// Mode:
// "r"	read
// "w"	write
// "a"	append
// "r+"	read extended
// "w+"	write extended
// "a+"	append extended

struct TFile //The same result if we change struct for class
{
private: 
	const char* sFilePath;

public: 
	TFile(char const* _filePath)
	{
		sFilePath = _filePath;
	}

	const char* GetPath()
	{
		return sFilePath;
	}

	void* OpenFile(const char* _sFileName, const char* _sMode);

	int CloseFile(void* _pFile);

	unsigned int ReadFile(void* _pFile, char* pBuffer_, unsigned int _uBufferSize);

	unsigned int WriteFile(void* _pFile, const char* _pBuffer, unsigned int _uBufferSize);

};