#pragma once

namespace dsl {

// Elemento com prioridade e ordem de chegada (para desempate estável)
template <typename T>
class PrioritizedElement {
private:
    T value;
    unsigned int priority;  // menor número = maior prioridade
    std::size_t arrivalOrder;

public:
    PrioritizedElement() : value(), priority(0), arrivalOrder(0) {}
    PrioritizedElement(const T& v, unsigned int p, std::size_t order)
        : value(v), priority(p), arrivalOrder(order) {}

    const T& getValue() const { return value; }
    unsigned int getPriority() const { return priority; }
    std::size_t getArrivalOrder() const { return arrivalOrder; }
};

} // namespace dsl
