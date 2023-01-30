#include "iostream"
#include "ctime"
#include "cstdlib"
#include "vector"
#include "limits"
#include "algorithm"


//Using Vector to check if the number is the same after new assigned
bool isInVec(unsigned int key, std::vector<unsigned int> tempVec){
    for(int i = 0; i < tempVec.size() ; i++){
        if(key == tempVec.at(i)){
            return true;
        }
    }
    return false;
}


//Bool check OutOfbound user input number that have to be large then 1 and not out of range
bool outOfBounds(unsigned int userInput, unsigned int range){
    if(userInput < 1 || userInput > range){
        return true;
        }
    return false;
}

//Function to print out array of number
void printArr(unsigned int arr[], unsigned int size) {
    for(int i = 0; i < size - 2; i++) {
        std::cout << arr[i] << " ";
    }
}
void printLuckyNum(unsigned int arr[], unsigned int size){
    for(int i = 5; i < size; i++){
        std::cout << arr[i] << " ";
    }
}
void inputNumOnly(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main() {
   
//Initialize 
    const unsigned int winSIZE = 7;
    const unsigned int luckySIZE = 2;
    unsigned int winNums[winSIZE];
    unsigned int userNums[winSIZE];
    const unsigned int mainBallRange = 50;
    const unsigned int luckyBallRange = 12;
    bool won = true;

    // std::ofstream outfile("winNums.txt");

    //Initialize Vector to store number
    std::vector<unsigned int> temp;
    std::vector<unsigned int> luckyTemp;
    std::vector<unsigned int> winTemp;
    std::vector<unsigned int> luckyWinTemp;
    std::vector<unsigned int> mainNum;
    std::vector<unsigned int> luckyNum;

    
    //Seed random number to time so that the number is randomized
    std::srand((unsigned int) (std::time(nullptr)));


    /*GENERATE WINNING NUM*/

    //Loop through winSIZE of 5 then assign random number ranging from 1-50
    
    int start = clock();
    
    for(int i = 0; i < winSIZE - 2 ; i++) {
        winNums[i] = rand() % 50 + 1;
        //checking if number is in vector or not if it is, assign new random number
        while(isInVec(winNums[i], winTemp)){
            winNums[i] = rand() % 50 + 1;
        }
        //then push the number into vector
        winTemp.push_back(winNums[i]);
    }
    //assign random lucky number ranging from 1-12
    for(int i = 5; i < winSIZE; i++){
        winNums[i] = rand() % 12 + 1;
        
        while(isInVec(winNums[i], luckyWinTemp)){
            winNums[i] = rand() % 12 + 1;
        }
        
        luckyWinTemp.push_back(winNums[i]);
    }

    int end = clock();

    std:: cout<< "it took" << end - start << "ticks or" << ((float) end - start)/CLOCKS_PER_SEC << "seconds.\n";

    std::cout<< "Winning Number: ";

    printArr(winNums, winSIZE);
    std::cout << "\n";

    std::cout << "Lucky Number: ";

    printLuckyNum(winNums, winSIZE);
    std::cout << "\n";

    // printArrToFile(winNums, winSIZE, outfile);


    std::cout << "Please Enter 5 unique numbers ranging from 1-50 and 2 lucky numbers ranging from 1-12" << "\n";

    /*USER INPUT */

    //Loop through winSIZE of 5 then get userInput for the first 5 number 
    for(int i = 0; i < winSIZE - 2; i++){
        std::cout << "Number " << i + 1 << ": ";
        std::cin >> userNums[i];

        // //while loop to check if userInput number is the same or out of bound then let user re-input the number
        while(isInVec(userNums[i], temp) || outOfBounds(userNums[i], mainBallRange)){
            std::cout<< "please do not enter duplicate or out of range number" << "\n";
            std::cout<< "please re-enter choice " << i + 1 <<": ";
            inputNumOnly();
            std::cin>>userNums[i];
        }
       
       //Push userInput to vector
        temp.push_back(userNums[i]);
    }

    //user lucky number input
    for(int i = 5; i < winSIZE; i++){
        std::cout << "Lucky Number" << i + 1 << ": ";
        std::cin >> userNums[i];
        while(isInVec(userNums[i], luckyTemp) || outOfBounds(userNums[i], luckyBallRange)){
            std::cout<< "please do not enter duplicate or out of range number" << "\n";
            std::cout<< "Please re-enter lucky number"<<i + 1 << ": ";
            inputNumOnly();
            std::cin>>userNums[i];
        }
        luckyTemp.push_back(userNums[i]);
    }
    
    std::set_intersection(
                            winTemp.begin(), winTemp.end(), 
                            temp.begin(), temp.end(), 
                            std::back_inserter(mainNum));
    std::set_intersection(
                            luckyWinTemp.begin(), luckyWinTemp.end(), 
                            luckyTemp.begin(), luckyTemp.end(), 
                            std::back_inserter(luckyNum));


    std::cout<< "Matched Main Number: ";
    std::cout<< mainNum.size() << "\n";
    std::cout<< "Matched Lucky Number: ";
    std::cout<< luckyNum.size() << "\n";

    if(mainNum.size() == 2 && luckyNum.size() == 0){
        std::cout << "You win \u20AC2.10";
    }
    if(mainNum.size() == 3 && luckyNum.size() == 0){
        std::cout << "You win \u20AC4.10";
    }
    if(mainNum.size() == 4 && luckyNum.size() == 0){
        std::cout << "You win \u20AC13.20";
    }
     if(mainNum.size() == 5 && luckyNum.size() == 0){
        std::cout << "You win \u20AC5,042.10";
    }
     if(mainNum.size() == 2 && luckyNum.size() == 1){
        std::cout << "You win \u20AC4.00";
    }
    if(mainNum.size() == 1 && luckyNum.size() == 2){
        std::cout << "You win \u20AC6.40";
    }
    if(mainNum.size() == 2 && luckyNum.size() == 2){
        std::cout << "You win \u20AC12.90";
    }
    if(mainNum.size() == 3 && luckyNum.size() == 1){
        std::cout << "You win \u20AC7.10";
    }
    if(mainNum.size() == 3 && luckyNum.size() == 2){
        std::cout << "You win \u20AC48.60";
    }
    if(mainNum.size() == 4 && luckyNum.size() == 1){
        std::cout << "You win \u20AC63.00";
    }
    if(mainNum.size() == 4 && luckyNum.size() == 2){
        std::cout << "You win \u20AC1,160.80";
    }
    if(mainNum.size() == 5 && luckyNum.size() == 1){
        std::cout << "You win \u20AC91,688.80";
    }
    if(mainNum.size() == 5 && luckyNum.size() == 2){
        std::cout << "You hit the Jackpot";
    }
}