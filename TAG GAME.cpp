#include <iostream>


// таблица аччивок на ТОП5 с сохранением на диске
// Запрос имени пользователя для топ 5
// сохранение игры при выходе спрашивать
// загрузка игры при старте спрашивать
// запилить заставку на старте 

//// Описание и функционал функций в core.cpp
int* genereteField(const int& SIZE);
void game(int* field, const int* wcom, const int& SIZE);


int main()
{
    const int SIZE = 16;

    ////тест
   int* field = new int[SIZE]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,0,15};
    
    //// генерация рандомного поля
    //int* field = genereteField(SIZE);
    // 
    //// победная комбинация
    int* wincom = new int[SIZE] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};

    game(field, wincom, SIZE);

	return 0;
}

