#include "LogQueue.h"
#include <mutex>

namespace Kaeru::Logging {

    template<typename T>
    LogQueue<T>::LogQueue() {

    }

    template<typename T>
    LogQueue<T>::~LogQueue() {

    }

    template<typename T>
    void LogQueue<T>::push(T value) {
        std::lock_guard<std::mutex> lock(m_Mtx);
        m_Queue.push(value);
    }

    template<typename T>
    T LogQueue<T>::pop() {
        std::unique_lock<std::mutex> lock(m_Mtx);
        m_Cv.wait(lock, [this]() {
            !this->Empty() || m_Done;
                });
        T value = m_Queue.front();
        m_Queue.pop();
        return value;
    }

    template<typename T>
    bool LogQueue<T>::empty() {
        std::lock_guard<std::mutex> lock(m_Mtx);
        return m_Queue.empty();
    }

    template<typename T>
    void LogQueue<T>::shutdown() {
        std::lock_guard<std::mutex> lock(m_Mtx);
        m_Done = true;
    }
}
    class LogQueue;
