#include <SDL2/SDL.h>
#include <vector>
#include "Forest.h"
#include "mes_perso.h"
#include "mes_formes.h"
#include "Field.h"
#include "Objects.h"
#include "Rock.h"
#include "Tree.h"


Forest::Forest()
{
    Field field;
    this->f=field;
}

Forest::Forest(Field field)
{
	this->f=field;
}

Forest::Forest(Forest& f)
{
    this->f=f.f;
    this->p1=f.p1;
    this->p2=f.p2;
    this->List_Obj= f.List_Obj;
}

Character* Forest::getP1(){return this->p1;}
Character* Forest::getP2(){return this->p2;}
std::vector<Objects*> Forest::getList(){return this->List_Obj;}

void Forest::init_forest()
{
	std::cout << "YO" << List_Obj.size() << std::endl;
	

    for (int i=0; i< List_Obj.size(); i++)
    {
    	std::cout << List_Obj[i]->getType() << std::endl;
        if(dynamic_cast<Rock*> (List_Obj[i]))
        	dynamic_cast <Rock*> (this->List_Obj[i])->print();
        if(dynamic_cast<Tree*> (List_Obj[i]))
            dynamic_cast <Tree*> (this->List_Obj[i])->print(this->f);    
    }
}

void Forest::print(SDL_Renderer *renderer)
{

  for(int unsigned i=0; i < this->List_Obj.size() ;i++)
  {
    if (dynamic_cast<Tree*>(this->List_Obj[i]))dynamic_cast<Tree*>(this->List_Obj[i])->print(f);
    if (dynamic_cast<Rock*>(this->List_Obj[i]))dynamic_cast<Rock*>(this->List_Obj[i])->print();
  }
   SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);
    
    SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

}

Forest::~Forest()
{}
