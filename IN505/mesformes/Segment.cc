
using namespace std;
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Segment.h"
#include "Point.h"
#include <cmath>

Segment::Segment(){}
//L'appel des constructeurs de p1 et p2 se fait automatiquement avec cette notation pour une classe composee
Segment::Segment(Point const& p, const double x, const double y): p1(p), p2(x, y){}
Segment::~Segment(){ cout << "destruction du segment" << endl; }
double Segment::longueur(){ return sqrt(pow(p2.getx()-p1.getx(),2) + pow(p2.gety()-p1.gety(),2)); }
bool Segment::estHorizontal(){ return p1.getx() == p2.getx(); }
bool Segment::estVertical(){ return p1.gety() == p2.gety();}
bool Segment::estSurDiagonal(){ return p1.getx() == p1.gety() && p2.getx() == p2.gety() ;}

