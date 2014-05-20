#include "gameobject.h"
#include "Turret.h"
#include "Missile.h"
class HeroShip :
	public GameObject
{
public:
	Turret turret;
	HeroShip(void);
	~HeroShip(void);
	void Init(Vector2 position);
	void Draw(Core::Graphics graphics);
	void Fire();
};