#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iomanip>
#include "Lotto.h"



//bool check array to check if the number is inside vector when pushed if it is the same
//assign new number 
template<typename T>
bool isInVec(T key, std::vector<T> tempVec){
    for(int i = 0; i < tempVec.size(); i++){
        if(key == tempVec.at(i)){
            return true;
        }
    }
    return false;
}


//Bool check OutOfbound user input number that have to be larger then 1 and not out of range
template<typename T>
bool outOfBounds(T userInput, T range){
    if(userInput < 1 || userInput > range){
        return true;
        }
    return false;
}

//Function to print out array of number
template<typename T>
void printArr(T arr[], T size) {
    for(int i = 0; i < size - 2; i++) {
        std::cout << arr[i] << " ";
    }
}

//cin only number if not number clear and ignore
void inputNumOnly(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



int main() {
   
//Initialize 
    const int winSIZE = 7;
    const int mainSIZE = 5;
    const int luckySIZE = 2;
    int winNums[winSIZE];
    int userNums[winSIZE];
    const int mainBallRange = 50;
    const int luckyBallRange = 12;
    const double main2 = 2.10;
    const double main2luck1 = 4.00;
    const double main1luck2 = 6.40;
    const double main3 = 4.10;
    const double main3luck1 = 7.10;
    const double main2luck2 = 12.90;
    const double main4 = 13.20;
    const double main3luck2 = 48.60;
    const double main4luck1 = 63.00;
    const double main4luck2 = 1160.80;
    const double main5 = 5042.10; 
    const double main5luck1 = 91688.80;
    const double main5luck2 = 230000000.00;


    //Initialize Vector to store number
    std::vector<int> temp;
    std::vector<int> luckyTemp;

    // std::vector<int> winTemp;
    // std::vector<int> luckyWinTemp;
    // std::vector<unsigned int> mainNum;
    // std::vector<unsigned int> luckyNum;

    
    //Seed random number to time so that the number is randomized
    // std::srand((unsigned int) (std::time(nullptr)));


    /*GENERATE WINNING NUM*/

    //For loop method assign random random then push to vector

    //Loop through winSIZE of 5 then assign random number ranging from 1-50

    // for(int i = 0; i < winSIZE - 2 ; i++) {
    //     winNums[i] = rand() % mainBallRange + 1;
    //     //checking if number is in vector or not if it is, assign new random number
    //     while(isInVec(winNums[i], winTemp)){
    //         winNums[i] = rand() % mainBallRange + 1;
    //     }
    //     //then push the number into vector
    //     winTemp.push_back(winNums[i]);
    // }
    // //assign random lucky number ranging from 1-12
    // for(int i = 5; i < winSIZE; i++){
    //     winNums[i] = rand() % luckyBallRange + 1;
        
    //     while(isInVec(winNums[i], luckyWinTemp)){
    //         winNums[i] = rand() % luckyBallRange + 1;
    //     }
        
    //     luckyWinTemp.push_back(winNums[i]);
    // }

    //Using Class Lotto to Generate random number using random engine and vector

    Lotto winMainNum(mainSIZE,mainBallRange);
    Lotto winLuckyNum(luckySIZE,luckyBallRange);

    std::cout<< "Winning Number: "<< winMainNum;
    std::cout << "\n";

    std::cout << "Lucky Number: "<<winLuckyNum;
    std::cout << "\n";

    /*USER INPUT */

    std::cout << "Please Enter 5 unique numbers ranging from 1-50 and 2 lucky numbers ranging from 1-12" << "\n";

    //Loop through winSIZE of 5 then get userInput for the first 5 number 
    for(int i = 0; i < winSIZE - luckySIZE; i++){
        std::cout << "Number " << i + 1 << ": ";
        std::cin >> userNums[i];

        // //while loop to check if userInput number is the same or out of bound then let user re-input the number
        while(isInVec(userNums[i], temp) || outOfBounds(userNums[i], mainBallRange)){
            std::cout<< "please enter only number do not enter duplicate or out of range number" << "\n";
            std::cout<< "please re-enter choice " << i + 1 <<": ";
            inputNumOnly();
            std::cin>>userNums[i];
        }
       
       //Push userInput to vector
        temp.push_back(userNums[i]);
    }

    //user lucky number input
    for(int i = mainSIZE; i < winSIZE; i++){
        std::cout << "Lucky Number" << i + 1 << ": ";
        std::cin >> userNums[i];
        while(isInVec(userNums[i], luckyTemp) || outOfBounds(userNums[i], luckyBallRange)){
            std::cout<< "please enter only number do not enter duplicate, out of range number " << "\n";
            std::cout<< "Please re-enter lucky number"<<i + 1 << ": ";
            inputNumOnly();
            std::cin>>userNums[i];
        }
        luckyTemp.push_back(userNums[i]);
    }

    //sort the vector before intersect
    std::sort(temp.begin(), temp.end());
    std::sort(luckyTemp.begin(), luckyTemp.end());

    const auto mainNum{winMainNum & temp};
    const auto luckyNum{winLuckyNum & luckyTemp};
    
    std::cout<< "Matched Main Number: ";
    std::cout<< mainNum.size() << "\n";
    std::cout<< "Matched Lucky Number: ";
    std::cout<< luckyNum.size() << "\n";


    std::cout<< std::setprecision(2) << std::fixed;

//prize breakdown(checker)
   
    if(mainNum.size() == 2 && luckyNum.size() == 1){
        std::cout << "You win \u20AC"<< main2luck1;
    }
    else if(mainNum.size() == 1 && luckyNum.size() == 2){
        std::cout << "You win \u20AC"<< main1luck2;
    }
    else if(mainNum.size() == 2 && luckyNum.size() == 2){
        std::cout << "You win \u20AC"<< main2luck2;
    }
    else if(mainNum.size() == 3 && luckyNum.size() == 1){
        std::cout << "You win \u20AC"<< main3luck1;
    }
    else if(mainNum.size() == 3 && luckyNum.size() == 2){
        std::cout << "You win \u20AC"<< main3luck2;
    }
    else if(mainNum.size() == 4 && luckyNum.size() == 1){
        std::cout << "You win \u20AC"<< main4luck1;
    }
    else if(mainNum.size() == 4 && luckyNum.size() == 2){
        std::cout << "You win \u20AC"<< main4luck2;
    }
    else if(mainNum.size() == 5 && luckyNum.size() == 1){
        std::cout << "You win \u20AC"<< main5luck1;
    }
    else if(mainNum.size() == 5 && luckyNum.size() == 2){
        std::cout << std::fixed <<"You hit the Jackpot of \u20AC"<< main5luck2;
    }
    else if(mainNum.size() == 2 ){
        std::cout << "You win \u20AC"<< main2;
    }
    else if(mainNum.size() == 3 ){
        std::cout << "You win \u20AC"<< main3;
    }
    else if(mainNum.size() == 4 ){
        std::cout << "You win \u20AC"<< main4;
    }
    else if(mainNum.size() == 5 ){
        std::cout << "You win \u20AC"<< main5;
    }
    else{
        std::cout << "You Lost";
        return 0;
    }
   
}