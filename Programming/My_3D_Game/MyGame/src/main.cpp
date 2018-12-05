#include "game.h"

int main(int argc, char** argv)
{
	Game game;
	game.start();
}
/*TODO:
- Read settings from a file (instead of using code variables)
- World Generation (currently manually created)
- Collision (check movement bounds) [using worldCoords and isSolid() boolean]
- test if music is cross-platform and handle stopping of sound on exit (might need to use SDLSound)
- implement multi-audio device support (allows the user to chose there audio input and output)
- recode the shader, mesh, vertex, audio, text, and camera classes (I "Stole" example code just to learn how to do certain task) [copyright issues]
__TODO LATER:___
- get a test version ready (so we can test it on a mac) [Needs FPS Text]
- Finish implementing/test multi-monitor support [Needs multi-monitor setup]
? In-game mic [Needs multi-audio device support]
- In-game text chat [Needs hud]
- In-game commands (will use /command in text window like Minecraft) [Needs Text Chat] 
? Auto complete commands (probably with TAB key) [Needs Commands]
- Multi-language support [Needs Menus]
- Menus [Waiting on assets]
- Add AI (for enemies) [Needs Collision handling]
- Items [Waiting on assets]
- texture failure [Waiting on assets]
- HUD [Waiting on assets]
- Game saving/loading [Needs stuff to save/load]
- Multi-player [Needs stuff to link]
- Integrate with steam (SteamCMD servers, VAC banning, friend list joining)
? Integrate with Battle Eye (as alternative to steam)
? Integrate with Easy Anti Cheat [used by Fornite] (as alternative to steam)
- Add anti-piracy
- Mod support
ASSETS I AM WAITING FOR:
- Menu background
- Menu button background (will reuse and render text above it to create buttons)
- Finalized player design
- More/finalized music
- Block designs
- Item designs
- HUD images:
          - health bar
          - manna and/or stamina
          ! hot bar
- Enemy designs
- Error texture (for texture loading failures)(edited)*/