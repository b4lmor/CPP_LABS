#include "utils/GameArgs.h"
#include "game/GameFactory.h"

int main(int argc, char * argv[]) {
	GameArgs args = GameArgs(argc, argv);
    AGame * game = get_game_by_args(args);
    game->run_game();
	return 0;
}
