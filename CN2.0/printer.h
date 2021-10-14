//
// Created by ulgeo on 10.09.2021.
//
#define  _CRT_SECURE_NO_WARNINGS

#ifndef CREST_PRINTER_H
#define CREST_PRINTER_H

#endif //CREST_PRINTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

/// <summary>
/// Переводит курсор в начало указанной строки
/// </summary>
/// <param name="row">Номер строки</param>
void setPos(int row) {

    printf("\033[%d;%dH", row, 1);
}

/// <summary>
/// Переводит курсор консоли в заданное положение
/// </summary>
/// <param name="row">Номер строки</param>
/// <param name="column">Номер символа в строке</param>
void setCurs(int row, int column)
{
    printf("\033[%d;%dH", row, column);
}

/// <summary>
/// Чистит консоль начиная со строки
/// </summary>
/// <param name="row">Номер строки</param>
void clearRowScreen(int row)
{
    printf("\033[%d;%dH", row, 1);
    printf("\033[J", row, 1);
}

/// <summary>
/// Полностью очищает консоль
/// </summary>
void clearScreen()
{
    printf("\033[H\033[J");
}