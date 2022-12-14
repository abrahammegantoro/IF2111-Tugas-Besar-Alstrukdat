#include "snakeonmeteor.h"

void red()
{
    printf("\033[1;31m");
}

void yellow()
{
    printf("\033[1;33m");
}

void green()
{
    printf("\033[0;32m");
}

void reset()
{
    printf("\033[0m");
}

boolean IsGameOver(ListSnake S, ListObstacle obstacle, int *score)
{
    Point P;
    somaddress Q;
    P = InfoPos(Head(S));
    
    Q = NextPos(Head(S));
    if (SearchObstacle(obstacle, P))
    {
        (*score) = LengthSnake(S) * 2;
        printf("          !!! Anda kalah karena menabrak obstacle !!!        \n");
        return true;
    }
    else
    {
        Point U, L, R, D;
        U = P; L = P; R = P; D = P;
        if (U.y == 0) {
            U.y = 4;
        } else {
            U.y--;
        }
        if (L.x == 0) {
            L.x = 4;
        } else {
            L.x--;
        }
        if (R.x == 4) {
            R.x = 0;
        } else {
            R.x++;
        }
        if (D.y == 4) {
            D.y = 0;
        } else {
            D.y++;
        }
        if (SearchSnake(S, U) != NilSOM && SearchSnake(S, L) != NilSOM && SearchSnake(S, R) != NilSOM && SearchSnake(S, D) != NilSOM)
        {
            (*score) = LengthSnake(S) * 2;
            printf("!!! Anda kalah karena tidak ada jalan lagi untuk bergerak !!!\n");
            return true;
        }
        else
        {
            return false;
        }
        // while (Q != NilSOM)
        // {
        //     if (PosX(P) == PosX(InfoPos(Q)) && PosY(P) == PosY(InfoPos(Q)))
        //     {
        //         return true;
        //     }
        //     Q = NextPos(Q);
        // }
    }
    return false;
}

void InitialSnake(ListSnake *S)
{
    int x, y;
    CreateEmptySnake(S);
    x = rand() % 5;
    y = rand() % 5;
    InsVLastSnake(S, MakePoint(x, y));
    for (int i = 0; i < 2; i++)
    {
        if (x > 0)
        {
            if (SearchSnake(*S, MakePoint(x - 1, y)) == NilSOM)
            {
                x--;
            }
            else
            {
                x++;
            }
        }
        else
        {
            if (y == 0)
            {
                if (SearchSnake(*S, MakePoint(x + 1, y)) == NilSOM)
                {
                    x++;
                }
                else
                {
                    y++;
                }
            }
            else
            {
                if (SearchSnake(*S, MakePoint(x, y - 1)) == NilSOM)
                {
                    y--;
                }
                else
                {
                    y++;
                }
            }
        }
        InsVLastSnake(S, MakePoint(x, y));
    }
}

void InitialFood(ListSnake S, Point *fruit, ListObstacle obstacle)
{
    int x, y;
    x = rand() % 5;
    y = rand() % 5;
    while (SearchSnake(S, MakePoint(x, y)) != NilSOM || (SearchObstacle(obstacle, MakePoint(x, y))))
    {
        x = rand() % 5;
        y = rand() % 5;
    }
    *fruit = MakePoint(x, y);
}

void InitialMeteor(Point *meteor, Point fruit, ListObstacle obstacle)
{
    int x, y;
    x = rand() % 5;
    y = rand() % 5;
    while (x == PosX(fruit) && y == PosY(fruit) || (SearchObstacle(obstacle, MakePoint(x, y))))
    {
        x = rand() % 5;
        y = rand() % 5;
    }
    *meteor = MakePoint(x, y);
}

void InitialObstacle(ListSnake S, ListObstacle *obstacle)
{
    int x, y;
    x = rand() % 5;
    y = rand() % 5;
    while (SearchSnake(S, MakePoint(x, y)) != NilSOM)
    {
        x = rand() % 5;
        y = rand() % 5;
    }
    (*obstacle).obsA = MakePoint(x, y);

    x = rand() % 5;
    y = rand() % 5;
    while (SearchSnake(S, MakePoint(x, y)) != NilSOM || SearchObstacle(*obstacle, MakePoint(x, y)))
    {
        x = rand() % 5;
        y = rand() % 5;
    }
    (*obstacle).obsB = MakePoint(x, y);

    x = rand() % 5;
    y = rand() % 5;
    while (SearchSnake(S, MakePoint(x, y)) != NilSOM || SearchObstacle(*obstacle, MakePoint(x, y)))
    {
        x = rand() % 5;
        y = rand() % 5;
    }
    (*obstacle).obsC = MakePoint(x, y);
}

void ReadInput(ListSnake *S, Point meteor, ListObstacle obstacle, int *score)
{
    printf("Masukkan input: ");
    STARTINPUT();
    Word input = currentWord;
    ADVWORD();
    if (IsInputValid(input) && EndWord)
    {
        MoveSnake(S, meteor, obstacle, input, score);
    }
    else
    {
        printf("Command tidak valid! Silahkan masukkan W/A/S/D\n");
        while (!EndWord)
        {
            ADVWORD();
        }
        ReadInput(S, meteor, obstacle, score);
    }
}

boolean IsInputValid(Word input)
{
    if (input.Length == 1)
    {
        if (input.TabWord[0] == 'W' || input.TabWord[0] == 'A' || input.TabWord[0] == 'S' || input.TabWord[0] == 'D')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void MoveSnake(ListSnake *S, Point meteor, ListObstacle obstacle, Word Input, int *score)
{
    Point P;
    P = InfoPos(Head(*S));
    if (Input.TabWord[0] == 'W')
    {
        if (PosY(P) > 0)
        {
            PosY(P)--;
        }
        else
        {
            PosY(P) = 4;
        }
    }
    else if (Input.TabWord[0] == 'S')
    {
        PosY(P) = (PosY(P) + 1) % 5;
    }
    else if (Input.TabWord[0] == 'A')
    {
        if (PosX(P) > 0)
        {
            PosX(P)--;
        }
        else
        {
            PosX(P) = 4;
        }
    }
    else if (Input.TabWord[0] == 'D')
    {
        PosX(P) = (PosX(P) + 1) % 5;
    }

    if (SearchSnake(*S, P) != NilSOM && SearchSnake(*S, P) != Tail(*S))
    {
        printf("Anda tidak dapat bergerak ke tubuh ular!\n");
        ReadInput(S, meteor, obstacle, score);
    }
    else if (IsEQPoint(P, meteor))
    {
        printf("Anda tidak dapat bergerak ke meteor!\n");
        ReadInput(S, meteor, obstacle, score);
    }
    else
    {
        InsVFirstSnake(S, P);
        DelVLastSnake(S, &P);
        if (!IsGameOver(*S, obstacle, score))
        {
            printf("Anda berhasil bergerak!\n");
        }
    }
}

void EatFruit(ListSnake *S, Point *fruit, Point Tail, ListObstacle obstacle)
{
    Point P;
    P = InfoPos(Head(*S));
    if (PosX(P) == PosX(*fruit) && PosY(P) == PosY(*fruit))
    {
        GrowSnake(S, Tail);
        InitialFood(*S, fruit, obstacle);
    }
}
void GrowSnake(ListSnake *S, Point Tail)
{
    Point P;
    P = Tail;
    InsVLastSnake(S, P);
}

void HitMeteor(ListSnake *S, Point meteor, boolean *isGameOver, int *score)
{
    if (IsEQPoint(InfoPos(Head(*S)), meteor))
    {
        *isGameOver = true;
        (*score) = (LengthSnake(*S) - 1) * 2;
    }
    else
    {
        DelPSnake(S, MakePoint(PosX(meteor), PosY(meteor)));
    }
}

boolean IsHit(ListSnake *S, Point meteor)
{
    somaddress P;
    P = SearchSnake(*S, meteor);
    if (P != NilSOM)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DisplayRow(ListSnake S, Point fruit, Point meteor, ListObstacle obstacle, int i)
{
    Point P;
    int idx;
    printf("X");
    for (int j = 0; j < 5; j++)
    {
        P = MakePoint(j, i);
        if (IsEQPoint(P, fruit))
        {
            idx = Fruit;
        }
        else if (IsEQPoint(P, meteor))
        {
            idx = Meteor;
        }
        else if (IsEQPoint(P, obstacle.obsA) || IsEQPoint(P, obstacle.obsB) || IsEQPoint(P, obstacle.obsC))
        {
            if (IsEQPoint(P, InfoPos(Head(S))))
            {
                idx = ObstacleHit;
            }
            else
            {
                idx = Obstacle;
            }
        }
        else
        {
            idx = SearchIdxSnake(S, P);
        }
        DisplayValue(idx);
        if (j < 4)
        {
            printf(":");
        }
    }
    printf("X\n");
}

void DisplayValue(int value)
{
    Word output;
    if (value == Empty)
    {
        DisplaySpace(11);
    }
    else if (value == Fruit)
    {
        output.Length = 1;
        output.TabWord[0] = 'O';
        DisplaySpace(5);
        yellow();
        PrintWord(output);
        reset();
        DisplaySpace(5);
    }
    else if (value == Meteor)
    {
        output.Length = 1;
        output.TabWord[0] = 'M';
        DisplaySpace(5);
        red();
        PrintWord(output);
        reset();
        DisplaySpace(5);
    }
    else if (value == Obstacle)
    {
        output.Length = 1;
        output.TabWord[0] = 'X';
        DisplaySpace(5);
        PrintWord(output);
        DisplaySpace(5);
    }
    else if (value == ObstacleHit)
    {
        output.Length = 1;
        output.TabWord[0] = 'X';
        DisplaySpace(5);
        red();
        PrintWord(output);
        reset();
        DisplaySpace(5);
    }
    else if (value == SnakeHead)
    {
        output.Length = 1;
        output.TabWord[0] = 'H';
        DisplaySpace(5);
        green();
        PrintWord(output);
        reset();
        DisplaySpace(5);
    }
    else
    {
        output.Length = value / 10 + 1;
        for (int i = output.Length - 1; i >= 0; i--)
        {
            output.TabWord[i] = (value % 10) + '0';
            value /= 10;
        }
        DisplaySpace(5);
        green();
        PrintWord(output);
        reset();
        DisplaySpace(6 - output.Length);
    }
}

void DisplaySpace(int value)
{
    for (int i = 0; i < value; i++)
    {
        printf(" ");
    }
}

void DisplayMap(ListSnake S, Point fruit, Point meteor, ListObstacle obstacle)
{
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X\n");
    for (int i = 0; i < 5; i++)
    {
        printf("X           :           :           :           :           X\n");
        DisplayRow(S, fruit, meteor, obstacle, i);
        printf("X           :           :           :           :           X\n");
        if (i < 4)
        {
            printf("X-----------:-----------:-----------:-----------:-----------X\n");
        }
    }
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X\n");
}

int RunSnakeOnMeteor()
{
    clear();
    ListSnake S;
    Point fruit;
    Point meteor;
    ListObstacle obstacle;
    Point temp;
    boolean isGameOver = false;
    int score;
    srand(time(NULL));
    InitialSnake(&S);
    InitialObstacle(S, &obstacle);
    InitialFood(S, &fruit, obstacle);
    while (!isGameOver)
    {
        printf("=============================================================\n");
        printf("   ________   _____  ___        __       __   ___    _______  \n");
        printf("  /'       )(\\'   \\|'  \\      /''\\     |/'| /  ')  /'     '| \n");
        printf(" (:   \\___/ |.\\\\   \\    |    /    \\    (: |/   /  (: ______) \n");
        printf("  \\___  \\   |: \\.   \\\\  |   /' /\\  \\   |    __/    \\/    |   \n");
        printf("   __/   \\  |.  \\    \\. |  //  __'  \\  (// _  \\    // ___)_  \n");
        printf("  /' \\   :) |    \\    \\ | /   /  \\\\  \\ |: | \\  \\  (:      '| \n");
        printf(" (_______/   \\___|\\____\\)(___/    \\___)(__|  \\__)  \\_______) \n");
        printf("=============================================================\n");
        printf("        H = Head, O = Fruit, M = Meteor, X = Obstacle        \n");
        printf("=============================================================\n");
        DisplayMap(S, fruit, meteor, obstacle);
        if (IsHit(&S, meteor))
        {
            HitMeteor(&S, meteor, &isGameOver, &score);
            printf("=============================================================\n");
            red();
            printf(".___  ___.  _______ .___________. _______   ______   .______      \n");
            printf("|   \\/   | |   ____||           ||   ____| /  __  \\  |   _  \\     \n");
            printf("|  \\  /  | |  |__   `---|  |----`|  |__   |  |  |  | |  |_)  |    \n");
            printf("|  |\\/|  | |   __|      |  |     |   __|  |  |  |  | |      /     \n");
            printf("|  |  |  | |  |____     |  |     |  |____ |  `--'  | |  |\\  \\_\n");
            printf("|__|  |__| |_______|    |__|     |_______| \\______/  | _| `.__|\n");
            printf("                                                                  \n");
            reset();
            printf("=============================================================\n");
            sleep(2);
            clear();
            printf("=============================================================\n");
            printf("   ________   _____  ___        __       __   ___    _______  \n");
            printf("  /'       )(\\'   \\|'  \\      /''\\     |/'| /  ')  /'     '| \n");
            printf(" (:   \\___/ |.\\\\   \\    |    /    \\    (: |/   /  (: ______) \n");
            printf("  \\___  \\   |: \\.   \\\\  |   /' /\\  \\   |    __/    \\/    |   \n");
            printf("   __/   \\  |.  \\    \\. |  //  __'  \\  (// _  \\    // ___)_  \n");
            printf("  /' \\   :) |    \\    \\ | /   /  \\\\  \\ |: | \\  \\  (:      '| \n");
            printf(" (_______/   \\___|\\____\\)(___/    \\___)(__|  \\__)  \\_______) \n");
            printf("=============================================================\n");
            printf("         H = Head, O = Fruit, M = Meteor, X = Obstacle       \n");
            printf("=============================================================\n");
            DisplayMap(S, fruit, meteor, obstacle);
            if (isGameOver) {
                printf("        !!! Anda kalah karena kepala terkena meteor !!!      \n");
            }
        }
        if (!isGameOver)
        {
            isGameOver = IsGameOver(S, obstacle, &score);
        }
        temp = InfoPos(Tail(S));
        if (!isGameOver)
        {
            ReadInput(&S, meteor, obstacle, &score);
            EatFruit(&S, &fruit, temp, obstacle);
            currentWord.Length = 0;
            currentWord.TabWord[0] = '\0';
        }
        InitialMeteor(&meteor, fruit, obstacle);
        if (!isGameOver) {
            sleep(1);
            clear();
        }
    }
    printf(" ___ __                                                __ ___ \n");
    printf("|  _/ /                                                \\ \\_  |\n");
    printf("| || |   __ _  __ _ _ __ ___   ___  _____   _____ _ __  | || |\n");
    printf("| / /   / _` |/ _` | '_ ` _ \\ / _ \\/ _ \\ \\ / / _ \\ '__|  \\ \\ |\n");
    printf("| \\ \\  | (_| | (_| | | | | | |  __/ (_) \\ V /  __/ |     / / |\n");
    printf("| || |  \\__, |\\__,_|_| |_| |_|\\___|\\___/ \\_/ \\___|_|    | || |\n");
    printf("|___\\_\\  __/ |                                         /_/___|\n");
    printf("        |___/                                                \n");
    printf("==============================================================\n");
    printf("                      SKOR KAMU : %d\n", score);
    printf("==============================================================\n");
    return score;
}