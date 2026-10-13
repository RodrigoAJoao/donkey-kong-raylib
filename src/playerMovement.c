#include "playerMovement.h"
#include "raylib.h"

void playerMovement(float *playerPositionX, float *playerPositionY)
{
    // Trata entrada do usuario e atualiza estado do jogo
		if (IsKeyPressed(KEY_RIGHT)) {
			*playerPositionX += 2.0f;
		}
		if (IsKeyPressed(KEY_LEFT)) {
			*playerPositionX -= 2.0f;
		}
		if (IsKeyPressed(KEY_UP)) {
			*playerPositionY -= 2.0f;
		}
		if (IsKeyPressed(KEY_DOWN)) {
			*playerPositionY += 2.0f;
		}
}