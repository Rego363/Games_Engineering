#include "Entity.h"
#include "HealthComponent.h"
#include "HealthSystem.h"
#include "PositionComponent.h"
#include "PositionSystem.h"

int main(void*)
{
	Entity player;
	std::shared_ptr<HealthComponent> hc = std::make_shared<HealthComponent>(HealthComponent());
	std::shared_ptr<PositionComponent> pc = std::make_shared<PositionComponent>(PositionComponent());
	player.addComponent(hc);
	player.addComponent(pc);

	HealthSystem hs;
	PositionSystem ps;
	hs.addEntity(player);
	ps.addEntity(player);

	while (true)
	{
		hs.update();
		ps.update();
	}
	return 0;
}