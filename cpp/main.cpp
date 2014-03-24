/* 
 * File:   main.cpp
 * Author: sig2
 *
 * Created on 21 March 2014, 17:04
 */

#include <cstdlib>
#include <string>
#include <iostream>

#include "FileParser.h"
#include "Stream.h"
#include "Controller.h"
using namespace std;


int main(int argc, char** argv) {
   Controller *c = new Controller();
   c->run();

   
    return 0;
}
