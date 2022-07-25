/*
 * (c) 2009, 2010 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */
#include "sf.hpp"

World *           w;
TexturesManager * t;
Sprite * Title, * Background0;
Player *          player;

#define BADSCOUNT 4

Creature *        Bads[BADSCOUNT];
ParticleSystem *  psEx;

#define WIDTH 800
#define HEIGHT 600

bool done = false,
     fullscreen = true,
     gamepause = false;
enum GameMode {gmMenu, gmEdit, gmPlay} mode = gmMenu;
#include <iostream>


void RenderText(TTF_Font *Font, int8_t R, int8_t G, int8_t B, double X, double Y, const char *Text)
{
    //Create some variables.
    SDL_Color Color = {R, G, B};
    SDL_Surface *Message = TTF_RenderText_Blended(Font, Text, Color);
    unsigned Texture = 0;

    //Generate an OpenGL 2D texture from the SDL_Surface*.
    glGenTextures(1, &Texture);
    glBindTexture(GL_TEXTURE_2D, Texture);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Message->w, Message->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, Message->pixels);

    glLoadIdentity();
    //Draw this texture on a quad with the given xyz coordinates.
    glBegin(GL_QUADS);
            glTexCoord2d(0, 1); glVertex2f(X, Y);
            glTexCoord2d(1, 1); glVertex2f(X+Message->w/128.f, Y);
            glTexCoord2d(1, 0); glVertex2f(X+Message->w/128.f, Y+Message->h/128.f);
            glTexCoord2d(0, 0); glVertex2f(X, Y+Message->h/128.f);
    glEnd();

    //Clean up.
    glDeleteTextures(1, &Texture);
    SDL_FreeSurface(Message);
}

void SetGameMode(GameMode _mode)
{
    mode = _mode;
    switch (mode)
    {
        case gmMenu:
            Title->WakeUp();
            Background0->Sleep();
            for (int i = 0; i < CurrentLevel.AmountOfSprites; i++)
                LevelSprites[i]->Sleep();
            for (int x = 0; x < TILEX; x++)
                for (int y = 0; y < TILEY; y++)
                    LevelTiles[y][x]->Sleep();
            player->Sleep();
            for (int i = 0; i < BADSCOUNT; i++)
                Bads[i]->Sleep();
            psEx->Sleep();
            break;
        case gmPlay:
            Title->Sleep();
            Background0->WakeUp();
            player->WakeUp();
            for (int i = 0; i < CurrentLevel.AmountOfSprites; i++)
                LevelSprites[i]->WakeUp();
            for (int x = 0; x < TILEX; x++)
                for (int y = 0; y < TILEY; y++)
                    LevelTiles[y][x]->WakeUp();
            for (int i = 0; i < BADSCOUNT; i++)
                Bads[i]->WakeUp();
            psEx->WakeUp();
            break;
        default:
            break;
    }
}

void Menu(uint32_t ElapsedTime, const uint8_t *keys)
{
    w->ScreenCenter.Set(0.f, 0.f);
    if (keys[SDL_SCANCODE_RETURN])
        SetGameMode(gmPlay);
    if (keys[SDL_SCANCODE_Q])
        done = true;
}

void Play(uint32_t ElapsedTime, const uint8_t *keys)
{
    if (keys[SDL_SCANCODE_ESCAPE])
        SetGameMode(gmMenu);
    if (keys[SDL_SCANCODE_F4])
        gamepause = true;
    if (keys[SDL_SCANCODE_F5])
        gamepause = false;
    if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_A])
        player->RunLeft();
    if (keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_D])
        player->RunRight();
    if (keys[SDL_SCANCODE_SPACE] || keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_KP_2])
        player->Jump();
    w->ScreenCenter = player->Position;
    Background0->Position = w->ScreenCenter;
}

Application::Application()
{
}

int Application::Init()
{
    return 0;
}

int Application::MainLoop()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        return 1;
    }
    TTF_Init();
    SDL_Window *window = SDL_CreateWindow("Strange fruits", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGHT,
                                          SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    //SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //SDL_Surface* screen = SDL_SetVideoMode(WIDTH, HEIGHT, 24, SDL_OPENGL | SDL_HWSURFACE | SDL_DOUBLEBUF | (fullscreen ? SDL_FULLSCREEN : 0));
    // if (!renderer)
    // {
    //     fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
    //     return 1;
    // }
    // SDL_WM_SetCaption("Strange fruits", "Strange fruits");
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,     8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,   8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,   16);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,   8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1 );

    w = new World();
    t = new TexturesManager();

    w->Background.Set(1.f, .0f, .0f, .0f);
    w->Width = 20;
    w->Height = 15;

    Title = new Sprite(w);
    Title->Width = 15;
    Title->Height = 15;
    Title->TextureID = t->Get("../share/bg.png");

    Background0 = new Sprite(w);
    Background0->Width = 20;
    Background0->Height = 20;
    Background0->TextureID = t->Get("../share/bgodn.png");

    psEx = new ParticleSystem(w, 200);
    psEx->Position.Set(22, 4);
    psEx->TextureID = t->Get("../share/fire.png");
    psEx->Set(0.2, 0.36, 1000, Color(0xFFFFFFFF), Color(0x00000000), 40);

    for (int i = 0; i < MAX_AMOUNT_OF_LEVEL_SPRITES; i++)
    {
        LevelSprites[i] = new Sprite(w);
        LevelSprites[i]->Sleep();
    }

    char Buff[128];
    uint32_t OrangeTexures[4];
    for (int i = 0; i < 4; i++)
    {
        sprintf(Buff, "../share/orange%d.png", i + 1);
        OrangeTexures[i] = t->Get(Buff);
    }
    uint32_t SolTexures[4];
    for (int i = 0; i < 4; i++)
    {
        sprintf(Buff, "../share/sol%d.png", i + 1);
        SolTexures[i] = t->Get(Buff);
    }

    for (int i = 0; i < BADSCOUNT; i++)
    {
        Bads[i] = new Creature(w);
        Bads[i]->Sleep();
        Bads[i]->Position.Set(4.f + i*2, 12.f + i/2.f);
        Bads[i]->AI = aiJump;//i % 2 ? aiJump : aiRun;
        Bads[i]->RunSpeed = 2.0f;
        Bads[i]->FlySpeed = 1.0f;
        for (int j = 0; j < 4; j++)
            Bads[i]->Textures[j] = SolTexures[j];
    }


    Bads[0]->AI = aiGuard;
    Bads[0]->Position.Set(5, 5);
    Bads[1]->AI = aiGuard;
    Bads[1]->Position.Set(8, 11);
    Bads[2]->AI = aiGuard;
    Bads[2]->Position.Set(15, 4);

    player = new Player(w);
    player->Sleep();
    player->Position.Set(10.f, 13.5f);
    for (int j = 0; j < 4; j++)
    player->Textures[j] = OrangeTexures[j];

    for (int x = 0; x < TILEX; x++)
        for (int y = 0; y < TILEY; y++)
        {
            LevelTiles[y][x] = new Sprite(w);
            LevelTiles[y][x]->Sleep();
        }

    LoadLevel(&TheLevel);

    SetGameMode(gmMenu);
    uint32_t ElapsedTime = 0, LastTickCount, ThisTickCount, Frames = 0, LastFrame;
    TTF_Font *Font = TTF_OpenFont("../share/font.ttf", 64);
    LastFrame = LastTickCount = SDL_GetTicks();
    while (!done)
    {
        ThisTickCount = SDL_GetTicks();
        ElapsedTime = ThisTickCount - LastTickCount;
        LastTickCount = ThisTickCount;
        /*if (ElapsedTime > 40)
        {
                printf("Too slow...\n");
                ElapsedTime = 40;
        }*/
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                  done = true;
                  break;
                case SDL_KEYDOWN:
                {
                  if (event.key.keysym.sym == SDLK_ESCAPE)
                    done = true;
                    break;
                }
            }
        }
        const uint8_t *keys = SDL_GetKeyboardState(0);
        switch (mode)
        {
            case gmMenu:
                Menu(ElapsedTime, keys);
                break;
            case gmPlay:
                Play(ElapsedTime, keys);
                break;
            default:
                break;
        }
        w->Iteration(gamepause ? 0 : ElapsedTime);
        Frames++;
        if (ThisTickCount - LastFrame > 500)
        {
            sprintf(Buff, "fr:%3.1ffps", Frames * 1000.f / (ThisTickCount - LastFrame));
            LastFrame = ThisTickCount;
            Frames = 0;
        }
        RenderText(Font, 255, 205, 0, 36.f, 4.75f, Buff);
        RenderText(Font, 64, 64, 255, 10.5f, 15.5f, "Eggplants must die!!!");
        //SDL_GL_SwapBuffers();
        // Update screen
        SDL_GL_SwapWindow(window);
        //SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(Font);
    for (int i = 0; i < MAX_AMOUNT_OF_LEVEL_SPRITES; i++)
        delete LevelSprites[i];
    for (int x = 0; x < TILEX; x++)
    for (int y = 0; y < TILEY; y++)
        delete LevelTiles[y][x];
    for (int i = 0; i < BADSCOUNT; i++)
        delete Bads[i];
    delete player;
    delete Title;
    delete psEx;
    delete t;
    delete w;
    
    SDL_GL_DeleteContext( context );
    //SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

int Application::Release()
{
    return 0;
}

int Application::Run()
{
    Init();
    MainLoop();
    Release();
    return 0;
}

Application::~Application()
{
}
