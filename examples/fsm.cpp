#include "context.h"
#include "state.h"

#include <cstdint>
#include <iostream>

struct Data {
    std::int32_t score{0};
};

class Exit_state : public statext::State {
public:
    Exit_state() noexcept : State{} {}
    virtual ~Exit_state() noexcept = default;

    void run() noexcept
    {
        std::cout << "Exiting\n";
        m_context->change_state(nullptr);
    }
};

class Game_state : public statext::State {
public:
    Game_state(Data data) noexcept : State{}, m_data(data) {}
    virtual ~Game_state() noexcept = default;

    void run() noexcept
    {
        std::cout << "Game_state...\n";
        std::cout << " -- Score: " << m_data.score << ".\n";
        m_context->change_state(std::make_shared<Exit_state>());
    }

private:
    Data m_data;
};

class Menu_state : public statext::State {
public:
    Menu_state() noexcept : State{} {}
    virtual ~Menu_state() noexcept = default;

    void run() noexcept
    {
        std::cout << "Hello from the Menu_state!\n";
        Data d{};
        d.score++;
        m_context->change_state(std::make_shared<Game_state>(d));
    }
};

std::int32_t main()
{
    statext::Context ctx{std::make_shared<Menu_state>()};

    ctx.update();

    return 0;
}
