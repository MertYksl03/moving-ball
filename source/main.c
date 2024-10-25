#include "header.h"
#include "draw_circle.h"

#define WINDOW_X 0
#define WINDOW_Y 0
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


#define FPS 60
#define FRAME_TARGET_TIME 1000 / FPS

#define BALL_SPEED 10

//FUNCTION PROTOTYPES
void process_input();
int initialize_window();
void update();
void render();
void setup();
void QUIT();
void move_ball();

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int last_frame_time = 0;
int ball_size = 100;

int is_game_running = FALSE;
int move = 0;   

enum {
    MOVE_STAY,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_INCREASE_SPEED,
    MOVE_DECREASE_SPEED,
};

struct ball
{
    int x;
    int y;
    int radius;
    int speed;
    int direction;
}ball;

int main(void) 
{
    is_game_running = initialize_window();

    setup();

    while(is_game_running) 
    {
        process_input();
        update(move);
        //render_text();
        render();
    }

    QUIT();

}

void process_input() 
{ 
    SDL_Event event;
    while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    is_game_running = FALSE;
                    break;
                case SDL_KEYUP:
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            is_game_running = FALSE;
                            break;
                        case SDLK_UP:
                            ball.direction = MOVE_UP;
                            break;
                        case SDLK_DOWN:
                            ball.direction = MOVE_DOWN;
                            break;
                        case SDLK_LEFT:
                            ball.direction = MOVE_LEFT;
                            break;
                        case SDLK_RIGHT:
                            ball.direction = MOVE_RIGHT;
                            break; 
                    }
            }
        }

}

int initialize_window()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return FALSE;
    }

    window = SDL_CreateWindow(
        "Game",
        WINDOW_X,
        WINDOW_Y,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );

    if(!window) {
        fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
        return FALSE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer) {
        fprintf(stderr,"Error creating SDL Renderer");
        return FALSE;
    }

    return TRUE;
}


void update() 
{
    //sleep until reach the frame target
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));

    last_frame_time = SDL_GetTicks();

    move_ball();

}

void move_ball() 
{

    switch (ball.direction)
    {
        case MOVE_UP:
            if (ball.y  - ball.radius > 0 ) 
            {
                ball.y -= ball.speed;
            }
            break;
        
        case MOVE_DOWN:
            if (ball.y + ball.radius < WINDOW_HEIGHT) 
            {
                ball.y += ball.speed;
            }
            break;
        
        case MOVE_LEFT:
            if (ball.x - ball.radius > 0 ) 
            {
                ball.x -= ball.speed;
            }
            break;
        
        case MOVE_RIGHT:
            //added ballsize to ball doesn't clip into walls
            if (ball.x + ball.radius < WINDOW_WIDTH) 
            {
                ball.x += ball.speed;
            }
            break;
        
        // case MOVE_INCREASE_SPEED:
        //     movement_speed += 1;
        //     break;
        
        // case MOVE_DECREASE_SPEED:
        //     movement_speed -=1;
        //     break;
        }
        
        //stop the ball 

}

void render() 
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    // //draw a rectangle 
    // SDL_Rect ball_rect = {
    //                     (int)ball.x, 
    //                     (int)ball.y, 
    //                     (int)ball.width, 
    //                     (int)ball.height};

    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // SDL_RenderFillRect(renderer, &ball_rect);



    //draw a white cirlce
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillCircle(
        renderer,
        ball.x,
        ball.y,
        ball.radius 
    );


    SDL_RenderPresent(renderer);

}

void setup() 
{
    ball.x = (WINDOW_WIDTH / 2) - (ball_size / 2);
    ball.y = (WINDOW_HEIGHT / 2) - (ball_size / 2);
    ball.radius = ball_size;
    ball.speed = BALL_SPEED;
    
    //set the initial direction randomly 
    srand(time(NULL));
    ball.direction = (rand() % 4) + 1;
}


void QUIT() 
{
    //Destroy renderer, window and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}