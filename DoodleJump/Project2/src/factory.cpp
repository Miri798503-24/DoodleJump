#include "factory.h"

std::unique_ptr<Objects> factory::create(const std::string& name)
{
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second();
}

bool factory::registerit(const std::string& name, std::unique_ptr<Objects>(*f)())
{
	getMap().emplace(name, f);
	return true;
}

std::unique_ptr<Monsters> factory::createM(const std::string& name)
{
	auto it = getMapM().find(name);
	if (it == getMapM().end())
		return nullptr;
	return it->second();
}

bool factory::registeritM(const std::string& name, std::unique_ptr<Monsters>(*f)())
{
	getMapM().emplace(name, f);
	return true;
}
