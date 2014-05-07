
#include "gameobject.h"
class HeroShip :
	public GameObject
{
public:
	HeroShip(void);
	~HeroShip(void);
	void Init(Vector2 position);
};