#include <iostream>

char optionMenu(){};

int main(){
    Admin admin;

    if (optionMenu() == 'A'){
        
        admin.adminMenu();
    }/* else if(optionMenu() == 'U'){
        User user;
        user.userMenu();
    } */

    return 0;
}

char optionMenu(){
    char option;
    std::cout << "U)ser A)dminister Q)uit" << std::endl;
    std::cin >> option;
    if (option == 'A'){
        std::cout << "You have chosen to Administer" << std::endl;
    }else if(option == 'U'){
        std::cout << "You have chosen to User" << std::endl;
    }else if (option == 'Q')
    {
        std::cout << "You have chosen to Quit" << std::endl;
        exit(0);
    }
    return option;
}

class Admin{
    public:
    Admin(){

        masterAccountBalance = 0;
        projectBalances[10] = 0;

        std::cout << "Welcome to Admin" << std::endl;
        std::cout << "----------------" << std::endl;
        std::cout << std::endl;
    }

        void adminMenu(){

            char option;
            std::cout << "B)alance M)aster P)orject" << std::endl;
            std::cin >> option;
            if (option == 'B'){ balance();}
            else if (option == 'M'){ master();}
            else if (option == 'P'){ project();}
    }
    void balance(){
        std::cout << "Master Account Balance: " << masterAccountBalance << std::endl;
            for(int i = 0; i < 10; i++){
                std::cout << "Project " << (i + 1) << " Balance: " << projectBalances[i] << std::endl;
            }
    }
    void master(){
        // Write code for the master function here
    }
    void project(){
        // Write code for the project function here
    }

    private:
        int masterAccountBalance = 0;
        int projectBalances[10];
};