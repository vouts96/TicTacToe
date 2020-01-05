#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <limits>
#include <ios>
using namespace std;

char gameMap[11][11];

void initializeGameMap(){
    int i, j;

    for(i=0; i<11; i++){
        for(j=0; j<11; j++){
            gameMap[i][j] = ' ';
        }
    }
    gameMap[0][3] = 179; // 179 = | box drawing vertical line
    gameMap[0][7] = 179;
    gameMap[1][3] = 179;
    gameMap[1][7] = 179;
    gameMap[2][3] = 179;
    gameMap[2][7] = 179;
    gameMap[3][0] = 196; // 196 = - box drawing horizontal line
    gameMap[3][1] = 196;
    gameMap[3][2] = 196;
    gameMap[3][3] = 197; // 180 = -|- box drawing vertical and horizontal line
    gameMap[3][4] = 196;
    gameMap[3][5] = 196;
    gameMap[3][6] = 196;
    gameMap[3][7] = 197;
    gameMap[3][8] = 196;
    gameMap[3][9] = 196;
    gameMap[3][10] = 196;
    gameMap[4][3] = 179;
    gameMap[4][7] = 179;
    gameMap[5][3] = 179;
    gameMap[5][7] = 179;
    gameMap[6][3] = 179;
    gameMap[6][7] = 179;
    gameMap[7][0] = 196; // 196 = - box drawing horizontal line
    gameMap[7][1] = 196;
    gameMap[7][2] = 196;
    gameMap[7][3] = 197; // 180 = -|- box drawing vertical and horizontal line
    gameMap[7][4] = 196;
    gameMap[7][5] = 196;
    gameMap[7][6] = 196;
    gameMap[7][7] = 197;
    gameMap[7][8] = 196;
    gameMap[7][9] = 196;
    gameMap[7][10] = 196;
    gameMap[8][3] = 179;
    gameMap[8][7] = 179;
    gameMap[9][3] = 179;
    gameMap[9][7] = 179;
    gameMap[10][3] = 179;
    gameMap[10][7] = 179;

}

void displayGameMap(){
    int i, j;

    for(i=0; i<11; i++){
        cout << "\t";
        for(j=0; j<11; j++){
            cout << gameMap[i][j];
        }
        cout << endl;
    }
}

class cell{
public:
    char cellArr[3][3];
    char moveElement;
    cell *down;
    cell *left;
    cell *right;
    cell *up;


    cell(){
        int i, j;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                cellArr[i][j] = ' ';
            }
        }

        moveElement = cellArr[1][1];
        down = NULL;
        left = NULL;
        right = NULL;
        up = NULL;
    }

    void goToCell(cell *c){
        c->cellArr[0][0] = 218;
        c->cellArr[0][1] = 196;
        c->cellArr[0][2] = 191;
        c->cellArr[1][0] = 179;
        c->cellArr[1][2] = 179;
        c->cellArr[2][0] = 192;
        c->cellArr[2][1] = 196;
        c->cellArr[2][2] = 217;
    }

    void leaveFromCell(cell *c){
        c->cellArr[0][0] = ' ';
        c->cellArr[0][1] = ' ';
        c->cellArr[0][2] = ' ';
        c->cellArr[1][0] = ' ';
        c->cellArr[1][2] = ' ';
        c->cellArr[2][0] = ' ';
        c->cellArr[2][1] = ' ';
        c->cellArr[2][2] = ' ';
    }

    void connect9cells(cell *c1, cell *c2, cell *c3, cell *c4, cell *c5, cell *c6, cell *c7, cell *c8, cell *c9){
        c1->down = c4;
        c1->left = NULL;
        c1->right = c2;
        c1->up = NULL;

        c2->down = c5;
        c2->left = c1;
        c2->right = c3;
        c2->up = NULL;

        c3->down = c6;
        c3->left = c2;
        c3->right = NULL;
        c3->up = NULL;

        c4->down = c7;
        c4->left = NULL;
        c4->right = c5;
        c4->up = c1;

        c5->down = c8;
        c5->left = c4;
        c5->right = c6;
        c5->up = c2;

        c6->down = c9;
        c6->left = c5;
        c6->right = NULL;
        c6->up = c3;

        c7->down = NULL;
        c7->left = NULL;
        c7->right = c8;
        c7->up = c4;

        c8->down = NULL;
        c8->left = c7;
        c8->right = c9;
        c8->up = c5;

        c9->down = NULL;
        c9->left = c8;
        c9->right = NULL;
        c9->up = c6;
    }

    void makeMove(cell *c, char m){
        c->cellArr[1][1] = m;
        c->moveElement = c->cellArr[1][1];
    }

    void _9cellsToMap(cell c1, cell c2, cell c3, cell c4, cell c5, cell c6, cell c7, cell c8, cell c9){
        int i, j;
        int ROWfactor, COLfactor;

        // c1
        ROWfactor = 0;
        COLfactor = 0;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                gameMap[i+ROWfactor][j+COLfactor] = c1.cellArr[i][j];
            }
        }

        //c2
        ROWfactor = 0;
        COLfactor = 4;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                gameMap[i+ROWfactor][j+COLfactor] = c2.cellArr[i][j];
            }
        }

        //c3
        ROWfactor = 0;
        COLfactor = 8;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                gameMap[i+ROWfactor][j+COLfactor] = c3.cellArr[i][j];
            }
        }

        // c4
        ROWfactor = 4;
        COLfactor = 0;
        for(i=0; i<3; i++){
            for(j=0; j<3;j++){
                gameMap[i+ROWfactor][j+COLfactor] = c4.cellArr[i][j];
            }
        }

        // c5
        ROWfactor = 4;
        COLfactor = 4;
        for(i=0; i<3; i++){
            for(j=0; j<3;j++){
                gameMap[i+ROWfactor][j+COLfactor] = c5.cellArr[i][j];
            }
        }

        // c6
        ROWfactor = 4;
        COLfactor = 8;
        for(i=0; i<3; i++){
            for(j=0; j<3;j++){
                gameMap[i+ROWfactor][j+COLfactor] = c6.cellArr[i][j];
            }
        }

        // c7
        ROWfactor = 8;
        COLfactor = 0;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                gameMap[i+ROWfactor][j+COLfactor] = c7.cellArr[i][j];
            }
        }

        // c8
        ROWfactor = 8;
        COLfactor = 4;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                gameMap[i+ROWfactor][j+COLfactor] = c8.cellArr[i][j];
            }
        }

        // c9
        ROWfactor = 8;
        COLfactor = 8;
        for(i=0; i<3; i++){
            for(j=0; j<3;j++){
                gameMap[i+ROWfactor][j+COLfactor] = c9.cellArr[i][j];
            }
        }
    }

    void displayCell(cell c){
        int i, j;

        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                cout << c.cellArr[i][j];
            }
            cout << endl;
        }
    }

    bool weHaveWinner(cell *c1, cell *c2, cell *c3, cell *c4, cell *c5, cell *c6, cell *c7, cell *c8, cell *c9, char m){
        if((c1->moveElement == m) && (c2->moveElement == m) &&(c3->moveElement == m)) return true;
        else if((c4->moveElement == m) && (c5->moveElement == m) &&(c6->moveElement == m)) return true;
        else if((c7->moveElement == m) && (c8->moveElement == m) &&(c9->moveElement == m)) return true;
        else if((c1->moveElement == m) && (c4->moveElement == m) &&(c7->moveElement == m)) return true;
        else if((c2->moveElement == m) && (c5->moveElement == m) &&(c8->moveElement == m)) return true;
        else if((c3->moveElement == m) && (c6->moveElement == m) &&(c9->moveElement == m)) return true;
        else if((c1->moveElement == m) && (c5->moveElement == m) &&(c9->moveElement == m)) return true;
        else if((c3->moveElement == m) && (c5->moveElement == m) &&(c7->moveElement == m)) return true;
        return false;
    }

    bool full(cell *c1, cell *c2, cell *c3, cell *c4, cell *c5, cell *c6, cell *c7, cell *c8, cell *c9){
        if((c1->moveElement != ' ') && (c2->moveElement != ' ') && (c3->moveElement != ' ') && (c4->moveElement != ' ')
           && (c5->moveElement != ' ') && (c6->moveElement != ' ') && (c7->moveElement != ' ') && (c8->moveElement != ' ')
           && (c9->moveElement != ' ')) return true;
        else return false;
    }
};

int main(){
    string player1, player2;
    string inputTrash;
    bool gameOver;
    bool turn1, turn2;
    bool player1wins, player2wins;
    char x;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_INTENSITY);

    cell *current;
    cell c0; // administrator cell
    cell c1, c2, c3, c4, c5, c6, c7, c8, c9;
    c1.connect9cells(&c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9);
    system("cls");
    cout << "\n\t--TIC TAC TOE--\n";
    cout << "\n\n\n\tMade by Billys\n\n\n\n\n";
    system("pause");
    system("cls");
    cout << endl;
    cout << "\tGive 1st player's name: ";
    cin >> player1; // giving P1 name
    system("cls");
    cout << endl;
    cout << "\tGive 2nd player's name: ";
    cin >> player2; // giving P2 name
    system("cls");
    cout << endl;
    cout << "\t" << player1 << " VS " << player2 << endl; // printing P1 VS P2
    Sleep(2000);
    initializeGameMap(); // initializing game map

    player1wins = false;
    player2wins = false;
    gameOver = false;
    current = &c1;
    while(!gameOver){
        turn1 = true;
        while(turn1){
            //check if there are any other moves possible
            if(c0.full(&c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9)){
                gameOver = true;
                break;
            }
            while(!kbhit()){
                system("cls");
                cout << endl;
                cout << "\t" << player1 << "'s turn" << endl;
                c0.goToCell(current);
                c0._9cellsToMap(c1, c2, c3, c4, c5, c6, c7, c8, c9);
                displayGameMap(); // printing game map
                Sleep(200);
                system("cls");
                cout << endl;
                cout << "\t" << player1 << "'s turn" << endl;
                c0.leaveFromCell(current);
                c0._9cellsToMap(c1, c2, c3, c4, c5, c6, c7, c8, c9);
                displayGameMap(); // printing game map
                Sleep(200);
            }
            x = getch();
            switch(x){
                case 0x50:
                    if(current->down == NULL) break;
                    else{
                        c0.leaveFromCell(current);
                        current = current->down;
                    }
                    break;
                case 0x4B:
                    if(current->left == NULL) break;
                    else{
                        c0.leaveFromCell(current);
                        current = current->left;
                    }
                    break;
                case 0x4D:
                    if(current->right == NULL) break;
                    else{
                        c0.leaveFromCell(current);
                        current = current->right;
                    }
                    break;
                case 0x48:
                    if(current->up == NULL) break;
                    else{
                        c0.leaveFromCell(current);
                        current = current->up;
                    }
                    break;
                default:
                    break;
            }
            if(x == 0x0D){
                if(current->moveElement == ' '){
                    c0.makeMove(current, 'X');
                    turn1 = false;
                    if(c0.weHaveWinner(&c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, 'X')){
                        gameOver = true;
                        player1wins = true;
                    }
                }
            }

        }
        if(player1wins) break;
        turn2 = true;
        while(turn2){
            //check if there are any other moves possible
            if(c0.full(&c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9)){
                gameOver = true;
                break;
            }
            while(!kbhit()){
                system("cls");
                cout << endl;
                cout << "\t" << player2 << "'s turn" << endl;
                c0.goToCell(current);
                c0._9cellsToMap(c1, c2, c3, c4, c5, c6, c7, c8, c9);
                displayGameMap(); // printing game map
                Sleep(200);
                system("cls");
                cout << endl;
                cout << "\t" << player2 << "'s turn" << endl;
                c0.leaveFromCell(current);
                c0._9cellsToMap(c1, c2, c3, c4, c5, c6, c7, c8, c9);
                displayGameMap(); // printing game map
                Sleep(200);
            }
            x = getch();
            switch(x){
                case 0x50:
                    if(current->down == NULL) break;
                    else{
                        c0.leaveFromCell(current);
                        current = current->down;
                    }
                    break;
                case 0x4B:
                    if(current->left == NULL) break;
                    else{
                        c0.leaveFromCell(current);
                        current = current->left;
                    }
                    break;
                case 0x4D:
                    if(current->right == NULL) break;
                    else{
                        c0.leaveFromCell(current);
                        current = current->right;
                    }
                    break;
                case 0x48:
                    if(current->up == NULL) break;
                    else{
                        c0.leaveFromCell(current);
                        current = current->up;
                    }
                    break;
                default:
                    break;
            }
            if(x == 0x0D){
                if(current->moveElement == ' '){
                    c0.makeMove(current, 'O');
                    turn2 = false;
                    if(c0.weHaveWinner(&c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, 'O')){
                        gameOver = true;
                        player2wins = true;
                    }
                }
            }
        }
    }

    if(player1wins){
        system("cls");
        cout << "\n\t" << player1 << " is the Winner!\n";
        c0.leaveFromCell(current);
        c0._9cellsToMap(c1, c2, c3, c4, c5, c6, c7, c8, c9);
        displayGameMap(); // printing game map
        cout << "\t" << player1 << " is the Winner!\n";
        Sleep(2000);
        return 0;
    }
    if(player2wins){
        system("cls");
        cout << "\n\t" << player2 << " is the Winner!\n";
        c0.leaveFromCell(current);
        c0._9cellsToMap(c1, c2, c3, c4, c5, c6, c7, c8, c9);
        displayGameMap(); // printing game map
        cout << "\t" << player2 << " is the Winner!\n";
        Sleep(2000);
        return 0;
    }

    system("cls");
    cout << "\n\tWe have a tie.\n";
    c0.leaveFromCell(current);
    c0._9cellsToMap(c1, c2, c3, c4, c5, c6, c7, c8, c9);
    displayGameMap(); // printing game map
    cout << "\tWe have a tie.\n";
    Sleep(2000);
}


