#include "context.h"

namespace statext {

Context::Context(std::shared_ptr<State> initial_state) noexcept : m_state{nullptr}
{
    change_state(initial_state);
}

void Context::update() noexcept
{
    while (m_state) {
        m_state->run();
    }
}

void Context::change_state(std::shared_ptr<State> new_state) noexcept
{
    if (m_state) {
        m_state.reset();
    }
    m_state = new_state;

    if (m_state) {
        m_state->set_context(this);
    }
}

bool Context::has_valid_state() const noexcept{
    return (m_state != nullptr);
}

} // namespace statext
