#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv){
    SPDLOG_INFO("Start program");

    // glfw 라이브러리 초기화, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Initialize glfw");

    if (!glfwInit()) {
        const char* description = nullptr;

        glfwGetError(&description);
        
        SPDLOG_ERROR("failed to initialize glfw: {}", description);

        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw 윈도우 생성, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Create glfw window");

    auto window = glfwCreateWindow(
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        WINDOW_NAME,
        nullptr,
        nullptr
    );

    glfwMakeContextCurrent(window);

    if (!window) {
        SPDLOG_ERROR("failed to create glfw window");

        glfwTerminate();

        return -1;
    }

    // glad를 활용한 OpenGL 함수 로딩
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        SPDLOG_ERROR("failed to initialize glad");
    
        glfwTerminate();
    
        return -1;
    }

    const GLubyte* glVersion = glGetString(GL_VERSION);

    SPDLOG_INFO("OpenGL context version: {}", std::string(reinterpret_cast<const char*>(glVersion)));

    // glfw 루프 실행, 윈도우 close 버튼을 누르면 정상 종료
    SPDLOG_INFO("Start main loop");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}