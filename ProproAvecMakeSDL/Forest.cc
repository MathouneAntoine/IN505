#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "Forest.h"
#include "mes_perso.h"
#include "mes_formes.h"
#include "Field.h"
#include "Objects.h"
#include "Rock.h"
#include "Tree.h"
using namespace std;

Forest::Forest()
{
    Field field;
    this->f=field;
    p1=NULL;
    p2=NULL;
    std::vector<Objects*>List_Obj;
}

Forest::Forest(Field field)
{
    this->f=field;
    p1=NULL;
    p2=NULL;
    std::vector<Objects*>List_Obj;
}


Character* Forest::getP1(){return this->p1;}
Character* Forest::getP2(){return this->p2;}
Field Forest::getField(){return this->f;}

Objects* Forest::getObj(int i){

    return this->List_Obj[i];
}

void Forest::setP1(Character* c){ this->p1=c;}
void Forest::setP2(Character* c){ this->p2=c;}

vector<Objects*> Forest::getList(){return this->List_Obj;}

void Forest::addList(Objects* o)
{
   List_Obj.push_back(o);
}
void Forest::setList(vector<Objects*> v)
{
    this->List_Obj = v;

}

void Forest::init_forest()
{
    std::cout << "YO" << List_Obj.size() << std::endl;
    

    for (int i=0; i< List_Obj.size(); i++)
    {
        std::cout << List_Obj[i]->getType() << std::endl;
        if(dynamic_cast<Rock*> (List_Obj[i]))
            dynamic_cast <Rock*> (this->List_Obj[i])->print(this->f);
        if(dynamic_cast<Tree*> (List_Obj[i]))
            dynamic_cast <Tree*> (this->List_Obj[i])->print(this->f);    
    }
}

void Forest::print(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);


  for(int unsigned i=0; i < this->List_Obj.size() ;i++)
  {
    if (dynamic_cast<Tree*>(this->List_Obj[i]))dynamic_cast<Tree*>(this->List_Obj[i])->print(f);
    if (dynamic_cast<Rock*>(this->List_Obj[i]))dynamic_cast<Rock*>(this->List_Obj[i])->print(f);
  }

  if (p1 != NULL) p1->print(f);
  if (p2 != NULL) p2->print(f);

    
   SDL_RenderPresent(renderer);
} 


Forest::~Forest()
{
    delete p1;
    delete p2;
}
