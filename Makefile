all:
	g++ -IC:\RPG_Game\build\include -LC:\RPG_Game\build\lib -o build/game.exe source_file/main.cpp source_file/Game.cpp states/GameState.cpp entities/Entity.cpp entities/Player.cpp states/State.cpp states/MainMenuState.cpp states/EditorState.cpp states/SettingState.cpp resource_file/Gui.cpp resource_file/GraphicSetting.cpp components/ComponentMovement.cpp components/ComponentAnimation.cpp components/ComponentHitboxx.cpp GUI/PauseMenu.cpp tile/Tile.cpp map/TileMap.cpp -lsfml-graphics -lsfml-window -lsfml-system