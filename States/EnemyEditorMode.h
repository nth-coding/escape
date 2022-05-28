#ifndef ENEMYEDITORMODE_H
#define ENEMYEDITORMODE_H

#include "../header_files/Header.h"
#include "EditorMode.h"
#include "../map/EnemySpawnerTile.h"

class EnemyEditorMode : public EditorMode
{
private:
	sf::Text cursorText;
	sf::RectangleShape sidebar;
	sf::RectangleShape selectorRect;
	sf::IntRect textureRect;

	int type;
	int amount;
	int timeToSpawn;
	float maxDistance;

	void initVariables();
	void initGui();

public:
	EnemyEditorMode(StateData* state_data, TileMap* tile_map, EditorStateData* editor_state_data);
	virtual ~EnemyEditorMode();

	//Functions
	void updateInput(const float& dt);
	void updateGui(const float& dt);
	void update(const float& dt);

	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

#endif
