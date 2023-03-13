#ifndef STATEXT_STATE_H
#define STATEXT_STATE_H

#include <memory>
namespace statext {

class Context;

class State {
public:
    State() noexcept;
    virtual ~State() noexcept = default;

    virtual void run() noexcept = 0;

    void set_context(Context* context) noexcept;

protected:
    Context* m_context;
};

} // namespace statext

#endif
