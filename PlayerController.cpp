#include "PlayerController.h"
#include <conio.h>
#include <chrono>
#include <thread>
#include <iostream>

PlayerController::PlayerController(Player& p, int x, int y) : player(p) {
    if (y >= 0 && y < Y_SIZE) {
        this->y = y;
    }
    else {
        this->y = 0;
    }
    if (x >= 0 && x < X_SIZE) {
        this->x = x;
    }
    else {
        this->x = 0;
    }
}

void PlayerController::run() {
    char key;

    auto lastTime = std::chrono::steady_clock::now(); ///ЗАМЕЧАНИЕ!!! Добавил для ограничения скорости перемещения - арг. не засчитан
    const int refreshRate = REFRESH_RATE;

    while (true) {
        auto startTime = std::chrono::steady_clock::now();

        key = getKeyPress();
        Keys Key = convertToKeys(key);
        updatePlayerPosition(Key);

        auto endTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

        if (elapsedTime < refreshRate) {
            std::this_thread::sleep_for(std::chrono::milliseconds(refreshRate - elapsedTime));
        }
    }
}

int PlayerController::getX() {
    return x;
}

int PlayerController::getY() {
    return y;
}

Keys PlayerController::convertToKeys(int key) {
    switch (key) {
    case 24:
        return Keys::Up;
    case 25:
        return Keys::Down;
    case 26:
        return Keys::Left;
    case 27:
        return Keys::Right;
    case 81:
        return Keys::Quit;
    default:
        return Keys::Default;
    }
}

char PlayerController::getKeyPress() {
    if (_kbhit()) {
        return _getch();
    }
    return '\0';
}

void PlayerController::updatePlayerPosition(Keys key) { ///ЗАМЕЧАНИЕ (В другой класс) - черновой вариант, не планировал показывать, т.к задание из другой л/р
    if (key == Keys::Up && y >= 0) {
        y--;
    }
    else if (key == Keys::Down && y < Y_SIZE) {
        y++;
    }
    else if (key == Keys::Left && x >= 0) {
        x--;
    }
    else if (key == Keys::Right && x < X_SIZE) {
        x++;
    }
}

void PlayerController::hotKeys(Keys key) {
    if (key == Keys::Quit) {
        std::cout << "Program completed.\n" << std::endl;
        //////////////////////
    }
}