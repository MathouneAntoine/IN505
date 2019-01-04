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
Character& Forest::getP1Ref(){return *p1;}
Character& Forest::getP2Ref(){return *p2;}

Field Forest::getField(){return this->f;}

Objects* Forest::getObj(int i){

  return this->List_Obj[i];
}

void Forest::setP1(Character* c){ this->p1=c;}
void Forest::setP2(Character* c){ this->p2=c;}

vector<Objects*> Forest::getList()
{
  return this->List_Obj;
}
vector<Objects*>& Forest::getListPtr()
{
  return List_Obj;
}

void Forest::addList(Objects* o)
{
 List_Obj.push_back(o);
}

void Forest::eraseList(int i)
{
 List_Obj.erase(List_Obj.begin()+i);
}

void Forest::init_forest()
{
  for (int i=0; i< List_Obj.size(); i++)
  {
    std::cout << List_Obj[i]->getType() << std::endl;
    if(dynamic_cast<Rock*> (List_Obj[i]))
      dynamic_cast <Rock*> (this->List_Obj[i])->print(this->f);
    if(dynamic_cast<Tree*> (List_Obj[i]))
      dynamic_cast <Tree*> (this->List_Obj[i])->print(this->f);    
  }
}

void Forest::print(SDL_Renderer *renderer, int i)
{
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);


  for(int unsigned j=0; j < this->List_Obj.size() ;j++)
  {
    if (dynamic_cast<Tree*>(this->List_Obj[j]))dynamic_cast<Tree*>(this->List_Obj[j])->print(f);
    if (dynamic_cast<Rock*>(this->List_Obj[j]))dynamic_cast<Rock*>(this->List_Obj[j])->print(f);
  }

  if (i==0)
  {
    if (p1 != NULL) p1->print(f);
    if (p2 != NULL) if(visible()==true)  p2->print(f);
  }

  if (i==1)
  {
    if (p1 != NULL) if(visible()==true)  p1->print(f);
    if (p2 != NULL)  p2->print(f);
  }
  
  if (i==2)
  {
    if (p1!=NULL)p1->print(f);
    if (p2!=NULL)p2->print(f);
  }


  SDL_RenderPresent(renderer);
} 

bool Forest::visible()
{
  bool visible=true;
  Objects* obj=NULL;

  float m=0;
  float b=0;

  float p2_x=p2->getForme()->getCenter().getX();
  float p1_x=p1->getForme()->getCenter().getX();
  float p2_y=p2->getForme()->getCenter().getY();
  float p1_y=p1->getForme()->getCenter().getY();
  for(int unsigned i=0; i < List_Obj.size() && visible !=false ;i++)
  {
    obj=getObj(i);
    int obj_x=obj->getCenter().getX();
    int obj_y=obj->getCenter().getY();
    int obj_d=obj->getDiameter()/2;
    int obj_h=obj->getHeight()/2;

    if(p1_x<p2_x && ((obj_x-obj_d<p2_x && obj_x-obj_d>p1_x)||(obj_x+obj_d<p2_x && obj_x+obj_d>p1_x)) &&
          ((obj_y-obj_h<p2_y && obj_y-obj_h>p1_y) ||  (obj_y+obj_h<p2_y && obj_y+obj_h>p1_y) ||
           (obj_y-obj_h>p2_y && obj_y-obj_h<p1_y) ||  (obj_y+obj_h>p2_y && obj_y+obj_h<p1_y) || 
           (obj_y+obj_h>p1_y && obj_y+obj_h>p2_y && obj_y-obj_h<p1_y && obj_y-obj_h<p2_y)))
    {
      cout<< "ici"<<endl;
        int dhd=((p2_x-p1_x)*((obj_y-obj_h)-p1_y))-((p2_y-p1_y)*((obj_x+obj_d)-p1_x));
        int dbd=((p2_x-p1_x)*((obj_y+obj_h)-p1_y))-((p2_y-p1_y)*((obj_x+obj_d)-p1_x));

        int dhg=((p2_x-p1_x)*((obj_y-obj_h)-p1_y))-((p2_y-p1_y)*((obj_x-obj_d)-p1_x));
        int dbg=((p2_x-p1_x)*((obj_y+obj_h)-p1_y))-((p2_y-p1_y)*((obj_x-obj_d)-p1_x));

        if((dhd<0 && dbd>0) || (dhg<0 && dbg>0) || (dhd<0 && dbg>0) || (dhg<0 && dbd>0))visible=false; 
    }

    if(p1_x>=p2_x && ((obj_x-obj_d>p2_x && obj_x-obj_d<p1_x) ||  (obj_x+obj_d>p2_x && obj_x+obj_d<p1_x)) &&
          ((obj_y-obj_h<p2_y && obj_y-obj_h>p1_y) ||  (obj_y+obj_h<p2_y && obj_y+obj_h>p1_y) ||
           (obj_y-obj_h>p2_y && obj_y-obj_h<p1_y) ||  (obj_y+obj_h>p2_y && obj_y+obj_h<p1_y) || 
           (obj_y+obj_h>p1_y && obj_y+obj_h>p2_y && obj_y-obj_h<p1_y && obj_y-obj_h<p2_y)))   
    {
        int dhd=((p1_x-p2_x)*((obj_y-obj_h)-p2_y))-((p1_y-p2_y)*((obj_x+obj_d)-p2_x));
        int dbd=((p1_x-p2_x)*((obj_y+obj_h)-p2_y))-((p1_y-p2_y)*((obj_x+obj_d)-p2_x));

        int dhg=((p1_x-p2_x)*((obj_y-obj_h)-p2_y))-((p1_y-p2_y)*((obj_x-obj_d)-p2_x));
        int dbg=((p1_x-p2_x)*((obj_y+obj_h)-p2_y))-((p1_y-p2_y)*((obj_x-obj_d)-p2_x));

        if((dhd<0 && dbd>0) || (dhg<0 && dbg>0) || (dhd<0 && dbg>0) || (dhg<0 && dbd>0))visible=false; 
    }
 }
return visible;
}


Forest::~Forest()
{
  cout << "Destructeur Forest "<<  endl;

  if(p1!=NULL) delete p1;
  if(p2!=NULL)delete p2;
  
}
