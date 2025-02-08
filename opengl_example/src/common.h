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
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define CLASS_PTR(klassName) \
class klassName; \
using klassName ## UPtr = std::unique_ptr<klassName>; \
using klassName ## Ptr = std::shared_ptr<klassName>; \
using klassName ## WPtr = std::weak_ptr<klassName>;

// CLASS_PTR(Shader)
// class Shader;
// using ShaderUPtr = std::unique_ptr<Shader>;
// using ShaderPtr = std::shared_ptr<Shader>;
// using ShaderWPtr = std::weak_ptr<Shader>;

std::optional<std::string> LoadTextFile(const std::string& filename);

glm::vec3 GetAttenuationCoeff(float distance);

#endif // __COMMON_H__