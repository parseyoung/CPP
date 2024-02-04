#pragma once
#include <iostream>
#include <chrono>

class Timer {
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> start_time;

public:
    Timer() : start_time(clock_t::now()) {}

    // 타이머 시작
    void start() {
        start_time = clock_t::now();
    }

    // 경과 시간을 반환 (초 단위)
    double elapsed() {
        auto end_time = clock_t::now();
        auto elapsed_seconds = std::chrono::duration_cast<second_t>(end_time - start_time);
        return elapsed_seconds.count();
    }
};
