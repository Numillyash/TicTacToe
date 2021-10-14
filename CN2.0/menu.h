//
// Created by ulgeo on 10.09.2021.
//
#pragma once
#define  _CRT_SECURE_NO_WARNINGS

#ifndef CREST_MENU_H
#define CREST_MENU_H

#endif CREST_MENU_H

#include "game.h"

int isMenu = 0;
char field[8][22] =
{
				{lu_ug, gor, gor, gor, gor, gor,gor, gor, gor, gor, gor,gor, gor, gor, gor, gor,gor, gor, gor, gor, gor,ru_ug  },
				{vert, prob,prob,prob,prob,prob,prob,prob,prob,'M','e','n','u',prob,prob,prob,prob,prob,prob,prob,prob,vert    },
				{vert, prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,vert},
				{vert, prob,prob,prob,'1','.',prob,'S','t','a','r','t',prob,'g','a','m','e',prob,prob,prob,prob,vert           },
				{vert, prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,vert},
				{vert, prob,prob,prob,'2','.',prob,'E','x','i','t',prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,vert      },
				{vert, prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,prob,vert},
				{ld_ug, gor, gor, gor, gor, gor,gor, gor, gor, gor, gor,gor, gor, gor, gor, gor,gor, gor, gor, gor, gor,rd_ug  }
};

/// <summary>
/// Функция отрисовки меню
/// </summary>
void printMenu()
{

	gameStarted = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			printf("%c", field[i][j]);
		}
		printf("\n");
	}
	isMenu = !isMenu;

}

/// <summary>
/// Управление меню
/// </summary>
/// <returns></returns>
int menuInp()
{
	while (!gameStarted)
	{
		char c[2] = { NULL, NULL };
		scanf("%2s%*[^\n]%*c", &c);
		if (c[1] == NULL) {
			if (c[0] == '2')
			{
				return 0;
			}
			else if (c[0] == '1')
			{
				gameStarted = 1;
				return 1;
			}
			else
			{
				//setPos(8);
				printf("Error, try again ('1' or '2')\n");
				//setPos(8);
			}
		}
		else
		{
			//setPos(8);
			printf("Error, try again ('1' or '2')\n");
			//setPos(8);
		}
	}
}