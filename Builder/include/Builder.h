/* 
* @Author: sxf
* @Date:   2015-11-08 09:06:35
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-21 19:30:12
*/


#ifndef BUILDER_H
#define BUILDER_H

#include <string>

class Worker;

/**
 * @brief 项目构建器
 */
class Builder
{
public:
	// 构建一个文件
	int BuildFile(std::string filename);
	
	// 构建其中指定的路径
	int BuildPath(std::string filepath, bool isRecursive = false);

	// 添加一个链接文件, 如果是bc的话, 会自动用llc编译成本地文件, 如果是.o则直接链接
	int AddLinkFile(std::string filename);

	// 添加一个链接路径
	int AddLinkPath(std::string filepath);

	// 设置构建路径
	int SetBuildPath(std::string path);

	// 扫描SearchPath下的全部符号
	int PreBuildAll();

	// 添加源代码的搜索路径
	int AddSearchPath(std::string path);

	// 添加库路径
	int AddLibPath(std::string path);

	// 设置Debug过程文件生成路径
	void setDebugFilePath(const char* path);

	// 设置工作器
	void setWorker(Worker* worker);

	// 构建Builder，需要初始化好的Worker
	static Builder* Create(Worker* worker = 0);
	void Close();

protected:
	Builder(Worker* worker = 0);
	~Builder();

	Worker* worker = 0;
	std::string buildpath;
	static std::string fileReader(const char* path);
	static std::string make_default_name(const char* filename);
	static std::string get_file_name(const char* filename);

	static int call_llc(std::string filein);
	static int call_ld(std::string filein, std::string fileout);

};



#endif // BUILDER_H
