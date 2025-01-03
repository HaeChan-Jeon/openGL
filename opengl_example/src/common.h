// 프로젝트가 공통적으로 이용할 기능들을 정의하는 파일
// common.h를 include를 할 때, ifndef, endif의 역할은 가운데 코드를 가져다 붙이는 역할을 수행함
#ifndef __COMMON_H__
#define __COMMON_H__

#include <memory>
#include <string>
#include <optional>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <spdlog/spdlog.h>

std::optional<std::string> LoadTextFile(const std::string& filename);

#endif // __COMMON_H__