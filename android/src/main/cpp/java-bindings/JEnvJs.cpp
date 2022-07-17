#include "JEnvJs.h"
#include <fbjni/fbjni.h>

#include <string>
#include <android/log.h>


namespace envjs {
    using namespace facebook::jni;

    std::string JEnvJs::getEnvironmentVariable(std::string const& environmentVariableName) {
        static const auto cls = javaClassStatic();

        const auto getEnvironmentVariable = cls->getStaticMethod<std::string(std::string)>("getEnvironmentVariable");

        return getEnvironmentVariable(cls, environmentVariableName)->toStdString();
    }
}
