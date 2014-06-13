#ifndef LOGGER
#define LOGGER

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "DebugMemory.h"

using std::vector;
using std::string;

enum Severity { Info, Warning, Error,Severe };

#define LOG( severity, message) Logger::Log( severity, message, __FILE__,__LINE__ )
#define END_LOG Logger::shutDown();

#pragma warning ( disable : 4100)
#pragma warning(disable : 4251)

class __declspec(dllexport)Logger
{
public:
#ifdef LOG_ON
	Logger(void);
	~Logger(void);
	static void StringReplace(string& str, const string& from, const string& to);
	static string Sanitize(string str);
	static void Log( Severity severity, const char* message, const char * logFile, long logLine);
	static void shutDown();
#else
	Logger(void){}
	~Logger(void){}
	static void StringReplace(string& str, const string& from, const string& to){}
	static string Sanitize(string str){}
	static void Log( Severity severity, const char* message, const char * logFile, long logLine){}
	static void shutDown(){}
#endif

private:
#ifdef LOG_ON
	static vector <std::string> logList;
	static vector <Severity> severityList;
	static void WriteFile();
#endif
};

#pragma warning ( default : 4100)
#pragma warning(default : 4251)

#endif