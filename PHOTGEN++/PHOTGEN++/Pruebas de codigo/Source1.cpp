#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
/* Para ver $HOME */
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
/* Para ver $HOME */

const std::list<std::string> stdConfigPaths =
{
  ":file.:cfgext",
  ":home/.:programa.:cfgext",
  ":home/.:programa/:file.:cfgext",
  "/etc/:programa.:cfgext",
  "/etc/:programa/:file.:cfgext",
  "/var/:programa/:file.:cfgext"
};

bool file_exists(const std::string& name)
{
	std::ifstream f(name.c_str());
	return f.good();
}

std::string replace(std::string source, std::map<std::string, std::string>strMap, int offset = 0, int times = 0, bool delimiters = true, std::string before = ":", std::string after = "")
{
	int total = 0;
	std::string::size_type pos = offset;
	std::string::size_type newPos;
	std::string::size_type lowerPos;
	std::string::size_type delsize;

	if (strMap.size() == 0)
		return source;

	if (delimiters)
		delsize = before.length() + after.length();

	do
	{
		std::string rep;
		for (auto i = strMap.begin(); i != strMap.end(); ++i)
		{
			auto fromStr = i->first;
			newPos = (delimiters) ?
				source.find(before + fromStr + after, pos) :
				source.find(fromStr, pos);

			if ((i == strMap.begin()) || (newPos < lowerPos))
			{
				rep = fromStr;
				lowerPos = newPos;
			}
		}

		pos = lowerPos;
		if (pos == std::string::npos)
			break;

		std::string toStr = strMap[rep];
		source.replace(pos, rep.length() + ((delimiters) ? delsize : 0), toStr);
		pos += toStr.size();

	} while ((times == 0) || (++total < times));

	return source;
}

bool findFile(std::string &file, const std::list<std::string>& paths, const std::map<std::string, std::string>& replacements)
{
	for (auto p : paths)
	{
		p = replace(p, replacements);
		if (file_exists(p) == 1)
		{
			file = p;
			return true;
		}
	}
}

/* Para ver $HOME */
char *getHomeDir()
{
	static char *home = NULL;

	if (!home)
	{
		home = getenv("HOME");
	}
	if (!home)
	{
		struct passwd *pw = getpwuid(getuid());
		if (pw)
			home = pw->pw_dir;
	}
	return home;
}
/* Para ver $HOME */

int main(int argc, char *argv[])
{
	std::string f;
	std::map<std::string, std::string> reemplazos =
	{
	  { "file", "miconfig" },
	  { "cfgext", "xml" },
	  { "programa", "miprograma" },
	  { "home", getHomeDir() }
	};

	if (findFile(f, stdConfigPaths, reemplazos))
		std::cout << "El fichero se encontró en: " << f << std::endl;
	else
		std::cout << "No se encuentra el fichero " << std::endl;
}