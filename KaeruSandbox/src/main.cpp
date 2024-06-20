#include "Kaeru/Application.h"
#include <Kaeru.h>

class Sandbox : public Kaeru::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

Kaeru::Application* Kaeru::CreateApplication()
{
    return new Sandbox();
}
