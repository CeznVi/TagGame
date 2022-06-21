#include <iostream>

// продумать изменение екрана путем его не полного, а лок обновления
// сделать проверку на выграш
// таблица аччивок на ТОП5 с сохранением на диске
// Запрос имени пользователя для топ 5
// сохранение игры при выходе спрашивать
// загрузка игры при старте спрашивать
// запилить заставку на старте 

//Cписок движения
enum Move {
    Up = 1,
    Down = 2,
    Left = 3,
    Rigth = 4,
};

//список цветов
enum ConsoleColor
{
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    Lightblue, LightGreen, Lightcyan, LightRed, LightMagenta, Yellow, White
};

//// Описание и функционал функций в visualization.cpp
void setColor(int text, int background = ConsoleColor::Black);
void setPos(short X, short Y);
void showMessage(std::string message, ConsoleColor color = ConsoleColor::White);
int convIdtoY(int id);
int convIdtoX(int id);
void draw1(int id);
void draw2(int id);
void draw3(int id);
void draw4(int id);
void draw5(int id);
void draw6(int id);
void draw7(int id);
void draw8(int id);
void draw9(int id);
void draw10(int id);
void draw11(int id);
void draw12(int id);
void draw13(int id);
void draw14(int id);
void draw15(int id);
void whichNumDraw(const int& id, const int& num);
void drawField(const int& id);
void drawGameField(const int* field, const int& SIZE);


//// Описание и функционал функций в core.cpp
int randInt(int min, int max);
int* genereteField(const int& SIZE);
int whereIs0(const int* field, const int& SIZE);
void showpole(const int* field, const int& SIZE);
void move(int* field, const int& SIZE, int dir);
void doStep(int* field, const int& SIZE);



////Ф-ция игры (цикл)
void game(int* field, const int& SIZE)
{
    while (true)
    {
        
        drawGameField(field, SIZE);
        
        doStep(field, SIZE);
        system("cls");
        
        drawGameField(field, SIZE);
    }

}

int main()
{
    const int SIZE = 16;

    ////тест
   // int* field = new int[SIZE]{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    
    //// рабочий вариант
    int* field = genereteField(SIZE);

    game(field, SIZE);

	return 0;
}