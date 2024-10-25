// #include "header.h"

// #define WINDOW_X 0
// #define WINDOW_Y 0
// #define WINDOW_WIDTH 1920
// #define WINDOW_HEIGHT 1080


// #define FPS 30
// #define FRAME_TARGET_TIME 1000 / FPS

// #define BALL_SIZE 100

// SDL_Window *window = NULL;
// SDL_Renderer *renderer = NULL;
// int last_frame_time = 0;
// int movement_speed = 3;

// enum {
//     MOVE_UP,
//     MOVE_DOWN,
//     MOVE_LEFT,
//     MOVE_RIGHT,
//     MOVE_INCREASE_SPEED,
//     MOVE_DECREASE_SPEED
// };

// struct ball
// {
//     int x;
//     int y;
//     int width;
//     int height;
// }ball;


// int initialize_window()
// {
//     if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//         fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
//         return FALSE;
//     }

//     window = SDL_CreateWindow(
//         "Game",
//         WINDOW_X,
//         WINDOW_Y,
//         WINDOW_WIDTH,
//         WINDOW_HEIGHT,
//         SDL_WINDOW_BORDERLESS
//     );

//     if(!window) {
//         fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
//         return FALSE;
//     }

//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if(!renderer) {
//         fprintf(stderr,"Error creating SDL Renderer");
//         return FALSE;
//     }

//     return TRUE;
// }


// void update(int move) 
// {
//     //sleep until reach the frame target
//     while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));

//     last_frame_time = SDL_GetTicks();

//     switch (move)
//     {
//     case MOVE_UP:
//         if (ball.y > 0) 
//         {
//             ball.y -= movement_speed;
//         }
//         break;
    
//     case MOVE_DOWN:
//         //added ballsize to ball doesn't clip into walls
//         if (ball.y + BALL_SIZE < WINDOW_HEIGHT) 
//         {
//             ball.y += movement_speed;
//         }
//         break;
    
//     case MOVE_LEFT:
//         if (ball.x > 0 ) 
//         {
//             ball.x -= movement_speed;
//         }
//         break;

//     case MOVE_RIGHT:
//         //added ballsize to ball doesn't clip into walls
//         if (ball.x + BALL_SIZE< WINDOW_WIDTH) 
//         {
//             ball.x += movement_speed;
//         }
//         break;

//     case MOVE_INCREASE_SPEED:
//         movement_speed += 1;
//         break;

//     case MOVE_DECREASE_SPEED:
//         movement_speed -=1;
//         break;
//     }

// }

// void render() 
// {
//     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//     SDL_RenderClear(renderer);
//     //draw a rectangle 
//     SDL_Rect ball_rect = {
//                         (int)ball.x, 
//                         (int)ball.y, 
//                         (int)ball.width, 
//                         (int)ball.height};

//     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//     SDL_RenderFillRect(renderer, &ball_rect);

//     SDL_RenderPresent(renderer);

// }

// void setup() 
// {
//     ball.x = (WINDOW_WIDTH / 2) - (BALL_SIZE / 2);
//     ball.y = (WINDOW_HEIGHT / 2) - (BALL_SIZE / 2);
//     ball.width = BALL_SIZE;
//     ball.height = BALL_SIZE;
// }

// void QUIT() 
// {
//     //Destroy renderer, window and quit
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();
// }