#ifndef QUEUE_EMPTY_HPP
#define QUEUE_EMPTY_HPP

#include <stdexcept>
#include <string>

class QueueEmpty : public std::runtime_error {
public:
    explicit QueueEmpty(const std::string& message) : std::runtime_error(message) {}
};

#endif
