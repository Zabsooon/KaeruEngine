#pragma once
#include "Core.h"

namespace Kaeru {

    class KAERU_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();
}
