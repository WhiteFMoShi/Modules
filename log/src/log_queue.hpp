#pragma once

#include <mutex>
#include <queue>

#include "log_entry.hpp"

// 线程安全队列
class LogQueue {
public:
    bool empty();
    void push(LogEntry entry);
    int size();
    LogEntry front_and_pop();

private:
    std::queue<LogEntry> q_;
    std::mutex push_mtx_; // 用于入队操作的互斥锁
    std::mutex pop_mtx_;  // 用于出队操作的互斥锁
};