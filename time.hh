#pragma once

#include <SFML/System/Clock.hpp>

class Time {
public:
    Time(float initialTimeSeconds);

    // Start the timer
    void start();

    // Update the timer (call this in your game loop)
    void update();

    // Check if time is up
    bool isTimeUp() const;

    // Get the remaining time in seconds
    float getRemainingTime() const;

    // Reset the timer to the initial time
    void reset();

private:
    sf::Clock clock;         // SFML clock for time tracking
    float initialTime;       // Initial time in seconds
    float remainingTime;     // Remaining time in seconds
    bool isRunning;          // Flag to track if the timer is running
};

