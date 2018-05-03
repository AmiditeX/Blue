//
//  diceware.h
//  Diceware++
//
//  Created by Harsh Mistry  on 2015-10-28.
//  Copyright (c) 2015 Harsh Mistry . All rights reserved.
//

#ifndef __Diceware____diceware__
#define __Diceware____diceware__

#include <stdio.h>
#include <string>
#include <iostream>
#include <random>
#include <ctime>



//Namespaces
using namespace std;

//Data Defintions
typedef int  diceValue;
typedef int  diceRadomValue;
typedef int  diceWordCount;
typedef int  diceWordIndex;
typedef bool debugInfo;
typedef string diceWareWord;
typedef string diceWarePassword;


//Diceroll Struct
struct DICEROLL{
    
    diceValue dice_one;
    diceValue dice_two;
    diceValue dice_three;
    diceValue dice_four;
    diceValue dice_five;
    
};

//Functions
diceRadomValue RandomNumGen();
DICEROLL DRoll(DICEROLL);
diceWordIndex IndexValue(DICEROLL);
diceWareWord GetWord(diceWordIndex);
diceWarePassword GenPass(diceWordCount, debugInfo);




#endif /* defined(__Diceware____diceware__) */
