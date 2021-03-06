#ifndef UTILS_WINDOW_H_INCLUDED
#define UTILS_WINDOW_H_INCLUDED

#include <Utils/Clock.h>
#include <Utils/Exception.h>
#include <Utils/GL+/Context.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

#include <list>
#include <string>
#include <vector>
#include <functional>

namespace Util {
    
    class Window {
        public:
            Window();
            Window(unsigned int width, unsigned int height, const std::string& title);
            Window(const glm::uvec2& size, const std::string& title);
            virtual ~Window();

            operator GLFWwindow*();
            
            bool create() throw(Util::Exception::FatalError);
            virtual void update();
            void destroy();
            
            void setSize(unsigned int width, unsigned int height);
            void setSize(const glm::uvec2& size);
            void setPosition(int posX, int posY);
            void setPosition(const glm::ivec2& position);
            void setTitle(const std::string& title);
            void appendTitle(const std::string& text);

            void setDisplayingFPS(bool flag);
            void setCountingFPS(bool flag);
            void setFPSRefreshRate(double refreshRate);

            void setFPSCountCallback(const std::function<void(int)>& function);
            void setDestroyCallback(const std::function<void()>& function);
            
            const bool isDisplayingFPS() const;
            const bool isCountingFPS() const;
            const double getFPSRefreshRate() const;
            const int getFPS() const;
            const unsigned int getWidth() const;
            const unsigned int getHeight() const;
            const glm::uvec2& getSize() const;
            const glm::ivec2& getPosition() const;
            const std::string& getTitle() const;

            const bool isCreated() const;
            const bool shouldClose() const;
            const double getFrameTime() const;
            GLFWwindow* getHandle();
            GL::Context& getContext();

            static void setHint(int option, int value);
            static void setHints(const std::list<std::pair<int, int>>& hints);
            static void setHints(const std::vector<std::pair<int, int>>& hints);
            static void setDefaultHints();

            static void initializeGLFW() throw(Util::Exception::FatalError);
            static void initializeGLEW() throw(Util::Exception::FatalError);

        protected:
            void setFPSCount(int fpsCount);
            void setContext();
            
            int _fpsCount;
            unsigned int _framesCount;
            bool _isDisplayingFPS;
            bool _isCountingFPS;
            double _lastFrame;
            double _thisFrame;
            double _fpsTime;
            double _fpsRefreshRate;
            double _frameTime;
            GLFWwindow* _handle;
            std::string _title;
            glm::uvec2 _windowSize;
            glm::ivec2 _windowPosition;
            GL::Context _context;
            std::function<void(int)> _fpsCountCallback;
            std::function<void()> _destroyCallback;
            Clock _fpsClock;

            static bool _hintsSet;
    };

}

#endif