//
// Created by ulgeo on 10.09.2021.
//
#define  _CRT_SECURE_NO_WARNINGS

#ifndef CREST_GAME_H
#define CREST_GAME_H

#endif //CREST_GAME_H

#include "stdio.h"
#include "printer.h"
#define vert (char)186
#define gor (char)205
#define lu_ug (char)201
#define ld_ug (char)200
#define ru_ug (char)187 
#define rd_ug (char)188
#define prob ' '
#define krest (char)206
#define kr_r (char)185
#define kr_d (char)202

char name1[21];
char name2[21];

short int gameData[3][3];
short int filled[3][3];
int drawn = 0;
const char field_c[8][16] = {
        {prob, prob, prob, vert,  prob, 'A', prob,  vert,  prob, 'B', prob,  vert,  prob, 'C',  prob, vert },
        {gor,  gor,  gor,  krest, gor,  gor,  gor,  krest, gor,  gor,  gor,  krest, gor,  gor,  gor,  kr_r },
        {prob, '1',  prob, vert,  prob, ' ', prob,  vert,  prob, ' ', prob,  vert,  prob, ' ',  prob, vert },
        {gor,  gor,  gor,  krest, gor,  gor,  gor,  krest, gor,  gor,  gor,  krest, gor,  gor,  gor,  kr_r },
        {prob, '2',  prob, vert,  prob, ' ', prob,  vert,  prob, ' ', prob,  vert,  prob, ' ',  prob, vert },
        {gor,  gor,  gor,  krest, gor,  gor,  gor,  krest, gor,  gor,  gor,  krest, gor,  gor,  gor,  kr_r },
        {prob, '3',  prob, vert,  prob, ' ', prob,  vert,  prob, ' ', prob,  vert,  prob, ' ',  prob, vert },
        {gor,  gor,  gor,  kr_d,  gor,  gor,  gor,  kr_d,  gor,  gor,  gor,  kr_d,  gor,  gor,  gor,  rd_ug},
};

int gameStarted = 0;

int hod1 = 1;
/// <summary>
/// обнуление поля
/// </summary>
void setGame() 
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            drawn = 0;
            filled[i][j] = -1;
            gameData[i][j] = -1;
        }
    }
}

/// <summary>
/// Проверка на окончание игры
/// </summary>
/// <returns>-1, если игра не окончена; 0 - если выиграли Нолики; 1 - если выиграли Крестики</returns>
int checkWin()
{
    for (int i = 0; i < 3; i++) // проверка по горизонтали
    {
        if (gameData[i][0] == gameData[i][1] && gameData[i][1] == gameData[i][2])
        {
            if (gameData[i][0] && gameData[i][0] != -1)
            {
                return 1;
            }
            else if (gameData[i][0] != -1)
            {
                return 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) // проверка по вертикали
    {
        if (gameData[0][i] == gameData[1][i] && gameData[1][i] == gameData[2][i])
        {
            if (gameData[0][i] && gameData[0][i] != -1)
            {
                return 1;
            }
            else if (gameData[0][i] != -1)
            {
                return 0;
            }
        }
    }
    if (gameData[0][0] == gameData[1][1] && gameData[1][1] == gameData[2][2]) // проверка по главной диагонали
    {
        if (gameData[0][0] && gameData[0][0] != -1)
        {
            return 1;
        }
        else if (gameData[0][0] != -1)
        {
            return 0;
        }
    }
    if (gameData[0][2] == gameData[1][1] && gameData[1][1] == gameData[2][0]) //проверка по побочной диагонали
    {
        if (gameData[0][2] && gameData[2][0] != -1)
        {
            return 1;
        }
        else if (gameData[2][0] != -1)
        {
            return 0;
        }
    }

    int draw = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameData[i][j] == -1)
            {
                draw = 0;
                break;
            }
        }
    }

    if (draw)
    {
        return 2;
    }

    return -1;
}

/// <summary>
/// Функция отрисовки/замены поля
/// </summary>
void drawField()
{
    if (!drawn)
    {
        if (hod1)
        {
            printf("Now goes: %s\n", name1);
        }
        else
        {
            printf("Now goes: %s\n", name2);
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                printf("%c", field_c[i][j]);
            }
            printf("\n");
        }
        drawn = !drawn;
    }
    else
    {
        setCurs(1, 1);
        if (hod1)
        {
            printf("Now goes: %s\n", name1);
        }
        else
        {
            printf("Now goes: %s\n", name2);
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (gameData[i][j] != filled[i][j])
                {
                    setCurs(4 + i * 2, 6 + 4 * j);
                    filled[i][j] = gameData[i][j];
                    if (gameData[i][j] == 1)
                        printf("X");
                    else
                        printf("O");
                }
            }
        }
        clearRowScreen(10);
    }
}

/// <summary>
/// Функция, принимающая и обрабатывающая ввод
/// </summary>
void round()
{
    char t = ' '; char d = ' '; int x = 0; int y = 0;
    int done = 0;
    do
    {
        char xxxxx[3]; // вспомогательный массив
        t = ' '; d = ' '; x = 0; y = 0;

        char fl = 0;
        while (!fl)
        {
            printf("Enter your move in format \'A1\'\n");
            for (int i = 0; i < 3; i++)
            {
                xxxxx[i] = NULL;
            }
            scanf("%3s%*[^\n]%*c", xxxxx);
            if (xxxxx[2] != NULL)
                printf("Format error, re-enter your move.\n");
            else
                fl = 1;
        }
        t = xxxxx[0]; d = xxxxx[1];
        if (t == 'A' || t == 'B' || t == 'C') {
            if (d == '1' || d == '2' || d == '3')
            {
                x = (int)(t - 'A');
                y = (int)(d - '1');
                if (gameData[y][x] == -1) {
                    done = 1;
                    if (hod1)
                        gameData[y][x] = 1;
                    else
                        gameData[y][x] = 0;
                    hod1 = !hod1;
                }
                else
                {
                    printf("Cell is used, re-enter your move.\n");
                }
            }
            else
            {
                printf("Format error, re-enter your move.\n");
            }
        }
        else
        {
            printf("Format error, re-enter your move.\n");
        }
    } while (!done);
}

/// <summary>
/// Функция, отвечающая за работу игры
/// </summary>
int game()
{
    setGame();

    clearScreen();

    char flag1 = 0, flag2 = 0;

    //Ввод имени первого игрока
    while (!flag1)
    {
        printf("Enter player 1 name (max 21 symbols and ONE word): ");
        for (int i = 0; i < 21; i++)
        {
            name1[i] = NULL;
        }
        scanf("%21s%*[^\n]%*c", &name1);
        if (name1[20] != NULL) 
            printf("Too long, try again\n");
        else
            flag1 = 1;
    }
    clearScreen();
    printf("Enter player 1 name (max 21 symbols and ONE word): %s\n", name1);
    
    //Ввод имени второго игрока
    while (!flag2)
    {
        printf("Enter player 2 name (max 21 symbols and ONE word): ");
        for (int i = 0; i < 21; i++)
        {
            name2[i] = NULL;
        }
        scanf("%21s%*[^\n]%*c", &name2);
        if (name2[20] != NULL)
            printf("Too long, try again\n");
        else
            flag2 = 1;
    }

    clearScreen();
    drawField();
    //игра
    if (gameStarted)
    {
        while (checkWin() == -1)
        {
            round();
            drawField();
        }
    }
    gameStarted = !gameStarted;
    clearScreen();

    //проверка на победу
    switch(checkWin())
    {
        case 0:
            printf("Won %s\n", name1);
            break;
        case 1:
            printf("Won %s\n", name2);
            break;
        case 2:
            printf("Draw\n");
            break;
        default:
            printf("Err\n");
            break;
    }

    //меню выхода
    printf("Print 1 to restart or 2 to exit\n");
    char rest = ' ';
    while ((rest != '1') || (rest != '2'))
    {
        char c[2] = { NULL, NULL };
        scanf("%2s%*[^\n]%*c", &c);
        if (c[1] == NULL) {
            rest = c[0];
            if (c[0] == '2')
            {
                return 0; // exit
            }
            else if (c[0] == '1')
            {
                return 1; //restart
            }
            else
            {
                printf("Error, try again ('1' or '2')\n");
            }
        }
        else
        {
            printf("Error, try again ('1' or '2')\n");
        }
    }

    return 0;
}