#include <iostream>

//ходилка стрелками
// продумать изменение екрана путем его не полного, а лок обновления
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
void drawField(const int& id);
void drawGameField(const int* field, const int& SIZE, const int& movCount, int* lastTurn);
void showbackground();

//// Описание и функционал функций в core.cpp
int* genereteField(const int& SIZE);
void move(int* field, const int& SIZE, int dir);
void doStep(int* field,const int& SIZE, int& movCount, int* lastTurn);
bool isWin(const int* field, const int* wcom, const int& SIZE);

////Ф-ция игры (цикл)
void game(int* field, const int* wcom, const int& SIZE)
{
    ////счетчик ходов
    int movCount{};

    ////хранение игрового поля до хода (для выполнения локальной отрисовки игр. поля) 
    int* lastTurn = new int[SIZE]{};
    
    bool play = false;
    
    showbackground();

    drawGameField(field, SIZE, movCount, lastTurn);

    while (!play)
    {
        doStep(field, SIZE, movCount, lastTurn);
        drawGameField(field,SIZE, movCount, lastTurn);
        play = isWin(field, wcom, SIZE);
    }
 
    std::cout << "GAME OVER\n";

}

int main()
{
    const int SIZE = 16;

    ////тест
   //int* field = new int[SIZE]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,0,15};
    
    //// генерация рандомного поля
    int* field = genereteField(SIZE);
    //// победная комбинация
    int* wincom = new int[SIZE] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};

    game(field, wincom, SIZE);

	return 0;
}

