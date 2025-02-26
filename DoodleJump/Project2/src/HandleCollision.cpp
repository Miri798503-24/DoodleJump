#include "HandleCollision.h"
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

namespace
{
    void playerMoney(Objects& player,
        Objects& mone)
    {
        Player& m_player = dynamic_cast<Player&>(player);
        money& m_mone = dynamic_cast<money&>(mone);

        //set score
          //erase vector
    }

    void playerMonster(Objects& player,      
        Objects& monster)
    {
        Player& m_player = dynamic_cast<Player&>(player);
        Monsters& m_monster = dynamic_cast<Monsters&>(monster);

        m_player.erase();
        m_player.setLife();
    }

    void monsterShoot(Objects& monster,  
        Objects& shoot)
    {
        Monsters& m_monster = dynamic_cast<Monsters&>(monster);
        Shoot& m_shoot = dynamic_cast<Shoot&>(shoot);
        //erase monster
    }


    void MoneyPlayer(Objects& mone,
        Objects& player)
    {
        playerMoney(player, mone);
    }
    void MonsterPlayer(Objects& monster,
        Objects& player)
    {
        playerMonster(player, monster);
    }
    void shootMonster(Objects& shoot,
        Objects& monster)
    {
        monsterShoot(shoot, monster);
    }


    using HitFunctionPtr = void (*)(Objects&, Objects&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Player), typeid(money))] = &playerMoney;
        phm[Key(typeid(Player), typeid(Monsters))] = &playerMonster;
        phm[Key(typeid(Monsters), typeid(Shoot))] = &monsterShoot;
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }
}
    void processCollision(Objects& object1, Objects& object2)
    {
        auto phf = lookup(typeid(object1), typeid(object2));
        phf(object1, object2);
    }