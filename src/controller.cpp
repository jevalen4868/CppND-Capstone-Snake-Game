#include "controller.h"
#include "SDL.h"
#include "snake.h"
#include <iostream>

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1)
    snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT: {
      running = false;
      break;
    }
    case SDL_KEYDOWN: {
      switch (e.key.keysym.sym) {
      case SDLK_UP:
      case SDLK_w:
        ChangeDirection(snake, Snake::Direction::kUp, Snake::Direction::kDown);
        break;
      case SDLK_DOWN:
      case SDLK_s:
        ChangeDirection(snake, Snake::Direction::kDown, Snake::Direction::kUp);
        break;

      case SDLK_LEFT:
      case SDLK_a:
        ChangeDirection(snake, Snake::Direction::kLeft,
                        Snake::Direction::kRight);
        break;
      case SDLK_RIGHT:
      case SDLK_d:
        ChangeDirection(snake, Snake::Direction::kRight,
                        Snake::Direction::kLeft);
        break;
      case SDLK_ESCAPE:
        running = false;
        break;
      case SDLK_SPACE: {
        // pause the game
      }
      }
      break;
    }
    }
  }
}