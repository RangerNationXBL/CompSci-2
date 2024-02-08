#include <iostream>

int masterAccountBalance = 0;
int projectBalances[10] = {0};
void userFunction(){
    int userID, numCopies;

    std::cout << "Enter userID and number of copies: ";
    std::cin >> userID >> numCopies;

    if(userID >= 1 && userID <= 10){
        projectBalances[userID - 1] += numCopies;
        std::cout << "Copies added tp project " << (userID) << std::endl;
    }else{
        std::cout << "Invalid userID" << std::endl;
    }
}

void adminFunction(){
    char adminChoice;

    do{
        std::cout << "B)alance M)aster A)dmin" << std::endl;
        std::cout<< "Enter your choice: ";
        std::cin >> adminChoice;

        switch(toupper(adminChoice)){
            case 'B':
                std::cout << "Master Account Balance: " << masterAccountBalance << std::endl;
                for(int i = 0; i < 10; i++){
                    std::cout << "Project " << (i + 1) << " Balance: " << projectBalances[i] << std::endl;
                }
                break;
            /* more cases */
        }
    }while (toupper(adminChoice)!= 'Q');
    
    
}

int main(){
    userFunction();
    adminFunction();
}