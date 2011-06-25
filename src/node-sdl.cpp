#include <v8.h>
#include <node.h>
#include <SDL.h>

using namespace v8;
using namespace node;

namespace node_sdl {

  static Handle<Value> Init(const Arguments& args) {
    HandleScope scope;

    SDL_Init( SDL_INIT_VIDEO );

    return Undefined();
  }

}

extern "C" void
init(Handle<Object> target)
{
  HandleScope scope;

  target->Set(String::New("hello"), String::New("World"));
  NODE_SET_METHOD(target, "init", node_sdl::Init);

}



/*
    SDL_Init( SDL_INIT_VIDEO );
    SDL_Surface* screen = SDL_SetVideoMode( 0, 0, 0, SDL_SWSURFACE );

    SDL_FillRect (screen, NULL, 0x0088ff);

    SDL_Flip (screen);

    SDL_Event event;
    bool gameRunning = true;

    while (gameRunning)
    {
      if (SDL_WaitEvent(&event))
      {
        if (event.type == SDL_QUIT)
        {
          gameRunning = false;
        }
      }
    }
    printf("End Loop");

    SDL_Quit();
*/


/*

int main(int argc, char **argv)
{
  SDL_Init( SDL_INIT_VIDEO );

  SDL_Surface* screen = SDL_SetVideoMode( 0, 0, 0, SDL_SWSURFACE );

  SDL_FillRect (screen, NULL, 0x0088ff);

  SDL_Flip (screen);

  SDL_Event event;
  bool gameRunning = true;

  while (gameRunning)
  {
    if (SDL_WaitEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        gameRunning = false;
      }
    } 
  }
  printf("End Loop");

  SDL_Quit();

  return 0;

}

*/