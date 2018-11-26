

SDL_Surface* Init_Screen()
{
// initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Foret Niveau 1 ! ", NULL); //Titre de la fenetre

    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
}
