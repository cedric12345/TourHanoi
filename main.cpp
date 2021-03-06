#include <SDL/SDL.h>
#include <SDL_image.h>

void page1(SDL_Surface* ecran);

int main ( int argc, char** argv )
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *imageprincipale = IMG_Load("images/hanoii0.jpg");
    SDL_Surface *jouer_premier = IMG_Load("images/reset.png");
    SDL_Surface *instructions_premier = IMG_Load("images/instruction.png");
    SDL_Surface *scores_premier = IMG_Load("images/mscore.png");
    SDL_Surface *apropos_premier = IMG_Load("images/apropos.png");

    SDL_Rect positionimage , positionbouton;

    SDL_Init(SDL_INIT_VIDEO);// charge en memoire de la video
    ecran = SDL_SetVideoMode(800 , 480 , 32 , SDL_HWSURFACE | SDL_DOUBLEBUF );
    SDL_WM_SetCaption("La tour d'Hanoi", NULL);

    positionimage.x=0;
    positionimage.y=0;
    SDL_BlitSurface(imageprincipale , NULL , ecran ,&positionimage );

    positionbouton.x=2.5;
    positionbouton.y=400;
    SDL_BlitSurface(jouer_premier , NULL , ecran ,&positionbouton);

    positionbouton.x=207.5;
    SDL_BlitSurface(instructions_premier , NULL , ecran ,&positionbouton);

    positionbouton.x=412.5;
    SDL_BlitSurface(scores_premier , NULL , ecran ,&positionbouton);

    positionbouton.x=617.5;
    SDL_BlitSurface(apropos_premier , NULL , ecran ,&positionbouton);

    SDL_Event event;
    int continuer=1;
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
                if(event.button.x>=2.5 && event.button.x<=182.5 && event.button.y>=400 && event.button.y<=440)
                {
                    page1(ecran);
                }
                if(event.button.x>=207.5 && event.button.x<=387.5 && event.button.y>=400 && event.button.y<=440)
                {
                    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,255,0));
                }
                if(event.button.x>=207.5 && event.button.x<=387.5 && event.button.y>=400 && event.button.y<=440)
                {
                    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,255,0));
                }
                if(event.button.x>=412.5 && event.button.x<=592.5 && event.button.y>=400 && event.button.y<=440)
                {
                    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,255));
                }
                if(event.button.x>=617.5 && event.button.x<=797.5 && event.button.y>=400 && event.button.y<=440)
                {
                    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,255,0));
                }
            }

        }
        SDL_Flip(ecran);
    }
     SDL_Quit();
    return 0;
}


void page1(SDL_Surface* ecran)
{
    SDL_Surface *instructions_premier = IMG_Load("images/instruction.png");
    SDL_Surface *scores_premier = IMG_Load("images/mscore.png");
    SDL_Surface *apropos_premier = IMG_Load("images/apropos.png");

   SDL_Rect positionimage , positionbouton;
   SDL_Surface *imageprincipale = IMG_Load("images/hanoii0.jpg");
   SDL_Surface *imageprincipale2 = IMG_Load("images/hanoii01.jpg");
   SDL_Surface *modeDefis = IMG_Load("images/defi.png");
   SDL_Surface *jouer_premier = IMG_Load("images/reset.png");
   SDL_Surface *b_retour = IMG_Load("images/retour.png");

   positionimage.x=0;
   positionimage.y=0;
   SDL_BlitSurface(imageprincipale2 , NULL , ecran ,&positionimage);

   positionbouton.x=0;
   positionbouton.y=ecran->h / 2 - b_retour->h / 2;
   SDL_BlitSurface(b_retour , NULL , ecran ,&positionbouton);

   positionbouton.y=400;
   positionbouton.x=207.5;
   SDL_BlitSurface(jouer_premier , NULL , ecran ,&positionbouton);
   positionbouton.x=412.5;
   SDL_BlitSurface(modeDefis , NULL , ecran ,&positionbouton);

   SDL_Event event;
   int continuer=1;
   while(continuer)
   {
       SDL_WaitEvent(&event);
       switch(event.type)
       {
       case SDL_QUIT:
        continuer=0;
        break;
       case SDL_MOUSEBUTTONDOWN:
        switch(event.button.button)
        {
        case SDL_BUTTON_LEFT:
            if(event.button.x>=207.5 && event.button.x<=387.5 && event.button.y>=400 && event.button.y<=440)
                {
                    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,255,0));
                }
            if(event.button.x>=412.5 && event.button.x<=592.5 && event.button.y>=400 && event.button.y<=440)
                {
                    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,255));
                }
            if(event.button.x>=0 && event.button.x<=60 && event.button.y>=ecran->h/2 && event.button.y<=(ecran->h/2)+60)
                {
                    continuer=0;
                }
                break;
        }
       }
       SDL_Flip(ecran);
   }
   SDL_BlitSurface(imageprincipale , NULL , ecran ,&positionimage );

   positionbouton.x=2.5;
    positionbouton.y=400;
    SDL_BlitSurface(jouer_premier , NULL , ecran ,&positionbouton);

    positionbouton.x=207.5;
    SDL_BlitSurface(instructions_premier , NULL , ecran ,&positionbouton);

    positionbouton.x=412.5;
    SDL_BlitSurface(scores_premier , NULL , ecran ,&positionbouton);

    positionbouton.x=617.5;
    SDL_BlitSurface(apropos_premier , NULL , ecran ,&positionbouton);
}
