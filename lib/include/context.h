#ifndef STATEXT_SUPERTYPER_H
#define STATEXT_SUPERTYPER_H

#include "state.h"

#include <memory>

namespace statext {

class Context {
public:
    Context(std::shared_ptr<State> initial_state) noexcept;
    ~Context() noexcept = default;

    void update() noexcept;

    void change_state(std::shared_ptr<State> new_state) noexcept;

    bool has_valid_state() const noexcept;

private:
    std::shared_ptr<State> m_state;
};

} // namespace statext

#endif
