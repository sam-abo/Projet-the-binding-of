#include "Time.hh"

Time::Time(float initialTimeSeconds) : initialTime(initialTimeSeconds), remainingTime(initialTime), isRunning(false) {}

void Time::start() {
    clock.restart();
    isRunning = true;
}

void Time::update() {
    if (isRunning) {
        float elapsedSeconds = clock.getElapsedTime().asSeconds();
        remainingTime = std::max(0.0f, initialTime - elapsedSeconds);
    }
}

bool Time::isTimeUp() const {
    return remainingTime <= 0.0f;
}

float Time::getRemainingTime() const {
    return remainingTime;
}

void Time::reset() {
    remainingTime = initialTime;
    isRunning = false;
}
/* full implementation and dependencies .....*/