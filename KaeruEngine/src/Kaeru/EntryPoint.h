#pragma once

#include "Kaeru/Application.h"

extern Kaeru::Application* Kaeru::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Kaeru::CreateApplication();
    app->Run();
    delete app;
}
