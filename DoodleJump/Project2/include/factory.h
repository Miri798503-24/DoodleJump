#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "Objects.h"
#include "Monsters.h"

typedef std::map<std::string, std::unique_ptr<Objects>(*)()> mymap;
typedef std::map<std::string, std::unique_ptr<Monsters>(*)()> mymapM;

class factory
{
public:
	factory() = default;
	~factory() = default;
	static std::unique_ptr<Objects> create(const std::string& name);
	static bool registerit(const std::string& name, std::unique_ptr<Objects>(*)());

	static std::unique_ptr<Monsters> createM(const std::string& name);
	static bool registeritM(const std::string& name, std::unique_ptr<Monsters>(*)());

private:

	static mymap& getMap()
	{
		static mymap m_map;
		return m_map;
	}

	static mymapM& getMapM()
	{
		static mymapM m_mapM;
		return m_mapM;
	}
};