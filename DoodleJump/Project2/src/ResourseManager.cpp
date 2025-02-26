#include "ResourseManager.h"

ResourseManager::ResourseManager()
{
	setvec();
}

ResourseManager& ResourseManager::instance()
{
	static ResourseManager insta;
	return insta;
}

void ResourseManager::setvec()
{
	//לטעון את כל התמונות	
	sf::Texture a, b, c, d, e, f, g, h, i, j, k, l, m ,n ,o ,p, q, r,s,t,u,v,w, y, x;
	a.loadFromFile("brickGreen.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("brickGreen", a));
	b.loadFromFile("bomb.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("bomb", b));
	c.loadFromFile("doodle fly.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("doodle fly", c));
	d.loadFromFile("doodle right.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("doodle right", d));
	e.loadFromFile("monster1.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("monster1", e));
	f.loadFromFile("pear.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("pear", f));
	g.loadFromFile("strawberry.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("strawberry", g));
	h.loadFromFile("monster2.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("monster2", h));
	i.loadFromFile("monster3.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("monster3", i));
	j.loadFromFile("doodle left.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("doodle left", j));
	k.loadFromFile("brickBrown.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("brickBrown", k));
	l.loadFromFile("brickCrushed.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("brickCrushed", l));
	m.loadFromFile("brickJump.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("brickJump", m));
	n.loadFromFile("brickWhite.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("brickWhite", n));
	o.loadFromFile("doodle in space.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("doodle in space", o));
	p.loadFromFile("doodleSleep.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("doodleSleep", p));
	q.loadFromFile("hole.jpg");
	m_mapPictures.insert(std::pair<string, sf::Texture>("hole", q));
	r.loadFromFile("level1.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("level1", r));
	s.loadFromFile("play butoon.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("play butoon", s));
	t.loadFromFile("level2.jpg");
	m_mapPictures.insert(std::pair<string, sf::Texture>("level2", t));
	u.loadFromFile("level3.jpg");
	m_mapPictures.insert(std::pair<string, sf::Texture>("level3", u));
	v.loadFromFile("cancel-button.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("cancel-button", v));
	w.loadFromFile("doodle.jpg");
	m_mapPictures.insert(std::pair<string, sf::Texture>("doodle", w));
	y.loadFromFile("endHome.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("endHome", y));
	x.loadFromFile("hart.png");
	m_mapPictures.insert(std::pair<string, sf::Texture>("hart", x));

	m_font = (std::make_unique<sf::Font>());
	m_font->loadFromFile("al-seana.ttf");

	/*m_music = std::make_unique<sf::Music>();
	m_music->openFromFile("resources\music.wav");
	m_music->setVolume(40);*/
}

sf::Texture& ResourseManager::getImage(const string& name)
{
	return m_mapPictures[name];
}

sf::Font& ResourseManager::getFont() const
{
	return *m_font;
}

//sf::Music& ResourseManager::getMusic() const
//{
//	return *m_music;
//}
