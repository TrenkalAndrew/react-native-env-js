#pragma once

#include <fbjni/fbjni.h>
#include <jni.h>
#include <string>

namespace envjs {

    using namespace facebook;
    using namespace jni;

    struct JEnvJs : public JavaClass<JEnvJs> {
        static constexpr auto kJavaDescriptor = "Lcom/reactnativeenvjs/EnvJs;";

    public:
        std::string static getEnvironmentVariable(std::string const& environmentVariableName);
    };

}
