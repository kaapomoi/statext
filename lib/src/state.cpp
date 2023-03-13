#include "state.h"

#include "context.h"

namespace statext {

State::State() noexcept {}

void State::set_context(Context* context) noexcept
{
    m_context = context;
}

} // namespace statext
