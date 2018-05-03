//
//  diceware.cpp
//  Diceware++
//
//  Created by Harsh Mistry  on 2015-10-28.
//  Copyright (c) 2015 Harsh Mistry . All rights reserved.
//

#include "diceware.h"
#include "wordlist.h"


//Generate Password (GenPass) : Consumes a number of desired words and
//     a Boolean Debug Value generates a password
//Returns : A string in the form of diceWarePassword
diceWarePassword GenPass (diceWordCount wordCount, debugInfo debugVal){
    
    //Generation variables
    DICEROLL rollStruct;
    diceWarePassword password = "";
    diceWordIndex index;
    diceWareWord counterString;
    
    for (diceWordCount counter = 1; counter < wordCount + 1; counter++) {
        
        //Roll 1 Die
        rollStruct = DRoll(rollStruct);
        
        //Get Index Value
        index = IndexValue(rollStruct);
        
        
        //Output Debug Info, only if debug val is true
        if (debugVal == true)
        {
        //Set Counter Counter String
        counterString = to_string(counter);
        
        cout << "Die #" + counterString << endl;
        cout << "---------------------" << endl;
        cout << rollStruct.dice_one << endl;
        cout << rollStruct.dice_two << endl;
        cout << rollStruct.dice_three << endl;
        cout << rollStruct.dice_four << endl;
        cout << rollStruct.dice_five << endl;
        
        //Output Index Info
        counterString = to_string(index);
        cout << "Index = " + counterString << endl;
        }
        
        
        //Get Word and append it to the password string
        password = password + " " + GetWord(index);
        
    }
    
    
    //Return Password
    return password;
}

//Get Index Value (IndexValue) : Consumes a DiceRoll and determines the corresponding
//      wordlist index using index find algorithm
//Returns : A int in the form of a diceWordIndex
diceWordIndex IndexValue(DICEROLL rollstruct){
    
    //Index Value Variables
    diceWordIndex index;
    diceWordIndex setStartValues[] = {0 , 1297, 2593, 3889, 5185, 6481};
    diceWordIndex setSecondValues[] = {0 , 216, 432, 648, 864, 1080};
    diceWordIndex setThirdValues[] = {0, 37, 73, 109, 145, 181};
    diceWordIndex setFourthValues[] = {0, 7, 13, 19, 25, 31};
    diceWordIndex setFifthValues[] = {0, 1, 2, 3, 4, 5};
    
    //Determining Starting Index Value
    index = setStartValues[rollstruct.dice_one - 1];
    
    //Incremenet Index based on the remaning dice
    index += setSecondValues[rollstruct.dice_two - 1];
    index += setThirdValues[rollstruct.dice_three - 1];
    index += setFourthValues[rollstruct.dice_four - 1];
    index += setFifthValues[rollstruct.dice_five - 1];
    
    //Return Index
    return index;
}


//Dice Roll (DRoll) : Consumes a DiceRoll struct and populates the struct
//      with 6 random dice roll values
//Returns : A Struct in the form of a DICEROLL
DICEROLL DRoll (DICEROLL rollStruct){
    
    //Populate Struct
    rollStruct.dice_one = RandomNumGen();
    rollStruct.dice_two = RandomNumGen();
    rollStruct.dice_three = RandomNumGen();
    rollStruct.dice_four = RandomNumGen();
    rollStruct.dice_five = RandomNumGen();
    
    //Return Struct
    return rollStruct;
}

//Get Word (GetWord) : Consumes a index and returns a word from the word list
diceWareWord GetWord (diceWordIndex index){
    
    //Word Variables
    diceWareWord genWord;
    
    //Get Value
    genWord = strWordList[index];
    
    return genWord;
}

//Random Number Generator (randomNumGen): returns a diceRandomValue from 1 - 6
diceRadomValue RandomNumGen (){
    
    //Random Value Varible
    diceRadomValue rndNum;

    //Get a Random Number
    random_device rGen;
    
    //Seed Num Generator
    mt19937 seedMt(rGen());
    
    //Define range
    uniform_int_distribution<> rangeDist (1, 6);
    
    
    
    //Generate Random Number
    rndNum = rangeDist(seedMt);
    
    //Return Random Value
    return rndNum;
}




