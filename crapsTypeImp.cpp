/*
Description: The program will use class declarations in the 
header file, by implimanting the function to run a craps
game. the class discribtions can be called in main and
the program will run using rand number geberation for the dies.
Input: The input file would be user input of money,
how much will be used as stake for the craps game. 
Output: the output will show the results on the roll
the amount of money won and if the condition for lossing 
or wining have been met, as well as show a display of 
the roll outcomes 
*/

#include <iostream>
#include <cstdlib>
#include "crapsType.h" //header libraray for class 
using namespace std; 

crapsType::crapsType(){
    //initializing variables to zero and boool to true
    originalStake = 0; 
    cashOnHand =0; 
    display = true; 
    die1 = 0; 
    die2 = 0; 
    nickName= " "; 

}
//to prompt user input for a stake amount 
void crapsType::readStake(){
   
   do{
       //prompt statment 
        cout << "Enter Stake Amount: ";
        cin >> originalStake; 
        while(originalStake < MINSTAKE || originalStake > MAXSTAKE){
            //error check to see if correct input  
            cout << "Error, invalid entry." 
            << "Must be between 50 and 10000 inclusive.\n";
            cout << "Please re-enter.\n"; 
            cout << "Enter Stake Amount: ";
            cin >> originalStake; 
            cout << endl; 
   
           
        }
        //settign the orginal stake as cash onhand 
        cashOnHand=originalStake;
        //condition for the loop 
    }while(!(originalStake>= MINSTAKE || originalStake <= MAXSTAKE));

}
//function to set the stake and make sure its within range 
//in addition to setting the stake to equal what the orginal stake is 
//as well as making it equal to the cash on hand, so you have a 
//uptodate count of the current blance as the game is played 
void crapsType::setStake(int stake){
    if(stake >= MINSTAKE && stake <= MAXSTAKE){
        originalStake=stake;
        cashOnHand=originalStake; 
        //making sure the first stake is == cash on hand 
    }
    else {
        cout<< "Error, Invalid Stake Amount\n"; 
    }

}
//retunring orginal stake, which is now the same as 
//the cash on hand, so that the game can continue 
int crapsType::getStake() const{
    
    
    return originalStake; 

}
//returning the current blance as cash on hand 
int crapsType::getCurrentBalance () const{
    
    return cashOnHand; 
}
/*checks to see if the diplay function is on or off 
so the input can be used in main based on whats 
is selcted. if the show is flase, the display will 
also be turned off, only showing reults*/
void crapsType::setDisplay(bool show){

    if(show == true){
        display=show;

    }
    else if (show == false){
        display=show; 
        //display=false; 
    }

}

//function to show what each rand roll results as 
/* the function takes in the input from the playcraps function 
after the numbers from die1 and die2 have been randmozied 
adding them to come up with a sum, which than is uesed by the 
switch statment to come up with the proper response. Showing what 
nickname to print in accordance to what the sum of the roll is*/
void crapsType::displayRoll(int die1, int die2){
    //the sume of the dies rolled determines wining conditon
    int sum = die1 + die2;
    
    //switch to check wining conditions 
    switch (sum)
        {
       
        case 2: //declaring nickname and printing each indvidual die 
            nickName = " Snake Eyes"; 
            cout << "Die 1: " << die1 <<"  "<<" Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName << endl;
            break; 
        
        case 3:
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed
            nickName = " Ace Deuce";
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName << endl;
            
            break; 
        case 4:
            //declaring nickname and printing each indvidual die 
            //chehcking for two diff outputs for the same result
            if(die1==2 && die2==2){
            nickName = " Hard Four "; 
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName << endl;  
            break;
            }
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed
            else{
            nickName =" Easy Four ";
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName <<endl;
            break;
            }             
           //declaring nickname and printing each indvidual die 
        case 5:
            //chehcking to make sure the right statement is printed
            nickName = " Fever Five "; 
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName <<endl;  
            break;    
        case 6:
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed
            if (die1==3 && die2==3){
            nickName = " Hard Six "; 
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName << endl;  
            break;
            }
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed
            else{
            nickName =" Easy Six ";
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName <<endl;
            break;
            }  
            //declaring nickname and printing each indvidual die 
        case 7:    
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed
            nickName= " Seven Out"; 
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName << endl;
            break;
        case 8:
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed
            if( die1==4 && die2==4 ){
            nickName = " Hard Eight ";
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName << endl;  
            break;
            }
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed
            else{
            nickName =" Easy Eight ";
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName <<endl;
            break;
            }
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed 
        case 9:
            nickName = " Nina ";
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum <<  "  " <<nickName<<endl;  
            break;
        case 10:
            //declaring nickname and printing each indvidual die 
             //chehcking to make sure the right statement is printed
            if (die1==5 && die2==5){
            nickName = " Hard Ten "; 
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName <<endl;  
            break; 
            } 
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed
            else{
            nickName =" Easy Ten ";
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName <<endl;
            break;
            }             
            //break;
        case 11:
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed
            nickName = " Yo-leven"; 
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum << "  " <<nickName << endl;
            break; 
        case 12: 
            //declaring nickname and printing each indvidual die 
            //chehcking to make sure the right statement is printed
            nickName = " Boxcars";
            cout << "Die 1: " << die1 <<"  "<<"Die 2: "
            <<die2<<" Sum: "<<
            sum <<"  " <<nickName << endl;
            break; 
        default:
            //return true;
            cout << "Error\n"; 
            break;
        }      
 
}
/*the function that actually plays the game 
based ont he rolls, and checking the winning conditions of 
the game, it will look at how many turns have passed 
as well, in addition to chehcking for erros, within the bet 
range*/
bool crapsType::playCraps(int bet){
    int point =0; 
    //to count how many rolls occur 
    int roll = 1; 
   //make sure the bet is within min and max range 
   if(bet < MINBET || bet > MAXBET){
            cout << "Error, Invalid Bet\n"; 
            return false; 
        }
    //condtion chehcking if the game is on 
    while(true){ 
        
        //randmaziation of the die rolls based on seed 
        die1=(rand()%6+1); 
        die2=(rand()%6+1);  
        
        //calling the die roll private function 
        if (display== true){
        displayRoll(die1,die2);
        }
        //addition of die rolls 
        int sum = die1 + die2;
        
        //conditon for the first roll 
        if(roll == 1){
            //statment to check if won in the first roll
            if(sum == 7 || sum==11){
                //when wining increase the cash on hand by the bet 
                cashOnHand+= bet;
                return true; 
                //break; 
            }
            //condtion for losing 
            if (sum == 2 || sum==3 || sum==12){
                //when losing, decrease the cash on hand by the bet 
                cashOnHand-=bet;
                return false; 
            }
            //condition for point distrabution 
            if(sum == 4 || sum==5 || sum==6 
            || sum==8 || sum==9 || sum==10){
                //assigning the points 
                point =sum;
                //checking to print points only for display 
                if(display==true){
                cout <<"point: " <<point << endl; 
                }
            } 
            roll = roll + 1; 
        }
        else{
            //ssecondary chechk for wining conditions 
            if(sum == point){
                cashOnHand += bet; 
                /*only print out the win statment if the condition 
                showing the display are met other wise to not print it*/
                if(display == true){
                    cout << "Won\n";
                    cout << "Current Balance: $" << cashOnHand <<endl; 
                    cout << "---------------------------\n";
                }
                return true; 
                break;
            }
            //secondary chechk for other types of lossing condition
            if(sum==7){
                //when losing, decrease the cash on hand by the bet 
                cashOnHand-=bet;  
                /*only print out the win statment if the condition 
                showing the display are met other wise to not print it*/
                if(display == true){
                    cout<<"Loss\n";
                }
                return false; 
                break;
            }
        }
    }
    
}
